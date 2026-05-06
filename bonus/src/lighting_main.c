/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:57:29 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:58:14 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	pow64_dbl(double x)
{
	double	res;

	res = x * x;
	res *= res;
	res *= res;
	res *= res;
	res *= res;
	res *= res;
	return (res);
}


t_cord	vec3_2pvec_norm(t_cord p1, t_cord p2)
{
	t_cord	res;

	initialise_t_cord(&res);
	res = vec3_sub(p1, p2);
	res = vec3_normalise(res);
	return (res);
}

double	calc_pixel_l_sdwvslit(t_box box, t_obj *obj, t_ligt *ligt)
{
	t_ray	shadow;
	t_cord	p;
	t_cord	sur_vec;
	t_cord	s2l_vec;
	double	factor;

	p = box.p;
	sur_vec = box.sur_vec;
	s2l_vec = box.s2l_vec;
	factor = box.ln_dotp;
	if (factor < 0)
		return (factor);
	initialise_t_ray(&shadow);
	shadow.cord = vec3_add(p, vec3_mul(sur_vec, EPSILON));
	shadow.ori = s2l_vec;
	calc_pixel_frt(&shadow, obj);
	if (shadow.t <= EPSILON
		|| shadow.t * shadow.t > vec3_len_sq(p, ligt->cord))
		return (factor);
	return (0.0);
}

// double	calc_pixel_l_sdwvslit(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
// {
// 	t_ray	shadow;
// 	t_cord	p;
// 	t_cord	sur_vec;
// 	t_cord	s2l_vec;
// 	double	factor;

// 	p = calc_point(ray);
// 	sur_vec = calc_surface_normal(p, cur);
// 	s2l_vec = vec3_2pvec_norm(data->ligt.cord, p);
// 	factor = vec3_dot(sur_vec, s2l_vec);
// 	if (factor < 0)
// 		return (factor);
// 	initialise_t_ray(&shadow);
// 	shadow.cord = vec3_add(p, vec3_mul(sur_vec, EPSILON));
// 	shadow.ori = s2l_vec;
// 	calc_pixel_frt(&shadow, obj);
// 	if (shadow.t <= EPSILON
// 		|| shadow.t * shadow.t > vec3_len_sq(p, data->ligt.cord))
// 	{
// 		factor += calc_pixel_l_sdwvslit_phong(s2l_vec, sur_vec,
// 					vec3_2pvec_norm(data->cam.cord, p), factor);
// 		return (factor);
// 	}
// 	return (0.0);
// }

// t_rgb	calc_pixel_l_diffused(double factor, t_obj *cur, t_data *data)
// {
// 	t_rgb	light;

// 	initialise_t_rgb(&light);
// 	light = rgb_amp_cap(data->ligt.rgb, data->ligt.bright);
// 	light = rgb_amp_cap(light, factor);
// 	light = rgb_mul(cur->rgb, light, 255);
// 	return (light);
// }
#define	SPECULAR_COEFFICIENT 1.5

// reflection vec: $$\vec{R} = 2(\vec{N} \cdot \vec{L})\vec{N} - \vec{L}$$
t_rgb	calc_pixel_l_specular(t_box box, t_ligt *ligt, t_data *data)
{
	t_cord	rfl_vec;
	t_cord	s2c_vec;
	t_rgb	light;
	double	res;

	initialise_t_rgb(&light);
	light = rgb_amp_cap(ligt->rgb, ligt->bright);
	s2c_vec = vec3_2pvec_norm(data->cam.cord, box.p);
	initialise_t_cord(&rfl_vec);
	rfl_vec = vec3_mul(box.sur_vec, box.ln_dotp * 2.0);
	rfl_vec = vec3_sub(rfl_vec, box.s2l_vec);
	res = vec3_dot(s2c_vec, rfl_vec);
	res = ft_max_dbl(0, res);
	res = pow64_dbl(res);
	res *= SPECULAR_COEFFICIENT;
	light = rgb_amp_cap(light, res);
	return (light);
}

t_rgb	cre_t_rgb(int r, int g, int b)
{
	t_rgb	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_cord	cre_t_cord(double x, double y, double z)
{
	t_cord	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

#define CHKR_SCALE 0.5

void	calc_chkr_uv_pl(t_calc *calc, t_cord p, t_obj *cur)
{
	t_cord	vec_caterpillar_u;
	t_cord	vec_caterpillar_v;
	t_cord	up;
	t_cord	local_p;

	if (cur->ori.y == 1 || cur->ori.y == -1)
	{
		calc->u = (p.x - cur->cord.x);
		calc->v = (p.z - cur->cord.z);
	}
	else
	{
		up = cre_t_cord(0.0, 1.0, 0.0);
		vec_caterpillar_u = vec3_cross(cur->ori, up);
		vec_caterpillar_u = vec3_normalise(vec_caterpillar_u);
		vec_caterpillar_v = vec3_cross(vec_caterpillar_u, cur->ori);
		local_p = vec3_sub(p, cur->cord);
		calc->u = vec3_dot(vec_caterpillar_u, local_p);
		calc->v = vec3_dot(vec_caterpillar_v, local_p);
	}
	calc->u = calc->u;
	calc->v = calc->v;
}

double	bound_limit_dbl(double val, double min, double max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	else
		return (val);
}

void	calc_chkr_uv_sp(t_calc *calc, t_cord p, t_obj *cur)
{
	double	longtitude;
	double	latitude;
	double	r;
	t_cord	local_p;
	double	val;

	local_p = vec3_sub(p, cur->cord);
	if (cur->type == SP)
		r = cur->dia / 2;
	else if (cur->type == EL)
	{
		local_p = vec3_div_vec3(local_p, vec3_div(cur->dia_xyz, 2.0));
		r = 1.0;
	}
	longtitude = atan2(local_p.x, local_p.z);
	longtitude = (longtitude + RT_PI) / (2.0 * RT_PI);
	val = local_p.y / r;
	val = bound_limit_dbl(val, -1.0, 1.0);
	latitude = asin(val);
	latitude = (latitude + RT_PI_HALF) / RT_PI;
	if (cur->type == SP)
	{
		calc->u = longtitude * 2 * r * RT_PI;
		calc->v = latitude * r * RT_PI;
	}
	else if (cur->type == EL)
	{
		calc->u = longtitude * 2 * cur->dia_xyz.x * RT_PI / 2;
		calc->v = latitude * cur->dia_xyz.z * RT_PI / 2;
	}
}

void	calc_chkr_uv_cy(t_calc *calc, t_cord p, t_ray *ray, t_obj *cur)
{
	t_cord	vec_caterpillar_u;
	t_cord	vec_caterpillar_v;
	t_cord	local_p;
	t_cord	up;

	if (ray->lhit == FLAT_TOP || ray->lhit == FLAT_BOT)
		calc_chkr_uv_pl(calc, p, cur);
	else if (ray->lhit == TUBE)
	{
		local_p = vec3_sub(p, cur->cord);
		if (cur->ori.y == 1 || cur->ori.y == -1)
		{
			calc->u = atan2(local_p.x, local_p.z);
			calc->u = (calc->u + RT_PI) / (2.0 * RT_PI);
			calc->u = calc->u * cur->dia * RT_PI;
			calc->v = (p.y - cur->cord.y);
			return ;
		}
		up = cre_t_cord(0.0, 1.0, 0.0);
		vec_caterpillar_u = vec3_normalise(vec3_cross(cur->ori, up));
		vec_caterpillar_v = vec3_cross(cur->ori, vec_caterpillar_u);
		calc->u = atan2(vec3_dot(vec_caterpillar_v, local_p),
						vec3_dot(vec_caterpillar_u, local_p));
		calc->u = (calc->u + RT_PI) / (2.0 * RT_PI);
		// calc->v = vec3_dot(cur->ori, local_p) / cur->higt;
		calc->u = calc->u * cur->dia * RT_PI;
		calc->v = vec3_dot(cur->ori, local_p);
	}
}

void	calc_chkr_uv(t_calc *calc, t_cord p, t_ray *ray, t_obj *cur)
{
	if (cur->type == PL)
	{
		calc_chkr_uv_pl(calc, p, cur);
	}
	else if (cur->type == SP || cur->type == EL)
	{
		calc_chkr_uv_sp(calc, p, cur);
	}
	else if (cur->type == CY)
	{
		calc_chkr_uv_cy(calc, p, ray, cur);
	}
	else
		ft_puterr("calc_ckr_uv: cur->type = unknown shape");
}


t_rgb	calc_chkr(t_ray *ray, t_cord p, t_obj *cur)
{
	t_calc	calc;
	int		sum;

	initialise_t_calc(&calc);
	calc_chkr_uv(&calc, p, ray, cur);
	// sum = (int) (floor(calc.u) + floor(calc.v));
	sum = (int) (floor(calc.u * CHKR_SCALE) + floor (calc.v * CHKR_SCALE));
	if (sum % 2 == 0)
		return (cre_t_rgb(255, 255, 255));
	else
		return (cre_t_rgb(0, 0, 0));
}

void	initialise_t_box(t_box *box)
{
	initialise_t_cord(&box->p);
	initialise_t_cord(&box->sur_vec);
	initialise_t_cord(&box->s2l_vec);
	initialise_t_rgb(&box->s);
	box->ln_dotp = 0;
}

// t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_ligt *ligt, t_data *data)
// {
// 	t_rgb	ambi;
// 	double	factor;
// 	t_box	box;

// 	initialise_t_rgb(&ambi);
// 	if (!ray || !cur || !ligt || !data)
// 		return (ambi);
// 	ambi = rgb_amp_cap(data->ambi.rgb, data->ambi.ratio);
// 	initialise_t_box(&box);
// 	box.p = calc_point(ray);
// 	if (cur->chkr == TRUE)
// 		box.s = calc_chkr(ray, box.p, cur);
// 	else
// 		box.s = cur->rgb;
// 	ambi = rgb_mul(ambi, box.s, 255);
// 	box.sur_vec = calc_surface_normal(box.p, cur, ray);
// 	box.ln_dotp = vec3_dot(box.sur_vec, box.s2l_vec);
// 	box.s2l_vec = vec3_2pvec_norm(ligt->cord, box.p);
	
// 	t_ligt	*cur_ligt = ligt;
// 	while (cur_ligt)
// 	{
// 		factor = calc_pixel_l_sdwvslit(box, data->obj_head, ligt);
// 		if (factor > 0)
// 		{
// 			ambi = rgb_add(ambi, calc_pixel_l_diffused(box.s, factor, ligt));
// 			ambi = rgb_amp_cap(rgb_add(ambi, calc_pixel_l_specular(box, ligt, data)), 1);
// 		}
// 		cur_ligt = cur_ligt->next;
// 	}
// 	return (ambi);
// }

t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_ligt *ligt, t_data *data)
{
	t_rgb	ambi;
	t_box	box;

	initialise_t_rgb(&ambi);
	if (!ray || !cur || !ligt || !data)
		return (ambi);
	ambi = rgb_amp_cap(data->ambi.rgb, data->ambi.ratio);
	initialise_t_box(&box);
	box.p = calc_point(ray);
	if (cur->chkr == TRUE)
		box.s = calc_chkr(ray, box.p, cur);
	else
		box.s = cur->rgb;
	ambi = rgb_mul(ambi, box.s, 255);
	box.sur_vec = calc_surface_normal(box.p, cur, ray);
	
	// ambi = calc_pixel_l_each(ambi, box, ligt, data);
	double	factor;
	t_ligt	*cur_ligt = ligt;
	while (cur_ligt)
	{
		box.s2l_vec = vec3_2pvec_norm(cur_ligt->cord, box.p);
		box.ln_dotp = vec3_dot(box.sur_vec, box.s2l_vec);
		factor = calc_pixel_l_sdwvslit(box, data->obj_head, cur_ligt);
		if (factor > 0)
		{
			ambi = rgb_add(ambi, calc_pixel_l_diffused(box.s, factor, cur_ligt));
			ambi = rgb_amp_cap(rgb_add(ambi, calc_pixel_l_specular(box, cur_ligt, data)), 1);
		}
		cur_ligt = cur_ligt->next;
	}
	return (ambi);
}

int	calc_pixel_a(int y, int x, t_rgb rgb, t_data *data)
{
	int		loc;
	int		n_bytes;

	n_bytes = data->bits_p_pixel / BITS_PER_BYTE;
	loc = y * data->size_line;
	loc = loc + (n_bytes * x);
	*(unsigned int *)(data->addr + loc) = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	return (0);
}

void	free_thrd(t_thrd **top)
{
	t_thrd	*head;
	t_thrd	*cur;

	head = *top;
	while (head)
	{
		cur = head;
		head = head->next;
		ft_sfree((void **)&cur);
	}
	*top = NULL;
}

t_thrd	*cre_t_thrd_new(int id, long nprocs, t_data *data)
{
	t_thrd	*new;
	int		total_len;
	int 	thrd_len;

	new = malloc(sizeof(t_thrd));
	if (!new)
		return (NULL);
	new->created = FALSE;
	new->data = data;
	total_len = HEIGHT * WIDTH;
	thrd_len = total_len / nprocs;
	new->id = id;
	new->next = NULL;
	new->obj = data->obj_head;
	new->starty = id * thrd_len / WIDTH;
	if (id == nprocs - 1)
		new->endy = HEIGHT;
	else
		new->endy = (id * thrd_len + thrd_len) / WIDTH;
	return (new);
}

t_thrd	*cre_t_thrd_next(t_thrd *thrd, int id, long nprocs, t_data *data)
{
	t_thrd	*new;

	new = cre_t_thrd_new(id, nprocs, data);
	if (!new)
		return (NULL);
	if (!thrd)
		return (new);
	thrd->next = new;
	return (new);
}

t_thrd	*cre_thrddata(t_data *data)
{
	long	nprocs;
	long	i;
	t_thrd	*head;
	t_thrd	*curr;

	nprocs = sysconf(_SC_NPROCESSORS_CONF);
	if (nprocs < 1)
		return (ft_puterr("sysconf processor number < 1"), NULL);
	i = 0;
	head = cre_t_thrd_new(i, nprocs, data);
	if (!head)
		return (NULL);
	curr = head;
	i++;
	while (i < nprocs)
	{
		curr = cre_t_thrd_next(curr, i, nprocs, data);
		if (!curr)
			return (ft_puterr("cre_t_thrddata error"), free_thrd(&head), NULL);
		i++;
	}
	return (head);
}

void	*calc_pixel_thrd_run(void *param)
{
	t_obj	*frt;
	t_ray	ray;
	int		y;
	int		x;
	t_thrd	*thrd;

	thrd = (t_thrd *)param;
	thrd->created = TRUE;
	frt = NULL;
	y = thrd->starty;
	while (y < thrd->endy)
	{
		x = 0;
		while (x < WIDTH)
		{
			initialise_t_ray(&ray);
			calc_ray_screen2obj(&ray, x, y, thrd->data);
			frt = calc_pixel_frt(&ray, thrd->obj);
			calc_pixel_a(y, x, calc_pixel_l(&ray, frt, thrd->data->ligt, thrd->data),
				thrd->data);
			x++;
		}
		y++;
	}
	return (NULL);
}

void	calc_pixel_thrd_join(t_thrd *head)
{
	t_thrd	*thrd;

	thrd = head;
	while (thrd)
	{
		if (thrd->created == FALSE)
			break ;
		pthread_join(thrd->thrd, NULL);
		thrd = thrd->next;
	}
}

int	calc_pixel(t_obj **obj, t_data **data)
{
	t_thrd	*head;
	t_thrd	*thrd;

	(void) obj;
	head = cre_thrddata(*data);
	if (head == NULL)
		return (-1);
	thrd = head;
	while (thrd)
	{
		if (pthread_create(&thrd->thrd, NULL, calc_pixel_thrd_run, (void *)thrd))
			return (ft_puterr("calc_pixel pthread creation failed thread "),
						ft_putnbr(thrd->id), calc_pixel_thrd_join(head),
							free_thrd(&head), 1);
		thrd->created = TRUE;
		thrd = thrd->next;
	}
	calc_pixel_thrd_join(head);
	free_thrd(&head);
	return (0);
}

// int	calc_pixel(t_obj **obj, t_data **data)
// {
// 	t_obj	*frt;
// 	t_ray	ray;
// 	int		x;
// 	int		y;

// 	frt = NULL;
// 	y = 0;
// 	while (y < HEIGHT)
// 	{
// 		x = 0;
// 		while (x < WIDTH)
// 		{
// 			initialise_t_ray(&ray);
// 			calc_ray_screen2obj(&ray, x, y, *data);
// 			frt = calc_pixel_frt(&ray, *obj);
// 			if (calc_pixel_a(y, x, calc_pixel_l(&ray, frt, *obj, *data), *data))
// 				return (1);
// 			x++;
// 		}
// 		y++;
// 	}
// 	return (0);
// }

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

double	calc_pixel_l_sdwvslit(t_box box, t_obj *obj, t_data *data)
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
		|| shadow.t * shadow.t > vec3_len_sq(p, data->ligt.cord))
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
// 	light = rgb_amp_capped(data->ligt.rgb, data->ligt.bright);
// 	light = rgb_amp_capped(light, factor);
// 	light = rgb_mul(cur->rgb, light, 255);
// 	return (light);
// }
#define	SPECULAR_COEFFICIENT 1.5

// reflection vec: $$\vec{R} = 2(\vec{N} \cdot \vec{L})\vec{N} - \vec{L}$$
t_rgb	calc_pixel_l_specular(t_box box, t_data *data)
{
	t_cord	rfl_vec;
	t_cord	s2c_vec;
	t_rgb	light;
	double	res;

	initialise_t_rgb(&light);
	light = rgb_amp_capped(data->ligt.rgb, data->ligt.bright);
	s2c_vec = vec3_2pvec_norm(data->cam.cord, box.p);
	initialise_t_cord(&rfl_vec);
	rfl_vec = vec3_mul(box.sur_vec, box.ln_dotp * 2.0);
	rfl_vec = vec3_sub(rfl_vec, box.s2l_vec);
	res = vec3_dot(s2c_vec, rfl_vec);
	res = ft_max_dbl(0, res);
	res = pow64_dbl(res);
	res *= SPECULAR_COEFFICIENT;
	light = rgb_amp_capped(light, res);
	return (light);
}

t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
{
	t_rgb	ambi;
	double	factor;
	t_box	box;

	initialise_t_rgb(&ambi);
	if (!ray || !cur || !obj || !data)
		return (ambi);
	ambi = rgb_amp_capped(data->ambi.rgb, data->ambi.ratio);
	ambi = rgb_mul(ambi, cur->rgb, 255);
	box.p = calc_point(ray);
	box.sur_vec = calc_surface_normal(box.p, cur, ray);
	box.s2l_vec = vec3_2pvec_norm(data->ligt.cord, box.p);
	box.ln_dotp = vec3_dot(box.sur_vec, box.s2l_vec);
	factor = calc_pixel_l_sdwvslit(box, obj, data);
	if (factor > 0)
	{
		ambi = rgb_add(ambi, calc_pixel_l_diffused(factor, cur, data));
		ambi = rgb_add(ambi, calc_pixel_l_specular(box, data));
		ambi = rgb_amp_capped(ambi, 1);
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
			calc_pixel_a(y, x, calc_pixel_l(&ray, frt, thrd->obj, thrd->data),
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

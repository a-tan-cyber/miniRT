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

// reflection vec: $$\vec{R} = 2(\vec{N} \cdot \vec{L})\vec{N} - \vec{L}$$
double	calc_pixel_l_sdwvslit_phong(t_cord s2l_vec, t_cord sur_vec,
			t_cord s2c_vec, double factor)
{
	t_cord	rfl_vec;
	double	res;

	initialise_t_cord(&rfl_vec);
	rfl_vec = vec3_mul(sur_vec, factor * 2.0);
	rfl_vec = vec3_sub(rfl_vec, s2l_vec);
	res = vec3_dot(s2c_vec, rfl_vec);
	res = max_dbl(0, res);
	res = pow64_dbl(res);
	return (res);
}

t_cord	vec3_p2vec_norm(t_cord p1, t_cord p2)
{
	t_cord	res;

	initialise_t_cord(&res);
	res = vec3_sub(p1, p2);
	res = vec3_normalise(res);
	return (res);
}

double	calc_pixel_l_sdwvslit(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
{
	t_ray	shadow;
	t_cord	p;
	t_cord	sur_vec;
	t_cord	s2l_vec;
	double	factor;

	p = calc_point(ray);
	sur_vec = calc_surface_normal(p, cur);
	s2l_vec = vec3_p2vec_norm(data->ligt.cord, p);
	factor = vec3_dot(sur_vec, s2l_vec);
	if (factor < 0)
		return (factor);
	initialise_t_ray(&shadow);
	shadow.cord = vec3_add(p, vec3_mul(sur_vec, EPSILON));
	shadow.ori = s2l_vec;
	calc_pixel_frt(&shadow, obj);
	if (shadow.t <= EPSILON
		|| shadow.t * shadow.t > vec3_len_sq(p, data->ligt.cord))
	{
		factor += calc_pixel_l_sdwvslit_phong(s2l_vec, sur_vec,
					vec3_p2vec_norm(data->cam.cord, p), factor);
		return (factor);
	}
	return (0.0);
}

t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
{
	t_rgb	ambi;
	double	factor;

	initialise_t_rgb(&ambi);
	if (!ray || !cur || !obj || !data)
		return (ambi);
	ambi = rgb_amp_capped(data->ambi.rgb, data->ambi.ratio);
	ambi = rgb_mul(ambi, cur->rgb, 255);
	factor = calc_pixel_l_sdwvslit(ray, cur, obj, data);
	if (factor > 0)
	{
		ambi = rgb_add(ambi, calc_pixel_l_diffused(factor, cur, data));
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

int	task_distributer()
{
	long	nprocs = sysconf(_SC_NPROCESSORS_CONF);
	if (nprocs < 1)
		return (ft_puterr("sysconf processor number < 1."), 1);
	
}

#include <pthread.h>

void	calc_pixel_thrd_run(thrd)
{

}

void	calc_pixel_thrd_join(t_data_thrd *head)
{
	t_data_thrd	*thrd;

	thrd = head;
	while (thrd)
	{
		if (thrd->created == FALSE)
			break ;
		pthread_join(thrd->thrd, NULL);
		thrd = thrd->next;
	}
}

// free_thrddata(&head)

// thrd->created
// thrd->thrd
// thrd->id
// thrd->start
// thrd->end
// thrd->next

int	calc_pixel(t_obj **obj, t_data **data)
{
	t_data_thrd	*head;
	t_data_thrd	*thrd;

	head = cre_thrddata(data);
	thrd = head;
	while (thrd)
	{
		if (pthread_create(&thrd->thrd, NULL, calc_pixel_thrd_run, (void *)thrd))
			return (ft_puterr("calc_pixel pthread creation failed thread "),
						ft_putnbr(thrd->id), calc_pixel_thrd_join(head),
							free_thrddata(&head), 1);
		thrd->created = TRUE;
		thrd = thrd->next;
	}
	calc_pixel_thrd_join(head);
	free_thrddata(&head);
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

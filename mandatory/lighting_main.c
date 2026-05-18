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

double	calc_pixel_l_sdwvslit(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
{
	t_ray	shadow;
	t_cord	p;
	t_cord	sur_vec;
	t_cord	s2l_vec;
	double	factor;

	p = calc_point(ray);
	sur_vec = calc_surface_normal(p, cur);
	s2l_vec = vec3_sub(data->ligt.cord, p);
	s2l_vec = vec3_normalise(s2l_vec);
	factor = vec3_dot(sur_vec, s2l_vec);
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
	char	rgb_str[RGB_BUFFER];
	int		n_bytes;

	n_bytes = data->bits_p_pixel / BITS_PER_BYTE;
	loc = y * data->size_line;
	loc = loc + (n_bytes * x);
	ft_memset(rgb_str, 0, RGB_BUFFER);
	if (conv_rgb2str(rgb_str, rgb, data))
		return (ft_puterr("calc_pixel_a rgb_str is NULL"), 1);
	ft_memcpy(data->addr + loc, rgb_str, n_bytes);
	return (0);
}

int	calc_pixel(t_obj **obj, t_data **data)
{
	t_obj	*frt;
	t_ray	ray;
	int		x;
	int		y;

	frt = NULL;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			initialise_t_ray(&ray);
			calc_ray_screen2obj(&ray, x, y, *data);
			frt = calc_pixel_frt(&ray, *obj);
			if (calc_pixel_a(y, x, calc_pixel_l(&ray, frt, *obj, *data), *data))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

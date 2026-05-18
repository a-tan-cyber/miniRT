/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_specular.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:10:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:10:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define SPECULAR_COEFFICIENT 1.5

double	calc_pixel_l_sdwvslit(t_box box, t_obj *obj, t_ligt *ligt)
{
	t_ray	shadow;
	t_cord	p;
	t_cord	s2l_vec;
	double	factor;

	p = box.p;
	s2l_vec = box.s2l_vec;
	factor = box.ln_dotp;
	if (factor < 0)
		return (factor);
	initialise_t_ray(&shadow);
	shadow.cord = vec3_add(p, vec3_mul(box.sur_vec, EPSILON));
	shadow.ori = s2l_vec;
	calc_pixel_frt(&shadow, obj);
	if (shadow.t <= EPSILON
		|| shadow.t * shadow.t > vec3_len_sq(p, ligt->cord))
		return (factor);
	return (0.0);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_bump_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:58:52 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:59:03 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

#define BUMP_EPS 0.0006
#define BUMP_STRENGTH 0.05
#define SINE_BUMP_FREQ 3.20
#define PERLIN_BUMP_FREQ 4.00

double	calc_bump_height(t_cord p, t_bump bump)
{
	double	wave;

	if (bump == SINE)
	{
		wave = p.y * SINE_BUMP_FREQ;
		wave = wave + sin(p.x * 0.55) * 0.75;
		return (sin(wave));
	}
	if (bump == PERLIN)
		return (perlin_noise(vec3_mul(p, PERLIN_BUMP_FREQ)));
	return (0.0);
}

t_cord	calc_bump_tangent(t_cord n)
{
	t_cord	axis;
	t_cord	tangent;

	axis = cre_t_cord(0.0, 1.0, 0.0);
	if (fabs(n.y) > 0.9)
		axis = cre_t_cord(1.0, 0.0, 0.0);
	tangent = vec3_cross(axis, n);
	return (vec3_normalise(tangent));
}

t_cord	calc_bump_sample_point(t_cord p, t_cord tangent, double step)
{
	return (vec3_add(p, vec3_mul(tangent, step)));
}

double	calc_bump_delta(t_cord p, t_cord tangent, t_bump bump)
{
	double	delta;

	delta = calc_bump_height(calc_bump_sample_point(p, tangent, BUMP_EPS),
			bump);
	delta = delta - calc_bump_height(calc_bump_sample_point(p, tangent,
				-BUMP_EPS), bump);
	return (delta / (2.0 * BUMP_EPS));
}

t_cord	calc_pixel_l_each_bump_deviation(t_cord p, t_cord sur_vec, t_obj *cur)
{
	t_cord	res;
	t_cord	tangent_u;
	t_cord	tangent_v;
	double	du;
	double	dv;

	res = vec3_mul(sur_vec, 1);
	if (cur->bump == EMPTY || (cur->bump != SINE && cur->bump != PERLIN))
		return (res);
	p = vec3_sub(p, cur->cord);
	tangent_u = calc_bump_tangent(sur_vec);
	tangent_v = vec3_normalise(vec3_cross(sur_vec, tangent_u));
	du = calc_bump_delta(p, tangent_u, cur->bump);
	dv = calc_bump_delta(p, tangent_v, cur->bump);
	res = vec3_sub(res, vec3_mul(tangent_u, du * BUMP_STRENGTH));
	res = vec3_sub(res, vec3_mul(tangent_v, dv * BUMP_STRENGTH));
	return (vec3_normalise(res));
}

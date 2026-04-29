/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_normal.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:56:44 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:57:19 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cord	calc_point(t_ray *ray)
{
	t_cord	res;

	initialise_t_cord(&res);
	res = vec3_mul(ray->ori, ray->t);
	res = vec3_add(ray->cord, res);
	return (res);
}

double	calc_surface_normal_cy_distance(t_cord p, t_obj *cur)
{
	t_cord	vector;
	double	res;

	initialise_t_cord(&vector);
	vector = vec3_sub(p, cur->cord);
	res = vec3_dot(vector, cur->ori);
	return (res);
}

t_cord	calc_surface_normal(t_cord p, t_obj *cur)
{
	t_cord	res;
	double	m;
	t_cord	new_center;

	initialise_t_cord(&res);
	if		(cur->type == SP)
		res = vec3_sub(p, cur->cord);
	else if (cur->type == PL)
		res = cur->ori;
	else if (cur->type == CY)
	{
		if		(cur->lhit == FLAT_TOP)
			res = cur->ori;
		else if (cur->lhit == FLAT_BOT)
			res = vec3_mul(cur->ori, -1);
		else if (cur->lhit == TUBE)
		{
			m = calc_surface_normal_cy_distance(p, cur);
			new_center = vec3_mul(cur->ori, m);
			new_center = vec3_add(new_center, cur->cord);
			res = vec3_sub(p, new_center);
		}
	}
	res = vec3_normalise(res);
	return (res);
}

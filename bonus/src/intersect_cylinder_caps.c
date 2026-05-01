/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_caps.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:32:47 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:33:36 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	calc_intersect_pl_hlp(t_cord rayori, t_cord raydir, t_cord center,
		t_cord normal)
{
	double	a;
	double	t;

	a = vec3_dot(raydir, normal);
	if (-EPSILON < a && a < EPSILON)
		return (-1);
	t = vec3_dot(center, normal) - vec3_dot(rayori, normal);
	t = t / a;
	if (t < EPSILON)
		return (-1);
	return (t);
}

double	ft_max_dbl(double f1, double f2)
{
	if (f1 > f2)
		return (f1);
	return (f2);
}

double	ft_min_dbl(double f1, double f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

int	calc_intersect_cy_plin(double t, t_cord top, t_ray *ray, t_obj *obj)
{
	t_cord	p;
	t_cord	v;
	double	m;
	double	r;

	p = vec3_add(ray->cord, vec3_mul(ray->ori, t));
	v = vec3_sub(top, p);
	m = vec3_dot(v, v);
	r = obj->dia / 2;
	if (m <= r * r)
		return (1);
	return (0);
}

double	calc_intersect_cy_plin_lhit(double final, double res, t_ray *ray,
		t_lhit lhit)
{
	if (final < res)
		return (final);
	ray->lhit = lhit;
	return (res);
}

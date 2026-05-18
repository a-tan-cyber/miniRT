/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:27:27 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 22:12:13 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_discriminant(double a, double b, double c)
{
	return ((b * b) - (4.0 * a * c));
}

double	ft_solve_quadratic_abd_near(double a, double b, double delta)
{
	double	t1;
	double	t2;

	t2 = (-b - sqrt(delta)) / (2.0 * a);
	if (t2 >= 0)
		return (t2);
	t1 = (-b + sqrt(delta)) / (2.0 * a);
	if (t1 >= 0)
		return (t1);
	return (-1);
}

//might optimise
double	ft_solve_quadratic_abd_far(double a, double b, double delta)
{
	double	t1;
	double	t2;

	t1 = (-b + sqrt(delta)) / (2.0 * a);
	if (t1 >= 0)
		return (t1);
	t2 = (-b - sqrt(delta)) / (2.0 * a);
	if (t2 >= 0)
		return (t2);
	return (-1);
}

// ellipsoid: Squish the Ray ray.ori / obj.dia_xyz; ray.cord / obj.dia_xyz
// sphere: x^2 + y^2 + z^2 = r^2
double	calc_intersect_sp(t_ray *ray, t_obj *obj)
{
	double	a;
	double	b;
	double	c;
	t_cord	tmp;
	double	r;

	a = vec3_dot(ray->ori, ray->ori);
	b = 2 * (vec3_dot(ray->ori, (vec3_sub(ray->cord, obj->cord))));
	tmp = vec3_sub(ray->cord, obj->cord);
	r = obj->dia / 2.0;
	c = vec3_dot(tmp, tmp) - (r * r);
	r = ft_discriminant(a, b, c);
	if (r >= 0)
		return (ft_solve_quadratic_abd_near(a, b, r));
	return (-1);
}

// check if parallel to plane using Normal
double	calc_intersect_pl(t_ray *ray, t_obj *obj)
{
	double	a;
	double	t;

	a = vec3_dot(ray->ori, obj->ori);
	if (-EPSILON < a && a < EPSILON)
	{
		return (-1);
	}
	t = obj->plane_constant - vec3_dot(obj->ori, ray->cord);
	t = t / a;
	if (t < EPSILON)
		return (-1);
	return (t);
}

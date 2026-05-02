/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_basic.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:27:27 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:28:55 by amtan            ###   ########.fr       */
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

t_cord	vec3_div(t_cord x, double times)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x / times;
	res.y = x.y / times;
	res.z = x.z / times;
	return (res);
}

t_cord	vec3_mul_vec3(t_cord x, t_cord y)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x * y.x;
	res.y = x.y * y.y;
	res.z = x.z * y.z;
	return (res);	
}

t_cord	vec3_div_vec3(t_cord x, t_cord y)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x / y.x;
	res.y = x.y / y.y;
	res.z = x.z / y.z;
	return (res);
}

// ellipsoid: Squish the Ray ray.ori / obj.dia_xyz; ray.cord / obj.dia_xyz
double	calc_intersect_el(t_ray *ray, t_obj *obj)
{
	t_cord	r;
	t_cord	ray_ori;
	t_cord	ray_cord;
	t_calc	calc;

	initialise_t_cord(&r);
	initialise_t_cord(&ray_ori);
	initialise_t_cord(&ray_cord);
	initialise_t_calc(&calc);
	r = vec3_div(obj->dia_xyz, 2);
	ray_ori = vec3_div_vec3(ray->ori, r);
	ray_cord = vec3_sub(ray->cord, obj->cord);
	ray_cord = vec3_div_vec3(ray_cord, r);
	calc.a = vec3_dot(ray_ori, ray_ori);
	calc.b = 2 * vec3_dot(ray_ori, ray_cord);
	calc.c = vec3_dot(ray_cord, ray_cord) - (1);
	calc.delta = ft_discriminant(calc.a, calc.b, calc.c);
	if (calc.delta >= 0)
		return (ft_solve_quadratic_abd_near(calc.a, calc.b, calc.delta));
	return (-1);
}

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder_tube_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:31:11 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:58:44 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

double	calc_intersect_cy_tube(t_ray *ray, t_obj *obj)
{
	t_calc	calc;
	double	t;
	double	m;

	calc = calc_intersect_cy_tube_dis(ray, obj);
	if (calc.delta < EPSILON)
		return (-1);
	t = ft_solve_quadratic_abd_near(calc.a, calc.b, calc.delta);
	m = calc_intersect_cy_tube_height(t, calc);
	if (m > -obj->higt / 2.0 && m < obj->higt / 2.0)
		return (t);
	t = ft_solve_quadratic_abd_far(calc.a, calc.b, calc.delta);
	m = calc_intersect_cy_tube_height(t, calc);
	if (m > -obj->higt / 2.0 && m < obj->higt / 2.0)
		return (t);
	return (-1);
}

void	initialise_t_calc(t_calc *calc)
{
	calc->a = 0;
	calc->b = 0;
	calc->c = 0;
	calc->sto1 = 0;
	calc->sto2 = 0;
	calc->delta = 0;
	calc->u = 0;
	calc->v = 0;
	initialise_t_cord(&calc->x);
}

t_calc	calc_intersect_cy_tube_dis(t_ray *ray, t_obj *obj)
{
	t_calc	calc;
	double	r;

	initialise_t_calc(&calc);
	calc.x = vec3_sub(ray->cord, obj->cord);
	r = obj->dia / 2;
	calc.a = vec3_dot(ray->ori, obj->ori);
	calc.sto1 = calc.a;
	calc.a = vec3_dot(ray->ori, ray->ori) - (calc.a * calc.a);
	calc.b = 2 * (vec3_dot(calc.x, ray->ori) - vec3_dot(obj->ori, calc.x)
			* vec3_dot(ray->ori, obj->ori));
	calc.c = vec3_dot(obj->ori, calc.x);
	calc.sto2 = calc.c;
	calc.c = vec3_dot(calc.x, calc.x) - (calc.c * calc.c) - (r * r);
	calc.delta = ft_discriminant(calc.a, calc.b, calc.c);
	return (calc);
}

// m = (P - C) dot N
double	calc_intersect_cy_tube_height(double t, t_calc calc)
{
	double	m;

	m = calc.sto2 + t * calc.sto1;
	return (m);
}

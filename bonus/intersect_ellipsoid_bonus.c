/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_ellipsoid_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:40:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:58:50 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_dispatch.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:33:51 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:34:22 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// cylinder: |((P - C) X N)|^2 = r^2
double	calc_intersect_cy(t_ray *ray, t_obj *obj)
{
	double	res1;
	double	final;
	t_cord	top;
	t_cord	bot;

	final = DBL_MAX;
	top = vec3_add(obj->cord, vec3_mul(obj->ori, obj->higt / 2.0));
	bot = vec3_sub(obj->cord, vec3_mul(obj->ori, obj->higt / 2.0));
	res1 = calc_intersect_cy_tube(ray, obj);
	if (res1 > 0)
	{
		final = res1;
		obj->lhit = TUBE;
	}
	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, top, obj->ori);
	if (res1 > 0 && calc_intersect_cy_plin(res1, top, ray, obj) == 1)
		final = calc_intersect_cy_plin_lhit(final, res1, obj, FLAT_TOP);
	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, bot, obj->ori);
	if (res1 > 0 && calc_intersect_cy_plin(res1, bot, ray, obj) == 1)
		final = calc_intersect_cy_plin_lhit(final, res1, obj, FLAT_BOT);
	if (final == DBL_MAX)
		return (-1);
	return (final);
}

double	calc_ray_t(t_ray *ray, t_obj *obj)
{
	double	res;

	res = -1.0;
	if (obj->type == SP)
	{
		res = calc_intersect_sp(ray, obj);
	}
	else if (obj->type == PL)
	{
		res = calc_intersect_pl(ray, obj);
	}
	else if (obj->type == CY)
	{
		res = calc_intersect_cy(ray, obj);
	}
	return (res);
}

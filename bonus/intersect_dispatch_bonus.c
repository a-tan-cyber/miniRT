/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_dispatch_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:33:51 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:58:47 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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
		ray->lhit = TUBE;
	}
	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, top, obj->ori);
	if (res1 > 0 && calc_intersect_cy_plin(res1, top, ray, obj) == 1)
		final = calc_intersect_cy_plin_lhit(final, res1, ray, FLAT_TOP);
	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, bot, obj->ori);
	if (res1 > 0 && calc_intersect_cy_plin(res1, bot, ray, obj) == 1)
		final = calc_intersect_cy_plin_lhit(final, res1, ray, FLAT_BOT);
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
	else if (obj->type == EL)
	{
		res = calc_intersect_el(ray, obj);
	}
	return (res);
}

t_obj	*calc_pixel_frt_s(t_ray *ray, t_obj *frt, t_obj *obj)
{
	double	near;
	double	curr;

	if (frt == NULL)
	{
		curr = calc_ray_t(ray, obj);
		if (curr <= EPSILON)
			return (NULL);
		ray->t = curr;
		return (obj);
	}
	near = ray->t;
	curr = calc_ray_t(ray, obj);
	if (curr >= EPSILON && near > curr)
	{
		ray->t = curr;
		return (obj);
	}
	return (frt);
}

t_obj	*calc_pixel_frt(t_ray *ray, t_obj *obj)
{
	t_obj	*frt;

	if (!ray || !obj)
		return (NULL);
	frt = NULL;
	while (obj != NULL)
	{
		frt = calc_pixel_frt_s(ray, frt, obj);
		obj = obj->next;
	}
	return (frt);
}

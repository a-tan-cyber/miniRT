/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_checker_uv.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:10:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:10:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define CHKR_SCALE 0.5

void	calc_chkr_uv_pl(t_calc *calc, t_cord p, t_obj *cur)
{
	t_cord	vec_caterpillar_u;
	t_cord	vec_caterpillar_v;
	t_cord	up;
	t_cord	local_p;

	if (cur->ori.y == 1 || cur->ori.y == -1)
	{
		calc->u = (p.x - cur->cord.x);
		calc->v = (p.z - cur->cord.z);
	}
	else
	{
		up = cre_t_cord(0.0, 1.0, 0.0);
		vec_caterpillar_u = vec3_cross(cur->ori, up);
		vec_caterpillar_u = vec3_normalise(vec_caterpillar_u);
		vec_caterpillar_v = vec3_cross(vec_caterpillar_u, cur->ori);
		local_p = vec3_sub(p, cur->cord);
		calc->u = vec3_dot(vec_caterpillar_u, local_p);
		calc->v = vec3_dot(vec_caterpillar_v, local_p);
	}
	calc->u = calc->u;
	calc->v = calc->v;
}

double	bound_limit_dbl(double val, double min, double max)
{
	if (val < min)
		return (min);
	else if (val > max)
		return (max);
	else
		return (val);
}

void	calc_chkr_uv_sp(t_calc *calc, t_cord p, t_obj *cur)
{
	double	longtitude;
	double	latitude;
	double	r;
	t_cord	local_p;

	local_p = vec3_sub(p, cur->cord);
	r = 1.0;
	if (cur->type == SP)
		r = cur->dia / 2;
	else if (cur->type == EL)
		local_p = vec3_div_vec3(local_p, vec3_div(cur->dia_xyz, 2.0));
	longtitude = atan2(local_p.x, local_p.z);
	longtitude = (longtitude + RT_PI) / (2.0 * RT_PI);
	latitude = asin(bound_limit_dbl(local_p.y / r, -1.0, 1.0));
	latitude = (latitude + RT_PI_HALF) / RT_PI;
	if (cur->type == SP)
	{
		calc->u = longtitude * 2 * r * RT_PI;
		calc->v = latitude * r * RT_PI;
		return ;
	}
	calc->u = longtitude * 2 * cur->dia_xyz.x * RT_PI / 2;
	calc->v = latitude * cur->dia_xyz.z * RT_PI / 2;
}

void	calc_chkr_uv_cy(t_calc *calc, t_cord p, t_ray *ray, t_obj *cur)
{
	t_cord	vec_caterpillar_u;
	t_cord	vec_caterpillar_v;
	t_cord	local_p;
	t_cord	up;

	if (ray->lhit == FLAT_TOP || ray->lhit == FLAT_BOT)
		calc_chkr_uv_pl(calc, p, cur);
	else if (ray->lhit == TUBE)
	{
		local_p = vec3_sub(p, cur->cord);
		if (cur->ori.y == 1 || cur->ori.y == -1)
		{
			calc->u = atan2(local_p.x, local_p.z);
			calc->u = (calc->u + RT_PI) / (2.0 * RT_PI) * cur->dia * RT_PI;
			calc->v = (p.y - cur->cord.y);
			return ;
		}
		up = cre_t_cord(0.0, 1.0, 0.0);
		vec_caterpillar_u = vec3_normalise(vec3_cross(cur->ori, up));
		vec_caterpillar_v = vec3_cross(cur->ori, vec_caterpillar_u);
		calc->u = atan2(vec3_dot(vec_caterpillar_v, local_p),
				vec3_dot(vec_caterpillar_u, local_p));
		calc->u = (calc->u + RT_PI) / (2.0 * RT_PI) * cur->dia * RT_PI;
		calc->v = vec3_dot(cur->ori, local_p);
	}
}

void	calc_chkr_uv(t_calc *calc, t_cord p, t_ray *ray, t_obj *cur)
{
	if (cur->type == PL)
	{
		calc_chkr_uv_pl(calc, p, cur);
	}
	else if (cur->type == SP || cur->type == EL)
	{
		calc_chkr_uv_sp(calc, p, cur);
	}
	else if (cur->type == CY)
	{
		calc_chkr_uv_cy(calc, p, ray, cur);
	}
	else
		ft_puterr("calc_ckr_uv: cur->type = unknown shape");
}

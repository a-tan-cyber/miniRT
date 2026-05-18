/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_perlin.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:25:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:25:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	perlin_square_mix(t_cord base, t_cord pos, t_cord fade, double zadd)
{
	double	a;
	double	b;

	a = perlin_corner((int)base.x, (int)base.y, (int)(base.z + zadd),
			cre_t_cord(pos.x, pos.y, pos.z - zadd));
	b = perlin_corner((int)base.x + 1, (int)base.y,
			(int)(base.z + zadd),
			cre_t_cord(pos.x - 1.0, pos.y, pos.z - zadd));
	a = perlin_lerp(fade.x, a, b);
	b = perlin_corner((int)base.x, (int)base.y + 1,
			(int)(base.z + zadd),
			cre_t_cord(pos.x, pos.y - 1.0, pos.z - zadd));
	b = perlin_lerp(fade.x, b, perlin_corner((int)base.x + 1,
				(int)base.y + 1, (int)(base.z + zadd),
				cre_t_cord(pos.x - 1.0, pos.y - 1.0, pos.z - zadd)));
	return (perlin_lerp(fade.y, a, b));
}

double	perlin_cube_mix(t_cord base, t_cord pos, t_cord fade)
{
	double	a;
	double	b;

	a = perlin_square_mix(base, pos, fade, 0.0);
	b = perlin_square_mix(base, pos, fade, 1.0);
	return (perlin_lerp(fade.z, a, b));
}

double	perlin_noise(t_cord p)
{
	t_cord	base;
	t_cord	pos;
	t_cord	fade;

	pos = cre_t_cord(p.x * 0.25, p.y * 0.25, p.z * 0.25);
	base = cre_t_cord(floor(pos.x), floor(pos.y), floor(pos.z));
	pos = cre_t_cord(pos.x - base.x, pos.y - base.y, pos.z - base.z);
	fade = cre_t_cord(perlin_fade(pos.x), perlin_fade(pos.y),
			perlin_fade(pos.z));
	return (perlin_cube_mix(base, pos, fade));
}

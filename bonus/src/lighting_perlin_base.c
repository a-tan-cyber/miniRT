/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_perlin_base.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:25:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:25:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	perlin_fade(double t)
{
	return (t * t * t * (t * (t * 6.0 - 15.0) + 10.0));
}

double	perlin_lerp(double t, double a, double b)
{
	return (a + t * (b - a));
}

int	perlin_hash(int x, int y, int z)
{
	unsigned int	hash;

	hash = (unsigned int)x * 374761393u;
	hash = hash + (unsigned int)y * 668265263u;
	hash = hash + (unsigned int)z * 2246822519u;
	hash = (hash ^ (hash >> 13u)) * 1274126177u;
	return ((int)(hash & 15u));
}

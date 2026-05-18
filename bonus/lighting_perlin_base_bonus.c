/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_perlin_base_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:59:33 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:59:38 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

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

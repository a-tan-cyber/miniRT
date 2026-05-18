/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_perlin_grad.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:25:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:25:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	perlin_grad_u(int h, double x, double y)
{
	if (h < 8)
		return (x);
	return (y);
}

double	perlin_grad_v(int h, double x, double y, double z)
{
	if (h < 4)
		return (y);
	if (h == 12 || h == 14)
		return (x);
	return (z);
}

double	perlin_grad_sign(int h, double u, double v)
{
	double	res;

	res = 0.0;
	if ((h & 1) == 0)
		res = res + u;
	else
		res = res - u;
	if ((h & 2) == 0)
		res = res + v;
	else
		res = res - v;
	return (res);
}

double	perlin_grad(int hash, double x, double y, double z)
{
	int		h;
	double	u;
	double	v;

	h = hash & 15;
	u = perlin_grad_u(h, x, y);
	v = perlin_grad_v(h, x, y, z);
	return (perlin_grad_sign(h, u, v));
}

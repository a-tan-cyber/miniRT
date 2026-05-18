/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:10:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:10:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	pow64_dbl(double x)
{
	double	res;

	res = x * x;
	res *= res;
	res *= res;
	res *= res;
	res *= res;
	res *= res;
	return (res);
}

t_cord	vec3_2pvec_norm(t_cord p1, t_cord p2)
{
	t_cord	res;

	initialise_t_cord(&res);
	res = vec3_sub(p1, p2);
	res = vec3_normalise(res);
	return (res);
}

t_rgb	cre_t_rgb(int r, int g, int b)
{
	t_rgb	res;

	res.r = r;
	res.g = g;
	res.b = b;
	return (res);
}

t_cord	cre_t_cord(double x, double y, double z)
{
	t_cord	res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}

void	initialise_t_box(t_box *box)
{
	initialise_t_cord(&box->p);
	initialise_t_cord(&box->sur_vec);
	initialise_t_cord(&box->s2l_vec);
	initialise_t_rgb(&box->s);
	box->ln_dotp = 0;
}

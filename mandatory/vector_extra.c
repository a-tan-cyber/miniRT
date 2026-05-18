/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_extra.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:53:17 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 19:53:55 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cord	vec3_cross(t_cord f, t_cord up)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = (f.y * up.z) - (up.y * f.z);
	res.y = (up.x * f.z) - (f.x * up.z);
	res.z = (f.x * up.y) - (up.x * f.y);
	return (res);
}

t_cord	vec3_normalise(t_cord ori)
{
	t_cord	res;
	double	mag;

	mag = (ori.x * ori.x) + (ori.y * ori.y) + (ori.z * ori.z);
	mag = sqrt(mag);
	initialise_t_cord(&res);
	if (mag > 0)
	{
		res.x = ori.x / mag;
		res.y = ori.y / mag;
		res.z = ori.z / mag;
	}
	return (res);
}

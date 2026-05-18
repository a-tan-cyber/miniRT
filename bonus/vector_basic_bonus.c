/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_basic_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:49:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:02:17 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

double	vec3_dot(t_cord c1, t_cord c2)
{
	return (c1.x * c2.x + c1.y * c2.y + c1.z * c2.z);
}

t_cord	vec3_sub(t_cord c1, t_cord c2)
{
	t_cord	res;

	res.x = c1.x - c2.x;
	res.y = c1.y - c2.y;
	res.z = c1.z - c2.z;
	return (res);
}

t_cord	vec3_mul(t_cord x, double times)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x * times;
	res.y = x.y * times;
	res.z = x.z * times;
	return (res);
}

t_cord	vec3_add(t_cord x, t_cord y)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x + y.x;
	res.y = x.y + y.y;
	res.z = x.z + y.z;
	return (res);
}

double	vec3_len_sq(t_cord p, t_cord cord)
{
	t_cord	vector;
	double	t;

	initialise_t_cord(&vector);
	vector = vec3_sub(p, cord);
	t = vec3_dot(vector, vector);
	return (t);
}

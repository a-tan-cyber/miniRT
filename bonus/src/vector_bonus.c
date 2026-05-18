/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:30:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 22:30:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cord	vec3_div(t_cord x, double times)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x / times;
	res.y = x.y / times;
	res.z = x.z / times;
	return (res);
}

t_cord	vec3_mul_vec3(t_cord x, t_cord y)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x * y.x;
	res.y = x.y * y.y;
	res.z = x.z * y.z;
	return (res);
}

t_cord	vec3_div_vec3(t_cord x, t_cord y)
{
	t_cord	res;

	initialise_t_cord(&res);
	res.x = x.x / y.x;
	res.y = x.y / y.y;
	res.z = x.z / y.z;
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_perlin_corner.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:25:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:25:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	perlin_corner(int x, int y, int z, t_cord dist)
{
	return (perlin_grad(perlin_hash(x, y, z), dist.x, dist.y, dist.z));
}

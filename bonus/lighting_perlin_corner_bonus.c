/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_perlin_corner_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 00:59:43 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:59:49 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

double	perlin_corner(int x, int y, int z, t_cord dist)
{
	return (perlin_grad(perlin_hash(x, y, z), dist.x, dist.y, dist.z));
}

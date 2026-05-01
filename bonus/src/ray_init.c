/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:03:45 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:04:03 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialise_t_ray(t_ray *ray)
{
	ray->t = -1.0f;
	initialise_t_cord(&ray->cord);
	initialise_t_cord(&ray->ori);
	ray->lhit = -1;
}

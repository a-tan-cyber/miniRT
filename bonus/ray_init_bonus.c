/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_init_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:03:45 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:02:15 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	initialise_t_ray(t_ray *ray)
{
	ray->t = -1.0f;
	initialise_t_cord(&ray->cord);
	initialise_t_cord(&ray->ori);
	ray->lhit = -1;
}

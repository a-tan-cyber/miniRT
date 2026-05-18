/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_thread_run_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:00:12 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:00:17 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	*calc_pixel_thrd_run(void *param)
{
	t_obj	*frt;
	t_ray	ray;
	int		y;
	int		x;
	t_thrd	*thrd;

	thrd = (t_thrd *)param;
	thrd->created = TRUE;
	frt = NULL;
	y = thrd->starty;
	while (y < thrd->endy)
	{
		x = 0;
		while (x < WIDTH)
		{
			initialise_t_ray(&ray);
			calc_ray_screen2obj(&ray, x, y, thrd->data);
			frt = calc_pixel_frt(&ray, thrd->obj);
			calc_pixel_a(y, x, calc_pixel_l(&ray, frt, thrd->data->ligt,
					thrd->data), thrd->data);
			x++;
		}
		y++;
	}
	return (NULL);
}

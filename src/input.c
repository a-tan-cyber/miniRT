/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:38:14 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 21:49:15 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// sudo showkey -a
// linux: ESC == 65307;
// linux: e == 101; s == 115; d == 100; f == 102;
int	handle_keypress(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC)
		return (free_rt(&data->obj_head, &data), exit(0), 0);
	if (key == T || key == G || key == E || key == S || key == D || key == F)
	{
		move_cam_strafe(key, data);
	}
	else if (key == I || key == J || key == K || key == L)
	{
		move_cam_aim(key, data);
	}
	else
		return (0);
	ft_putstr("Camera coord: ");
	ft_print_t_cord(data->cam.cord);
	ft_putstr("Camera angle: ");
	ft_print_t_cord(data->cam.ori);
	ft_putstr("\n");
	return (0);
}

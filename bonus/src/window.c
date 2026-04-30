/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:11:40 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:23:57 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <X11/X.h>

int	initialise_minilibx(t_data **data)
{
	t_data	*curr;

	curr = *data;
	curr->mlx = mlx_init();
	if (!curr->mlx)
		return (ft_puterr("initialise_minilibx: failed to initialise curr->mlx")
			, 1);
	curr->win = mlx_new_window(curr->mlx, WIDTH, HEIGHT, "miniRT");
	if (!curr->win)
		return (ft_puterr("initialise_minilibx: failed to initialise curr->win")
			, 2);
	curr->img = mlx_new_image(curr->mlx, WIDTH, HEIGHT);
	if (!curr->img)
		return (ft_puterr("initialise_minilibx: failed to initialise curr->img")
			, 3);
	curr->addr = mlx_get_data_addr(curr->img, &curr->bits_p_pixel,
			&curr->size_line, &curr->endian);
	if (!curr->addr)
		return (
			ft_puterr("initialise_minilibx: failed to initialise curr->addr")
			, 4);
	return (0);
}

int	redraw_window(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (!data || !data->mlx || !data->win || !data->img)
		return (0);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	return (0);
}

int	add_event_hook(t_data *data)
{
	mlx_hook(data->win, 17, 0, redx, (void *)data);
	mlx_hook(data->win, 2, 1L << 0, handle_keypress, (void *)data);
	mlx_expose_hook(data->win, redraw_window, (void *)data);
	mlx_hook(data->win, ConfigureNotify, StructureNotifyMask,
		redraw_window, (void *)data);
	return (0);
}

int	run_window_loop(t_data *data)
{
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
	mlx_loop(data->mlx);
	return (0);
}

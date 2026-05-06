/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:10:47 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:11:21 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	free_t_obj_all(t_obj *head)
{
	t_obj	*cur;

	while (head)
	{
		cur = head;
		head = head->next;
		ft_sfree((void **)&cur);
	}
}

void	free_t_data(t_data *data)
{
	if (!data)
		return ;
	if (data->img)
		mlx_destroy_image(data->mlx, data->img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		ft_sfree((void **)&data->mlx);
	}
	// free data->ligt
	ft_sfree((void **)&data);
}

void	free_rt(t_obj **obj, t_data **data)
{
	if (obj && *obj)
	{
		free_t_obj_all(*obj);
		*obj = NULL;
	}
	if (data && *data)
	{
		free_t_data(*data);
		*data = NULL;
	}
}

int	redx(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	free_rt(&data->obj_head, &data);
	exit(0);
	return (0);
}

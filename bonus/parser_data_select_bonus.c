/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_select_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:00:55 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:01:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	add_rt_data_d_ambient(const char **split_arr, t_data **data)
{
	if ((*data)->ambi_loaded == TRUE)
		return (ft_puterr("duplicate ambient lighting"), -11);
	(*data)->ambi_loaded = TRUE;
	return (add_rt_data_d_a(split_arr, data));
}

int	add_rt_data_d_camera(const char **split_arr, t_data **data)
{
	if ((*data)->cam_loaded == TRUE)
		return (ft_puterr("duplicate camera setting"), -12);
	(*data)->cam_loaded = TRUE;
	return (add_rt_data_d_c(split_arr, &(*data)->cam));
}

int	add_rt_data_d_light(const char **split_arr, t_data **data)
{
	t_ligt	*new;

	new = cre_t_ligt_last((*data)->ligt);
	if (!new)
		return (ft_puterr("light malloc failed"), -13);
	if ((*data)->ligt == NULL)
		(*data)->ligt = new;
	return (add_rt_data_d_l(split_arr, new));
}

int	add_rt_data_d(const char **split_arr, t_data **data)
{
	if (ft_strcmp(split_arr[0], "A") == 0)
		return (add_rt_data_d_ambient(split_arr, data));
	if (ft_strcmp(split_arr[0], "C") == 0)
		return (add_rt_data_d_camera(split_arr, data));
	if (ft_strcmp(split_arr[0], "L") == 0)
		return (add_rt_data_d_light(split_arr, data));
	return (0);
}

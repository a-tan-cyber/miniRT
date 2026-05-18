/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object_common.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:50:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 22:50:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	obj_parse_cord(t_obj *new, const char *str, char *msg)
{
	char	**arr;

	arr = split_3_float(str, ",");
	if (!arr)
		return (ft_puterr(msg), -1);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -1);
	free_arr(arr);
	return (0);
}

int	obj_parse_dia_xyz(t_obj *new, const char *str, char *msg)
{
	char	**arr;

	arr = split_3_float(str, ",");
	if (!arr)
		return (ft_puterr(msg), -1);
	if (ins_vec3(&new->dia_xyz, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -1);
	free_arr(arr);
	return (0);
}

int	obj_parse_ori(t_obj *new, const char *str, char *msg)
{
	char	**arr;

	arr = split_3_double_range(str, ",", -1, 1);
	if (!arr || ins_vec3(&new->ori, arr[0], arr[1], arr[2])
		|| chk_normalised(new->ori))
		return (ft_puterr(msg), free_arr(arr), -1);
	free_arr(arr);
	return (0);
}

int	obj_parse_rgb(t_obj *new, const char *str, char *msg)
{
	char	**arr;

	arr = split_3_int_range(str, ",", "0", "255");
	if (!arr)
		return (ft_puterr(msg), -1);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -1);
	free_arr(arr);
	return (0);
}

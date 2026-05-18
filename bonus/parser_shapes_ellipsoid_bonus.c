/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shapes_ellipsoid_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:02:01 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:02:05 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	val_el_dia_xyz(t_cord dia_xyz)
{
	if (dia_xyz.x <= 0.0)
		return (ft_puterr("ellipsoid x diameter must be positive"), -1);
	if (dia_xyz.y <= 0.0)
		return (ft_puterr("ellipsoid y diameter must be positive"), -1);
	if (dia_xyz.z <= 0.0)
		return (ft_puterr("ellipsoid z diameter must be positive"), -1);
	return (0);
}

int	add_rt_data_s_el(const char **split_arr, t_obj *new)
{
	if (ft_arrlen(split_arr) < 4 || ft_arrlen(split_arr) > 6)
		return (ft_puterr("ellipsoid wrong number of fields"), -2);
	new->type = EL;
	if (obj_parse_cord(new, split_arr[1], "obj.cord el error"))
		return (-3);
	if (obj_parse_dia_xyz(new, split_arr[2], "obj.diaxyz el error"))
		return (-4);
	if (val_el_dia_xyz(new->dia_xyz))
		return (-4);
	if (obj_parse_rgb(new, split_arr[3], "obj.rgb el error"))
		return (-5);
	if (ins_obj_bonus(split_arr, 4, new))
		return (-6);
	return (0);
}

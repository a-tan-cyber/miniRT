/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shapes_basic.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:50:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 22:50:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	add_rt_data_s_sp(const char **split_arr, t_obj *new)
{
	if (ft_arrlen(split_arr) < 4 || ft_arrlen(split_arr) > 6)
		return (ft_puterr("sphere wrong number of fields"), -2);
	new->type = SP;
	if (obj_parse_cord(new, split_arr[1], "obj.cord error"))
		return (-3);
	if (ft_atof(split_arr[2]) <= 0)
		return (ft_puterr("obj.dia error"), 3);
	new->dia = ft_atod(split_arr[2]);
	if (obj_parse_rgb(new, split_arr[3], "obj.rgb error"))
		return (-4);
	if (ins_obj_bonus(split_arr, 4, new))
		return (-6);
	return (0);
}

int	add_rt_data_s_pl(const char **split_arr, t_obj *new)
{
	if (ft_arrlen(split_arr) < 4 || ft_arrlen(split_arr) > 6)
		return (ft_puterr("plane wrong number of fields"), -2);
	new->type = PL;
	if (obj_parse_cord(new, split_arr[1], "obj.cord error"))
		return (-3);
	if (obj_parse_ori(new, split_arr[2], "obj.ori error"))
		return (2);
	if (obj_parse_rgb(new, split_arr[3], "obj.rgb error"))
		return (-4);
	if (ins_obj_bonus(split_arr, 4, new))
		return (-6);
	new->plane_constant = vec3_dot(new->cord, new->ori);
	return (0);
}

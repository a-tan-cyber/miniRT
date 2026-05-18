/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_shapes_cylinder_bonus.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:01:53 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:01:57 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	add_rt_data_s_cy(const char **split_arr, t_obj *new)
{
	if (ft_arrlen(split_arr) < 6 || ft_arrlen(split_arr) > 8)
		return (ft_puterr("cylinder wrong number of fields"), -2);
	new->type = CY;
	if (obj_parse_cord(new, split_arr[1], "cylinder obj.cord error"))
		return (-3);
	if (obj_parse_ori(new, split_arr[2], "cylinder obj.ori error"))
		return (-3);
	if (ft_atof(split_arr[3]) <= 0 || ft_atof(split_arr[4]) <= 0)
		return (ft_puterr("cylinder diameter <= 0 or height <= 0"), 3);
	new->dia = ft_atod(split_arr[3]);
	new->higt = ft_atod(split_arr[4]);
	if (obj_parse_rgb(new, split_arr[5], "cylinder obj.rgb error"))
		return (4);
	if (ins_obj_bonus(split_arr, 6, new))
		return (-6);
	return (0);
}

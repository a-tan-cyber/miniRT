/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_data_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:12:35 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:00:52 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	add_rt_data_d_a(const char **split_arr, t_data **data)
{
	char	**arr;

	if (ft_arrlen(split_arr) != 3)
		return (ft_puterr("ambient wrong number of fields"), -1);
	if (ft_str_is_float(split_arr[1]) == FALSE)
		return (ft_puterr("data.ambi ratio is not float"), 1);
	(*data)->ambi.ratio = ft_atod(split_arr[1]);
	if ((*data)->ambi.ratio > 1.0 || (*data)->ambi.ratio < 0.0)
		return (ft_puterr("data.ambi value is out of range"), -2);
	arr = ft_split(split_arr[2], " ,\r\n");
	if (!arr)
		return (ft_puterr("malloc failed (data.ambi.rgb)"), 2);
	if (ft_arrlen((const char **)arr) != 3)
		return (ft_puterr("data.ambi wrong no. of rgb val"), free_arr(arr), 3);
	if (validate_str_int_range(arr[0], "0", "255") == FALSE)
		return (ft_puterr("data.ambi.r value invalid"), free_arr(arr), 4);
	(*data)->ambi.rgb.r = ft_atoi(arr[0]);
	if (validate_str_int_range(arr[1], "0", "255") == FALSE)
		return (ft_puterr("data.ambi.g value invalid"), free_arr(arr), 5);
	(*data)->ambi.rgb.g = ft_atoi(arr[1]);
	if (validate_str_int_range(arr[2], "0", "255") == FALSE)
		return (ft_puterr("data.ambi.b value invalid"), free_arr(arr), 6);
	(*data)->ambi.rgb.b = ft_atoi(arr[2]);
	return (free_arr(arr), 0);
}

int	ins_vec3(t_cord *cord, const char *x, const char *y, const char *z)
{
	if (!cord)
		return (ft_puterr("ins_vec3 cord value is NULL"), -1);
	if (!ft_str_is_float(x) || !ft_str_is_float(y) || !ft_str_is_float(z))
		return (ft_puterr("ensure string is float before insertion"), 1);
	cord->x = ft_atod(x);
	cord->y = ft_atod(y);
	cord->z = ft_atod(z);
	return (0);
}

// ◦Camera:
// C -50.0,0,20 0,0,1 70
// ∗identifier: C
// ∗x, y, z coordinates of the viewpoint: -50.0,0,20
// ∗3D normalized orientation vector, in the range [-1,1] for each x, y, z axis:
// 0.0,0.0,1.0
// ∗FOV: Horizontal field of view in degrees in the range [0,180]: 70
int	add_rt_data_d_c(const char **split_arr, t_cam *cam)
{
	char	**arr;

	if (ft_arrlen(split_arr) != 4)
		return (ft_puterr("camera wrong number of fields"), -1);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("data.cam.cord error"), 2);
	if (ins_vec3(&cam->cord, arr[0], arr[1], arr[2]) != 0)
		return (free_arr(arr), -1);
	free_arr(arr);
	arr = split_3_double_range(split_arr[2], ",", -1, 1);
	if (!arr)
		return (ft_puterr("data.cam.ori error"), 3);
	if (ins_vec3(&cam->ori, arr[0], arr[1], arr[2])
		|| chk_normalised(cam->ori))
		return (ft_puterr("data.cam.ori error"), free_arr(arr), -2);
	free_arr(arr);
	if (validate_str_int_range(split_arr[3], "0", "180") == FALSE)
		return (ft_puterr("data.cam FOV val invalid"), 4);
	cam->fov = ft_atoi(split_arr[3]);
	return (0);
}

int	ins_rgb(t_rgb *rgb, const char *r, const char *g, const char *b)
{
	if (!rgb)
		return (ft_puterr("ins_rgb rgb value is NULL"), -1);
	if (!ft_str_is_int(r) || !ft_str_is_int(g) || !ft_str_is_int(b))
		return (ft_puterr("ensure string is int before insertion"), 1);
	rgb->r = ft_atoi(r);
	rgb->g = ft_atoi(g);
	rgb->b = ft_atoi(b);
	return (0);
}

// ◦Light:
// L -40.0,50.0,0.0 0.6 10,0,255
// ∗identifier: L
// ∗x, y, z coordinates of the light point: -40.0,50.0,0.0
// ∗the light brightness ratio in the range [0.0,1.0]: 0.6
// ∗(unused in mandatory part) R, G, B colors in the range [0-255]: 10, 0,
// 255
int	add_rt_data_d_l(const char **split_arr, t_ligt *ligt)
{
	char	**arr;

	if (ft_arrlen(split_arr) != 4)
		return (ft_puterr("light wrong number of fields"), -1);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("data.ligt.cord error"), 2);
	if (ins_vec3(&ligt->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -2);
	free_arr(arr);
	if (validate_str_float_range(split_arr[2], 0, 1) == 0)
		return (ft_puterr("data.ligt.bright error"), 3);
	ligt->bright = ft_atod(split_arr[2]);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("data.ligt.rgb error"), 4);
	if (ins_rgb(&ligt->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	return (0);
}

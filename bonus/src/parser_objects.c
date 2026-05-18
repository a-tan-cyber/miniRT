/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:13:55 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 21:14:55 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialise_t_ligt(t_ligt *ligt)
{
	initialise_t_cord(&ligt->cord);
	ligt->bright = -1;
	initialise_t_rgb(&ligt->rgb);
	ligt->next = NULL;
}

t_ligt	*go_t_ligt_last(t_ligt *ligt)
{
	t_ligt	*cur;

	cur = ligt;
	while (ligt)
	{
		cur = ligt;
		ligt = ligt->next;
	}
	return (cur);
}

t_ligt	*cre_t_ligt_new(void)
{
	t_ligt	*new;

	new = malloc(sizeof(t_ligt));
	if (!new)
		return (NULL);
	initialise_t_ligt(new);
	return (new);
}

t_ligt	*cre_t_ligt_last(t_ligt *ligt)
{
	t_ligt	*new;

	if (ligt == NULL)
		return (cre_t_ligt_new());
	ligt = go_t_ligt_last(ligt);
	new = cre_t_ligt_new();
	if (!new)
		return (NULL);
	ligt->next = new;
	return (new);
}

int	add_rt_data_d(const char **split_arr, t_data **data)
{
	int		err;
	t_ligt	*new;

	err = 0;
	if (ft_strcmp(split_arr[0], "A") == 0)
	{
		if ((*data)->ambi_loaded == TRUE)
			return (ft_puterr("duplicate ambient lighting"), -11);
		(*data)->ambi_loaded = TRUE;
		err = add_rt_data_d_a(split_arr, data);
	}
	else if (ft_strcmp(split_arr[0], "C") == 0)
	{
		if ((*data)->cam_loaded == TRUE)
			return (ft_puterr("duplicate camera setting"), -12);
		(*data)->cam_loaded = TRUE;
		err = add_rt_data_d_c(split_arr, &(*data)->cam);
	}
	else if (ft_strcmp(split_arr[0], "L") == 0)
	{
		new = cre_t_ligt_last((*data)->ligt);
		if ((*data)->ligt == NULL)
			(*data)->ligt = new;
		err = add_rt_data_d_l(split_arr, new);
	}
	return (err);
}

int	ins_chkr(t_bool *chkr, const char *str)
{
	if (!ft_strcmp("is_chkr", str))
		*chkr = TRUE;
	else if (!ft_strcmp("no_chkr", str))
		*chkr = FALSE;
	else
		return (ft_puterr("ins_chkr value is invalid"), -1);
	return (0);
}

int	ins_bump(t_bump *bump_type, const char *str)
{
	if (!ft_strcmp("sine", str))
		*bump_type = SINE;
	else if (!ft_strcmp("perlin", str))
		*bump_type = PERLIN;
	else if (!ft_strcmp("empty", str))
		*bump_type = EMPTY;
	else
		return (ft_puterr("bump type value is invalid"), -1);
	return (0);
}

int	is_chkr_token(const char *str)
{
	return (!ft_strcmp("is_chkr", str) || !ft_strcmp("no_chkr", str));
}

int	is_bump_token(const char *str)
{
	return (!ft_strcmp("sine", str) || !ft_strcmp("perlin", str)
		|| !ft_strcmp("empty", str));
}

int	ins_obj_bonus(const char **split_arr, int first_bonus, t_obj *new)
{
	int	len;

	len = ft_arrlen(split_arr);
	if (len == first_bonus)
		return (0);
	if (len > first_bonus + 2)
		return (ft_puterr("object wrong number of bonus fields"), -1);
	if (is_chkr_token(split_arr[first_bonus]))
	{
		if (ins_chkr(&new->chkr, split_arr[first_bonus]))
			return (-1);
	}
	else if (len == first_bonus + 1 && is_bump_token(split_arr[first_bonus]))
	{
		if (ins_bump(&new->bump, split_arr[first_bonus]))
			return (-1);
	}
	else
		return (ft_puterr("object bonus field is invalid"), -1);
	if (len == first_bonus + 2 && ins_bump(&new->bump,
			split_arr[first_bonus + 1]))
		return (-1);
	return (0);
}

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
	char	**arr;

	if (ft_arrlen(split_arr) < 4 || ft_arrlen(split_arr) > 6)
		return (ft_puterr("ellipsoid wrong number of fields"), -2);
	new->type = EL;
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("obj.cord el error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_float(split_arr[2], ",");
	if (!arr)
		return (ft_puterr("obj.diaxyz el error"), 3);
	if (ins_vec3(&new->dia_xyz, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	if (val_el_dia_xyz(new->dia_xyz))
		return (free_arr(arr), -4);
	free_arr(arr);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("obj.rgb el error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -5);
	free_arr(arr);
	if (ins_obj_bonus(split_arr, 4, new))
		return (-6);
	return (0);
}

/* 
Sphere:
sp 0.0,0.0,20.6 12.6 10,0,255
∗identifier: sp
∗x, y, z coordinates of the sphere center: 0.0,0.0,20.6
∗the sphere diameter: 12.6
∗R,G,B colors in the range [0-255]: 10, 0, 255
 */
int	add_rt_data_s_sp(const char **split_arr, t_obj *new)
{
	char	**arr;

	if (ft_arrlen(split_arr) < 4 || ft_arrlen(split_arr) > 6)
		return (ft_puterr("sphere wrong number of fields"), -2);
	new->type = SP;
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	if (ft_atof(split_arr[2]) <= 0)
		return (ft_puterr("obj.dia error"), 3);
	new->dia = ft_atod(split_arr[2]);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("obj.rgb error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	free_arr(arr);
	if (ins_obj_bonus(split_arr, 4, new))
		return (-6);
	return (0);
}

/* 
◦Plane:
pl 0.0,0.0,-10.0 0.0,1.0,0.0 0,0,225
∗identifier: pl
∗x, y, z coordinates of a point in the plane: 0.0,0.0,-10.0
∗3D normalized normal vector, in the range [-1,1] for each x, y, z axis:
0.0,1.0,0.0
∗R,G,B colors in the range [0-255]: 0,0,225
 */
int	add_rt_data_s_pl(const char **split_arr, t_obj *new)
{
	char	**arr;

	if (ft_arrlen(split_arr) < 4 || ft_arrlen(split_arr) > 6)
		return (ft_puterr("plane wrong number of fields"), -2);
	new->type = PL;
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_double_range(split_arr[2], ",", -1, 1);
	if (!arr || ins_vec3(&new->ori, arr[0], arr[1], arr[2])
		|| chk_normalised(new->ori))
		return (ft_puterr("obj.ori error"), free_arr(arr), 2);
	free_arr(arr);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("obj.rgb error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	free_arr(arr);
	if (ins_obj_bonus(split_arr, 4, new))
		return (-6);
	new->plane_constant = vec3_dot(new->cord, new->ori);
	return (0);
}

int	val_ins_rgb(const char *string, t_obj *new)
{
	char	**arr;

	arr = split_3_int_range(string, ",", "0", "255");
	if (!arr)
		return (ft_puterr("val_ins_rgb: error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	free_arr(arr);
	return (0);
}

/* 
◦Cylinder:
cy 50.0,0.0,20.6	0.0,0.0,1.0		14.2	21.42	10,0,255
∗identifier: cy
∗x, y, z coordinates of the center of the cylinder: 50.0,0.0,20.6
∗3D normalized vector of axis of cylinder, in the range [-1,1] for each x, y,
z axis: 0.0,0.0,1.0
∗the cylinder diameter: 14.2
∗the cylinder height: 21.42
∗R, G, B colors in the range [0,255]: 10, 0, 255 
*/
int	add_rt_data_s_cy(const char **split_arr, t_obj *new)
{
	char	**arr;

	if (ft_arrlen(split_arr) < 6 || ft_arrlen(split_arr) > 8)
		return (ft_puterr("cylinder wrong number of fields"), -2);
	new->type = CY;
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("cylinder obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_double_range(split_arr[2], ",", -1, 1);
	if (!arr || ins_vec3(&new->ori, arr[0], arr[1], arr[2])
		|| chk_normalised(new->ori))
		return (ft_puterr("cylinder obj.ori error"), free_arr(arr), -3);
	free_arr(arr);
	if (ft_atof(split_arr[3]) <= 0 || ft_atof(split_arr[4]) <= 0)
		return (ft_puterr("cylinder diameter <= 0 or height <= 0"), 3);
	new->dia = ft_atod(split_arr[3]);
	new->higt = ft_atod(split_arr[4]);
	if (val_ins_rgb(split_arr[5], new) != 0)
		return (ft_puterr("add_rt_data_s_cy: cylinder failed to ins rgb"), 4);
	if (ins_obj_bonus(split_arr, 6, new))
		return (-6);
	return (0);
}

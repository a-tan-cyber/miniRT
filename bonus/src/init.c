/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:39:38 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 19:45:31 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// typedef struct s_obj
// {
// 	t_type			type;
// 	t_cord			cord;
// 	double			dia;
// 	t_cord			dia_xyz;
// 	t_cord			ori;
// 	double			higt;
// 	t_rgb			rgb;
// 	double			plane_constant;
// 	t_bool			chkr;
// 	struct s_obj	*next;
// }	t_obj;

void	initialise_t_obj(t_obj **obj)
{
	t_obj	*cur_obj;

	cur_obj = *obj;
	cur_obj->type = -1;
	initialise_t_cord(&cur_obj->cord);
	cur_obj->dia = 0;
	initialise_t_cord(&cur_obj->dia_xyz);
	initialise_t_cord(&cur_obj->ori);
	cur_obj->higt = 0;
	initialise_t_rgb(&cur_obj->rgb);
	cur_obj->plane_constant = 0;
	cur_obj->chkr = FALSE;
	cur_obj->next = NULL;
}

void	initialise_t_cord(t_cord *cord)
{
	cord->x = 0;
	cord->y = 0;
	cord->z = 0;
}

void	initialise_t_rgb(t_rgb *rgb)
{
	rgb->r = -1;
	rgb->g = -1;
	rgb->b = -1;
}

void	initialise_t_data(t_data *cur_data)
{
	cur_data->ambi_loaded = FALSE;
	cur_data->ambi.ratio = -1;
	initialise_t_rgb(&cur_data->ambi.rgb);
	cur_data->cam_loaded = FALSE;
	initialise_t_cord(&cur_data->cam.cord);
	initialise_t_cord(&cur_data->cam.ori);
	cur_data->cam.fov = -1;
	cur_data->ligt_loaded = FALSE;
	initialise_t_cord(&cur_data->ligt.cord);
	cur_data->ligt.bright = -1;
	initialise_t_rgb(&cur_data->ligt.rgb);
	cur_data->mlx = NULL;
	cur_data->win = NULL;
	cur_data->img = NULL;
	cur_data->addr = NULL;
	cur_data->bits_p_pixel = -1;
	cur_data->size_line = -1;
	cur_data->endian = -1;
	cur_data->obj_head = NULL;
}

int	initialise_structs(t_obj **obj, t_data **data)
{
	(void)obj;
	*data = malloc(sizeof(t_data));
	if (!(*data))
		return (ft_puterr("initialise_structs (*data) malloc failed"), 1);
	initialise_t_data(*data);
	return (0);
}

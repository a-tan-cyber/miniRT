/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:35:00 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 21:36:48 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_cord	calc_vector_up(t_cord f)
{
	t_cord	up;

	initialise_t_cord(&up);
	if (f.x == 0.0f && (f.y == 1.0f || f.y == -1.0f) && f.z == 0.0f)
		up.z = -1.0f;
	else
		up.y = 1.0f;
	return (up);
}

// T == forward; G == backward;
// E == UP; D == Down; S == Left; F ==right;
void	move_cam_strafe(int key, t_data *data)
{
	t_cord	up;
	t_cord	right;

	if (key == T)
		data->cam.cord = vec3_add(data->cam.cord,
				vec3_mul(data->cam.ori, STEP));
	else if (key == G)
		data->cam.cord = vec3_sub(data->cam.cord,
				vec3_mul(data->cam.ori, STEP));
	else
	{
		up = vec3_normalise(calc_vector_up(data->cam.ori));
		right = vec3_cross(data->cam.ori, up);
		right = vec3_normalise(right);
		if (key == E)
			data->cam.cord = vec3_add(data->cam.cord, vec3_mul(up, STEP));
		else if (key == D)
			data->cam.cord = vec3_sub(data->cam.cord, vec3_mul(up, STEP));
		else if (key == S)
			data->cam.cord = vec3_sub(data->cam.cord, vec3_mul(right, STEP));
		else if (key == F)
			data->cam.cord = vec3_add(data->cam.cord, vec3_mul(right, STEP));
	}
	calc_pixel(&data->obj_head, &data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

void	ins_vec3_dbl(t_cord *step, double x, double y, double z)
{
	step->x = x;
	step->y = y;
	step->z = z;
}

void	move_cam_aim(int key, t_data *data)
{
	if (key == I)
		data->cam.ori.y += TILT;
	else if (key == K)
		data->cam.ori.y -= TILT;
	else if (key == J)
		data->cam.ori.x += TILT;
	else if (key == L)
		data->cam.ori.x -= TILT;
	data->cam.ori = vec3_normalise(data->cam.ori);
	calc_pixel(&data->obj_head, &data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

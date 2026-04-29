/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:17:44 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/29 21:29:08 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


// // cylinder: |((P - C) X N)|^2 = r^2
// double	calc_intersect_cy(t_ray *ray, t_obj *obj)
// {
// 	double	res1;
// 	double	final;
// 	t_cord	top;
// 	t_cord	bot;

// 	final = DBL_MAX;
// 	top = vec3_add(obj->cord, vec3_mul(obj->ori, obj->higt / 2.0));
// 	bot = vec3_sub(obj->cord, vec3_mul(obj->ori, obj->higt / 2.0));
// 	res1 = calc_intersect_cy_tube(ray, obj);
// 	if (res1 > 0)
// 	{
// 		final = res1;
// 		obj->lhit = TUBE;
// 	}
// 	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, top, obj->ori);
// 	if (res1 > 0 && calc_intersect_cy_plin(res1, top, ray, obj) == 1)
// 		final = ft_min_dbl(final, res1);
// 	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, bot, obj->ori);
// 	if (res1 > 0 && calc_intersect_cy_plin(res1, bot, ray, obj) == 1)
// 		final = ft_min_dbl(final, res1);
// 	if (final == DBL_MAX)
// 		return (-1);
// 	return (final);
// }






// t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
// {
// 	t_rgb	ambi;
// 	t_rgb	light;
// 	t_ray	shadow;
// 	t_cord	p;
// 	t_cord	sur_vec;
// 	t_cord	s2l_vec;

// 	initialise_t_rgb(&light);
// 	if (!ray || !cur || !obj || !data)
// 		return (light);
// 	//ambient light
// 	// light.r = data->ambi.ratio * data->ambi.rgb.r;
// 	// light.g = data->ambi.ratio * data->ambi.rgb.g;
// 	// light.b = data->ambi.ratio * data->ambi.rgb.b;
// 	ambi = rgb_amp_capped(data->ambi.rgb, data->ambi.ratio);
// 	//surface normal
// 	p = calc_point(ray);
// 	// sur_vec = vec3_sub(p, obj->cord);
// 	// sur_vec = vec3_normalise(sur_vec);
// 	sur_vec = calc_surface_normal(p, cur);
// 	//vector: surface to light
// 	s2l_vec = vec3_sub(data->ligt.cord, p);
// 	s2l_vec = vec3_normalise(s2l_vec);
// 	//hard shadows
// 	initialise_t_ray(&shadow);
// 	shadow.cord = vec3_sub(p, vec3_mul(sur_vec, EPSILON));
// 	shadow.ori = s2l_vec;
// 	calc_pixel_frt(&shadow, obj);
// 	double	factor;
// 	factor = vec3_dot(sur_vec, s2l_vec);
// 	if (shadow.t <= EPSILON || (shadow.t + EPSILON) * (shadow.t + EPSILON) >= vec3_dot(vec3_sub(p, data->ligt.cord), vec3_sub(p, data->ligt.cord)))
// 	{
// 		//add diffuse light
// 		light = rgb_amp_capped(data->ligt.rgb, data->ligt.bright);
// 		light = rgb_mix(cur->rgb, light);
// 		factor = ft_max_dbl(0, factor);
// 		light = rgb_amp_capped(light, factor);
// 		light = rgb3_add(ambi, light);
// 		rgb_amp_capped(light, -1);
// 		return (light);
// 	}
// 	return (ambi);
// }





// t_cord	calc_surface_normal(t_cord p, t_obj *cur)
// {
// 	t_cord	res;
// 	double	m;
// 	t_cord	new_center;

// 	initialise_t_cord(&res);
// 	if		(cur->type == SP)
// 		res = vec3_sub(p, cur->cord);
// 	else if (cur->type == PL)
// 		res = cur->ori;
// 	else if (cur->type == CY)
// 	{
// 		m = calc_surface_normal_cy_distance(p, cur);
// 		if (-cur->higt / 2 < m && m < cur->higt / 2)
// 		{
// 			new_center = vec3_mul(cur->ori, m);
// 			new_center = vec3_add(new_center, cur->cord);
// 			res = vec3_sub(p, new_center);
// 		}
// 		else if (m < 0)
// 			res = vec3_mul(cur->ori, -1);
// 		else
// 			res = cur->ori;
// 	}
// 	res = vec3_normalise(res);
// 	return (res);
// }










#define	ESC 65307
#define	E 101
#define	S 115
#define	D 100
#define	F 102
#define	T 116
#define	G 103
#define	I 105
#define	J 106
#define	K 107
#define	L 108
#define	STEP 5
#define	TILT 0.1



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
		data->cam.cord = vec3_add(data->cam.cord, vec3_mul(data->cam.ori, STEP));
	else if (key == G)
		data->cam.cord = vec3_sub(data->cam.cord, vec3_mul(data->cam.ori, STEP));
	else
	{
		up = vec3_normalise(calc_vector_up(data->cam.ori));
		right = vec3_cross(data->cam.ori, up);
		right = vec3_normalise(right);
		if		(key == E)
			data->cam.cord = vec3_add(data->cam.cord, vec3_mul(up, STEP));
		else if	(key == D)
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
	if		(key == I)
		data->cam.ori.y += TILT;
	else if	(key == K)
		data->cam.ori.y -= TILT;
	else if (key == J)
		data->cam.ori.x += TILT;
	else if (key == L)
		data->cam.ori.x -= TILT;
	data->cam.ori = vec3_normalise(data->cam.ori);
	calc_pixel(&data->obj_head, &data);
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}

#include <stdio.h>
void	ft_print_t_cord(t_cord cord)
{
	//change printf
	// printf("%lf", cord.x);
	// ft_putstr(", ");
	// printf("%lf", cord.y);
	// ft_putstr(", ");
	// printf("%lf", cord.z);
	printf("% lf, % lf, % lf; ", cord.x, cord.y, cord.z);
	fflush(stdout);
}

// sudo showkey -a
// linux: ESC == 65307;
// linux: e == 101; s == 115; d == 100; f == 102;
int	handle_keypress(int key, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	if (key == ESC)
		return (free_rt(&data->obj_head, &data), exit(0), 0);
	if (key == T || key == G || key == E || key == S || key == D || key == F)
	{
		move_cam_strafe(key, data);
	}
	else if (key == I || key == J || key == K || key == L)
	{
		move_cam_aim(key, data);
	}
	else
		return (0);
	ft_putstr("Camera coord: ");
	ft_print_t_cord(data->cam.cord);
	ft_putstr("Camera angle: ");
	ft_print_t_cord(data->cam.ori);
	ft_putstr("\n");
	return (0);
}



int	main(int argc, char **argv)
{
	t_obj	*obj;
	t_data	*data;

	if (argc != 2)
		return (ft_puterr("invalid number of arg"), 1);
	if (check_str_end(argv[1], ".rt") != TRUE)
		return (ft_puterr("invalid extension"), 2);
	obj = NULL;
	data = NULL;
	if (initialise_structs(&obj, &data) != 0)
		return (free_rt(&obj, &data), 3);
	if (initialise_rt(argv[1], &obj, &data) != 0)
		return (free_rt(&obj, &data), 4);
	if (initialise_minilibx(&data) != 0)
		return (free_rt(&obj, &data), 5);
	if (calc_pixel(&obj, &data) != 0)
		return (free_rt(&obj, &data), 6);
	if (add_event_hook(data) != 0)
		return (free_rt(&obj, &data), 7);
	if (run_window_loop(data) != 0)
		return (free_rt(&obj, &data), 8);
	return (free_rt(&obj, &data), 0);
}

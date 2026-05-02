/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:17:44 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/29 21:43:43 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	printf("initialise_structs complete\n"); //
	if (initialise_rt(argv[1], &obj, &data) != 0)
		return (free_rt(&obj, &data), 4);
	printf("initialise_rt complete\n"); //
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
// 	if (shadow.t <= EPSILON ||
// 		(shadow.t + EPSILON) * (shadow.t + EPSILON) >=
// 		vec3_dot(vec3_sub(p, data->ligt.cord),
// 		vec3_sub(p, data->ligt.cord)))
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
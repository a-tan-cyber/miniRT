/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 19:57:15 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 20:06:39 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	ft_degree2radian(int degree)
{
	double	res;

	res = degree * RT_PI / 180;
	return (res);
}

double	ft_normalise_x(int x, double width, double aspect, double fov)
{
	double	res;

	res = ((double)x + 0.5f) / width;
	res = res * 2.0f - 1.0f;
	res *= tan(fov / 2.0f);
	res *= aspect;
	return (res);
}

double	ft_normalise_y(int y, double height, double fov)
{
	double	res;

	res = ((double)y + 0.5f) / height;
	res = 1.0f - (2.0f * res);
	res *= tan(fov / 2.0f);
	return (res);
}

void	calc_orientation(double xf, double yf, t_cord ori, t_ray *ray)
{
	t_cord	f;
	t_cord	r;
	t_cord	up;

	f = vec3_normalise(ori);
	initialise_t_cord(&up);
	if (f.x == 0.0f && (f.y == 1.0f || f.y == -1.0f) && f.z == 0.0f)
		up.z = -1.0f;
	else
		up.y = 1.0f;
	r = vec3_cross(f, up);
	up = vec3_cross(r, f);
	ray->ori.x = (xf * r.x) + (yf * up.x) + (1.0f * f.x);
	ray->ori.y = (xf * r.y) + (yf * up.y) + (1.0f * f.y);
	ray->ori.z = (xf * r.z) + (yf * up.z) + (1.0f * f.z);
	ray->ori = vec3_normalise(ray->ori);
}

void	calc_ray_screen2obj(t_ray *ray, int x, int y, t_data *data)
{
	double	aspect_ratio;
	double	fov;
	double	xf;
	double	yf;

	aspect_ratio = (float)WIDTH / (float)HEIGHT;
	fov = ft_degree2radian(data->cam.fov);
	xf = ft_normalise_x(x, WIDTH, aspect_ratio, fov);
	yf = ft_normalise_y(y, HEIGHT, fov);
	calc_orientation(xf, yf, data->cam.ori, ray);
	ray->cord = data->cam.cord;
}

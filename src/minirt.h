/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:41:51 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/29 20:08:39 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define _USE_MATH_DEFINES
# include <math.h>
# include <float.h>

# define EPSILON 1e-8
# define RT_PI 3.14159265358979323846
# define WIDTH	1024
# define HEIGHT	1024

# include "../libft/include/libft.h"
# include "../minilibx-linux/mlx.h"
# include "minirt_struct.h"

void	initialise_t_obj(t_obj **obj);
void	initialise_t_cord(t_cord *cord);
void	initialise_t_rgb(t_rgb *rgb);
void	initialise_t_data(t_data *cur_data);
int		initialise_structs(t_obj **obj, t_data **data);

double	vec3_dot(t_cord c1, t_cord c2);
t_cord	vec3_cross(t_cord f, t_cord up);
t_cord	vec3_normalise(t_cord ori);
t_cord	vec3_sub(t_cord c1, t_cord c2);
t_cord	vec3_mul(t_cord x, double times);
t_cord	vec3_add(t_cord x, t_cord y);
double	vec3_len_sq(t_cord p, t_cord cord);

double	ft_degree2radian(int degree);
double	ft_normalise_x(int x, double width, double aspect, double fov);
double	ft_normalise_y(int y, double height, double fov);
void	calc_orientation(double xf, double yf, t_cord ori, t_ray *ray);
void	calc_ray_screen2obj(t_ray *ray, int x, int y, t_data *data);
void	initialise_t_ray(t_ray *ray);

float	ft_atof(const char *s);
double	ft_atod(const char *s);
int		ft_is_digit(char c);
int		ft_skip_space(const char *s, int i);
double	ft_read_frac(const char *s, int *i);
int		ft_read_exp(const char *s, int *i, int *exp, int *exp_sign);

#endif

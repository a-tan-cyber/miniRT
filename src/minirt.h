/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 17:41:51 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/29 21:04:27 by amtan            ###   ########.fr       */
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
# define BITS_PER_BYTE 8
# define RGB_BUFFER 8

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

int		initialise_minilibx(t_data **data);
void	free_t_obj_all(t_obj *head);
void	free_t_data(t_data *data);
void	free_rt(t_obj **obj, t_data **data);
int		redx(void *param);
int		redraw_window(void *param);
int		add_event_hook(t_data *data);
int		run_window_loop(t_data *data);

double	ft_discriminant(double a, double b, double c);
double	ft_solve_quadratic_abd_near(double a, double b, double delta);
double	ft_solve_quadratic_abd_far(double a, double b, double delta);
double	calc_intersect_sp(t_ray *ray, t_obj *obj);
double	calc_intersect_pl(t_ray *ray, t_obj *obj);

double	calc_intersect_cy_tube_height(double t, t_calc calc);
void	initialise_t_calc(t_calc *calc);
t_calc	calc_intersect_cy_tube_dis(t_ray *ray, t_obj *obj);
double	calc_intersect_cy_tube(t_ray *ray, t_obj *obj);
double	calc_intersect_pl_hlp(t_cord rayori, t_cord raydir,
			t_cord center, t_cord ori);
double	ft_min_dbl(double f1, double f2);
int		calc_intersect_cy_plin(double t, t_cord top,
			t_ray *ray, t_obj *obj);
double	calc_intersect_cy_plin_lhit(double final, double res,
			t_obj *cur, t_lhit lhit);
double	calc_intersect_cy(t_ray *ray, t_obj *obj);
double	calc_ray_t(t_ray *ray, t_obj *obj);
t_obj	*calc_pixel_frt_s(t_ray *ray, t_obj *frt, t_obj *obj);
t_obj	*calc_pixel_frt(t_ray *ray, t_obj *obj);

t_rgb	rgb_amp_capped(t_rgb rgb, double ratio);
t_rgb	rgb_add(t_rgb l1, t_rgb l2);
t_rgb	rgb_mul(t_rgb l1, t_rgb l2, int bound);
t_rgb	calc_pixel_l_diffused(double factor, t_obj *cur, t_data *data);
int		conv_rgb2str(char *dest, t_rgb rgb, t_data *data);
t_cord	calc_point(t_ray *ray);
double	calc_surface_normal_cy_distance(t_cord p, t_obj *cur);
t_cord	calc_surface_normal(t_cord p, t_obj *cur);
double	calc_pixel_l_sdwvslit(t_ray *ray, t_obj *cur, t_obj *obj,
			t_data *data);
t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data);
int		calc_pixel_a(int y, int x, t_rgb rgb, t_data *data);
int		calc_pixel(t_obj **obj, t_data **data);

int		handle_keypress(int key, void *param);

float	ft_atof(const char *s);
double	ft_atod(const char *s);
int		ft_is_digit(char c);
int		ft_skip_space(const char *s, int i);
double	ft_read_frac(const char *s, int *i);
int		ft_read_exp(const char *s, int *i, int *exp, int *exp_sign);

#endif

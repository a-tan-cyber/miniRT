/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:17:44 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/03 17:17:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ft_str_is_float(const char *s);
float	ft_atof(const char *s);

// if s1 is smaller than min or bigger than max, then return 0
int	validate_str_int_range(const char *s1, const char *min, const char *max)
{
	if (!ft_str_is_int(s1) || !ft_str_is_int(min) || !ft_str_is_int(max))
		return (ft_puterr("val is not an int"), 0);
	if (ft_str_numcmp(min, max) == 1)
		return (ft_puterr("int min is greater than max"), 0);
	if (ft_str_numcmp(s1, min) == -1)
		return (ft_puterr("int val is too small"), 0);
	if (ft_str_numcmp(s1, max) == 1)
		return (ft_puterr("int val is too large"), 0);
	return (1);
}

int	validate_str_float_range(const char *s, float min, float max)
{
	float	target;

	if (!s)
		return (ft_puterr("missing float val"), 0);
	if (min > max)
		return (ft_puterr("float min > max"), 0);
	if (!ft_str_is_float(s))
		return (ft_puterr("val is not a float"), 0);
	target = ft_atof(s);
	if (target < min)
		return (ft_puterr("float val too small"), 0);
	if (target > max)
		return (ft_puterr("float val too large"), 0);
	return (1);
}

int	add_rt_data_d_a(const char **split_arr, t_data **data)
{
	char	**arr;

	if (ft_arrlen(split_arr) != 3)
		return (-1);
	if (ft_str_is_float(split_arr[1]) == FALSE)
		return (ft_puterr("data.ambi ratio is not float"), 1);
	(*data)->ambi.ratio = ft_atof(split_arr[1]);
	if ((*data)->ambi.ratio > 1.0 || (*data)->ambi.ratio < 0.0)
		return (ft_puterr("data.ambi value is out of range"), -2);
	arr = ft_split(split_arr[2], ",");
	if (!arr)
		return (ft_puterr("malloc failed (data.ambi.rgb)"), 2);
	if (ft_arrlen(arr) != 3)
		return (ft_puterr("data.ambi wrong no. of rgb val"), free_arr(arr), 3);
	if (validate_str_int_range(arr[0], "0", "255") == FALSE)
		return (ft_puterr("data.ambi r value invalid"), free_arr(arr), 4);
	(*data)->ambi.rgb.r = ft_atoi(arr[0]);
	if (validate_str_int_range(arr[1], "0", "255") == FALSE)
		return (ft_puterr("data.ambi g value invalid"), free_arr(arr), 5);
	(*data)->ambi.rgb.g = ft_atoi(arr[1]);
	if (validate_str_int_range(arr[2], "0", "255") == FALSE)
		return (ft_puterr("data.ambi b value invalid"), free_arr(arr), 6);
	(*data)->ambi.rgb.b = ft_atoi(arr[2]);
	return (free_arr(arr), 0);
}

char	**split_3_float(const char *string, const char *charset)
{
	char	**arr;

	if (!string || !charset)
		return (NULL);
	arr = ft_split(string, charset);
	if (!arr)
		return (ft_puterr("malloc failed"), NULL);
	if (ft_arrlen(arr) != 3)
		return (ft_puterr("wrong no. of vector"), free_arr(arr), NULL);
	if (!ft_str_is_float(arr[0]) || !ft_str_is_float(arr[1])
		|| !ft_str_is_float(arr[2]))
		return (ft_puterr("vector or ori is not float"), free_arr(arr), NULL);
	return (arr);
}

char	**split_3_float_range(const char *string, const char *charset,
			float min, float max)
{
	char	**arr;
	float	curr;

	arr = split_3_float(string, charset);
	if (!arr)
		return (NULL);
	curr = ft_atof(arr[0]);
	if (curr < min || max < curr)
		return (ft_puterr("float number x out of range"), free_arr(arr), NULL);
	curr = ft_atof(arr[1]);
	if (curr < min || max < curr)
		return (ft_puterr("float number y out of range"), free_arr(arr), NULL);
	curr = ft_atof(arr[2]);
	if (curr < min || max < curr)
		return (ft_puterr("float number z out of range"), free_arr(arr), NULL);
	return (arr);
}

int	ins_vec3(t_cord *cord, const char *x, const char *y, const char *z)
{
	if (!cord)
		return (ft_puterr("ins_vec3 cord value is NULL"), -1);
	if (!ft_str_is_float(x) || !ft_str_is_float(y) || !ft_str_is_float(z))
		return (ft_puterr("ensure string is float before insertion"), 1);
	cord->x = ft_atof(x);
	cord->y = ft_atof(y);
	cord->z = ft_atof(z);
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
		return (-1);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("data.cam.cord error"), 2);
	if (ins_vec3(&cam->cord, arr[0], arr[1], arr[2]) != 0)
		return (free_arr(arr), -1);
	free_arr(arr);
	arr = split_3_float_range(split_arr[2], ",", -1, 1);
	if (!arr)
		return (ft_puterr("data.cam.ori error"), 3);
	if (ins_vec3(&cam->ori, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -2);;
	free_arr(arr);
	if (validate_str_int_range(split_arr[3], "0", "180") == FALSE)
		return (ft_puterr("data.cam FOV val invalid"), 4);
	cam->fov = ft_atoi(split_arr[3]);
	return (0);
}

char	**split_3_int(const char *string, const char *charset)
{
	char	**arr;

	if (!string || !charset)
		return (NULL);
	arr = ft_split(string, charset);
	if (!arr)
		return (ft_puterr("malloc failed"), NULL);
	if (ft_arrlen(arr) != 3)
		return (ft_puterr("wrong no. of int (rgb)"), free_arr(arr), NULL);
	if (!ft_str_is_int(arr[0]) || !ft_str_is_int(arr[1])
		|| !ft_str_is_int(arr[2]))
		return (ft_puterr("rgb is not int"), free_arr(arr), NULL);
	return (arr);
}

char	**split_3_int_range(const char *string, const char *charset,
			const char *min_str, const char *max_str)
{
	char	**arr;
	int		curr;
	int		min;
	int		max;

	arr = split_3_int(string, charset);
	if (!arr)
		return (NULL);
	min = ft_atoi(min_str);
	max = ft_atoi(max_str);
	curr = ft_atoi(arr[0]);
	if (curr < min || max < curr)
		return (ft_puterr("int number r out of range"), free_arr(arr), NULL);
	curr = ft_atof(arr[1]);
	if (curr < min || max < curr)
		return (ft_puterr("int number g out of range"), free_arr(arr), NULL);
	curr = ft_atof(arr[2]);
	if (curr < min || max < curr)
		return (ft_puterr("int number b out of range"), free_arr(arr), NULL);
	return (arr);
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
		return (-1);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("data.ligt.cord error"), 2);
	if (ins_vec3(&ligt->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -2);
	free_arr(arr);
	if (validate_str_float_range(split_arr[2], 0, 1) == 0)
		return (ft_puterr("data.ligt.bright error"), 3);
	ligt->bright = ft_atof(split_arr[2]);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("data.ligt.rgb error"), 4);
	if (ins_rgb(&ligt->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	return (0);
}

int	add_rt_data_d(const char **split_arr, t_data **data)
{
	int	err;

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
		err = add_rt_data_d_c(split_arr, (*data)->cam);
	}
	else if (ft_strcmp(split_arr[0], "L") == 0)
	{
		if ((*data)->ligt_loaded == TRUE)
			return (ft_puterr("duplicate light setting"), -13);
		(*data)->ligt_loaded = TRUE;
		err = add_rt_data_d_l(split_arr, (*data)->ligt);
	}
	return (err);
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

	if (ft_arrlen(split_arr) != 4)
		return (-2);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	if (ft_atof(split_arr[2]) <= 0)
		return (ft_puterr("obj.dia error"), 3);
	new->dia = ft_atof(split_arr[2]);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("obj.rgb error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	return (free_arr(arr), 0);
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

	if (ft_arrlen(split_arr) != 4)
		return (-2);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_float_range(split_arr[2], ",", -1, 1);
	if (!arr)
		return (ft_puterr("obj.ori error"), 2);
	if (ins_vec3(&new->ori, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("obj.rgb error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	return (free_arr(arr), 0);
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

	if (ft_arrlen(split_arr) != 6)
		return (-2);
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("cylinder obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_float_range(split_arr[2], ",", -1, 1);
	if (!arr)
		return (ft_puterr("cylinder obj.ori error"), 2);
	if (ins_vec3(&new->ori, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	if (ft_atof(split_arr[3]) <= 0 || ft_atof(split_arr[4]) <= 0)
		return (ft_puterr("cylinder diameter <= 0 or height <= 0"), 3);
	new->dia = ft_atof(split_arr[3]);
	new->higt = ft_atof(split_arr[4]);
	if (val_ins_rgb(split_arr[5], new) != 0)
		return (ft_puterr("add_rt_data_s_cy: cylinder failed to ins rgb"), 4);
	return (0);
}

int	add_rt_data_s(const char **split_arr, t_obj **obj)
{
	int		err;
	t_obj	*new;

	new = cre_t_obj_next(go_t_obj_last(*obj));
	if (!new)
		return (ft_puterr("add_rt_data_s: failed to create new"), -1);
	err = 0;
	if (ft_strcmp(split_arr[0], "sp") == 0)
		err = add_rt_data_s_sp(split_arr, new);
	else if (ft_strcmp(split_arr[0], "pl") == 0)
		err = add_rt_data_s_pl(split_arr, new);
	else if (ft_strcmp(split_arr[0], "cy") == 0)
		err = add_rt_data_s_cy(split_arr, new);
	else
		return (ft_puterr("invalid shape identifier"), -11);
	return (err);
}

int	add_rt_data(const char *trimmed, t_obj **obj, t_data **data)
{
	char	**split_arr;
	char	*curr;

	split_arr = ft_split(trimmed, " ");
	if (!split_arr || !split_arr[0])
		return (-1);
	curr = split_arr[0];
	if (!ft_strcmp(curr, "A") || !ft_strcmp(curr, "C") || !ft_strcmp(curr, "L"))
	{
		if (add_rt_data_d(split_arr, data) != 0)
			return (free_arr(split_arr), 1);
	}
	else if (!ft_strcmp(curr, "sp") || !ft_strcmp(curr, "pl")
		|| !ft_strcmp(curr, "cy"))
	{
		if (add_rt_data_s(split_arr, obj) != 0)
			return (free_arr(split_arr), 2);
	}
	else
		return (ft_puterr("invalid data identifier: "), ft_puterr(split_arr[0]),
			free_arr(split_arr), -2);
	return (free_arr(split_arr), 0);
}

int	initialise_rt(const char *str, t_obj **obj, t_data **data)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, " \n");
		ft_sfree(&line);
		if (ft_strcmp(trimmed, "") != 0)
		{
			if (add_rt_data(trimmed, obj, data) != 0)
				return (ft_sfree(&trimmed), close(fd), get_next_line(-69), 2);
		}
		ft_sfree(&trimmed);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
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

void	initialise_t_obj(t_obj **obj)
{
	t_obj	*cur_obj;

	cur_obj->type = -1;
	initialise_t_cord(&cur_obj->cord);
	cur_obj->dia = 0;
	initialise_t_cord(&cur_obj->ori);
	cur_obj->higt = 0;
	initialise_t_rgb(&cur_obj->rgb);
	cur_obj->id	= -1;
	cur_obj->next = NULL;
	cur_obj->data = data;
}

void	initialise_t_data(t_data **data)
{
	t_data	*cur_data;

	cur_data = *data;
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
}

void	initialise_structs(t_obj **obj, t_data **data)
{
	void(obj);
	initialise_t_data(data);
}

#define WIDTH	256
#define HEIGHT	256

int	initialise_minilibx(t_data **data)
{
	t_data	*curr;

	curr = *data;
	curr->mlx = mlx_init();
	curr->win = mlx_new_window(curr->mlx, WIDTH, HEIGHT, "miniRT");
	curr->img = mlx_new_image(curr->mlx, WIDTH, HEIGHT);
	curr->addr = mlx_get_data_addr(curr->img, &curr->bits_p_pixel,
				&curr->size_line, &curr->endian);
	return (0);
}

float	ft_degree2radian(int degree)
{
	float	res;

	res = degree * M_PI / 180;
	return (res);
}

float	ft_normalise_x(int x, float width, float aspect, float fov)
{
	float	res;

	res = ((float)x + 0.5f) / width;
	res = res * 2.0f - 1.0f;
	res *= tan(fov / 2.0f);
	res *= aspect;
	return (res);
}

float	ft_normalise_y(int y, float height, float fov)
{
	float	res;

	res = ((float)y + 0.5f) / height;
	res = 1.0f - (2.0f * res);
	res *= tan(fov / 2.0f);
	return (res);
}


// r = vec3_cross(f, up);
// f = vec3_normalise(ori);

void	calc_orientation(float xf, float yf, t_cord ori, t_ray *ray)
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
	float	aspect_ratio;
	float	fov;
	float	xf;
	float	yf;
	
	aspect_ratio = (float)WIDTH / (float)HEIGHT;
	fov = ft_degree2radian(data->cam.fov);
	xf = ft_normalise_x(x, WIDTH, aspect_ratio, fov);
	yf = ft_normalise_y(y, HEIGHT, fov);
	calc_orientation(xf, yf, data->cam.ori, ray);
}

t_obj	*calc_pixel_frt(int x, int y, t_obj *obj, t_data *data)
{
	t_obj	*frt;
	t_ray	cur;

	if (x < 0 || y < 0 || !obj || !data)
		return (NULL);
	cur.t = -1.0f;
	initialise_t_cord(&cur.cord);
	initialise_t_cord(&cur.ori);
	calc_ray_screen2obj(&cur, x, y, data);
	frt = NULL;
	while (obj != NULL)
	{
		frt = calc_pixel_frt_s(&cur, frt, obj, data);
		obj = obj->next;
	}
	return (frt);
}

int	calc_pixel_shape(x, y, cur, *data)
{

}

int	calc_pixel(t_obj **obj, t_data **data)
{
	t_obj	*frt;
	int		x;
	int		y;

	frt = NULL;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			frt = calc_pixel_frt(x, y, *obj, *data);
			if (calc_pixel_shape(x, y, frt, *data) != 0)
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}


// if (add_event_hook(&data) != 0)
// 	return (6);
// if (run_window_loop(&obj, &data) != 0)
// 	return (7);
// return (free_rt(&obj, &data), 0);

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
	initialise_structs(&obj, &data);
	if (initialise_rt(argv[1], &obj, &data) != 0)
		return (free_rt(&obj, &data), 3);
	if (initialise_minilibx(&data) != 0)
		return (free_rt(&obj, &data), 4);
	if (calc_pixel(&obj, &data) != 0)
		return (free_rt(&obj, &data), 5);
	if (add_event_hook(&data) != 0)
		return (free_rt(&obj, &data), 6);
	if (run_window_loop(&obj, &data) != 0)
		return (free_rt(&obj, &data), 7);
	return (free_rt(&obj, &data), 0);
}

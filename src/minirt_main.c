/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:17:44 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/29 20:28:51 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int		chk_normalised(t_cord ori);

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
		return (ft_puterr("ambient wrong number of fields"), -1);
	if (ft_str_is_float(split_arr[1]) == FALSE)
		return (ft_puterr("data.ambi ratio is not float"), 1);
	(*data)->ambi.ratio = ft_atod(split_arr[1]);
	if ((*data)->ambi.ratio > 1.0 || (*data)->ambi.ratio < 0.0)
		return (ft_puterr("data.ambi value is out of range"), -2);
	arr = ft_split(split_arr[2], ",");
	if (!arr)
		return (ft_puterr("malloc failed (data.ambi.rgb)"), 2);
	if (ft_arrlen((const char **)arr) != 3)
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
	if (ft_arrlen((const char **)arr) != 3)
		return (ft_puterr("wrong no. of vector"), free_arr(arr), NULL);
	if (!ft_str_is_float(arr[0]) || !ft_str_is_float(arr[1])
		|| !ft_str_is_float(arr[2]))
		return (ft_puterr("vector or ori is not float"), free_arr(arr), NULL);
	return (arr);
}

char	**split_3_double_range(const char *string, const char *charset,
			double min, double max)
{
	char	**arr;
	double	curr;

	arr = split_3_float(string, charset);
	if (!arr)
		return (NULL);
	curr = ft_atod(arr[0]);
	if (curr < min || max < curr)
		return (ft_puterr("double number x out of range"), free_arr(arr), NULL);
	curr = ft_atod(arr[1]);
	if (curr < min || max < curr)
		return (ft_puterr("double number y out of range"), free_arr(arr), NULL);
	curr = ft_atod(arr[2]);
	if (curr < min || max < curr)
		return (ft_puterr("double number z out of range"), free_arr(arr), NULL);
	return (arr);
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

char	**split_3_int(const char *string, const char *charset)
{
	char	**arr;

	if (!string || !charset)
		return (NULL);
	arr = ft_split(string, charset);
	if (!arr)
		return (ft_puterr("malloc failed"), NULL);
	if (ft_arrlen((const char **)arr) != 3)
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
	curr = ft_atoi(arr[1]);
	if (curr < min || max < curr)
		return (ft_puterr("int number g out of range"), free_arr(arr), NULL);
	curr = ft_atoi(arr[2]);
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
		err = add_rt_data_d_c(split_arr, &(*data)->cam);
	}
	else if (ft_strcmp(split_arr[0], "L") == 0)
	{
		if ((*data)->ligt_loaded == TRUE)
			return (ft_puterr("duplicate light setting"), -13);
		(*data)->ligt_loaded = TRUE;
		err = add_rt_data_d_l(split_arr, &(*data)->ligt);
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
		return (ft_puterr("plane wrong number of fields"), -2);
	new->type = PL;
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_double_range(split_arr[2], ",", -1, 1);
	if (!arr)
		return (ft_puterr("obj.ori error"), 2);
	if (ins_vec3(&new->ori, arr[0], arr[1], arr[2])
		|| chk_normalised(new->ori))
		return (ft_puterr("obj.ori error"), free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_int_range(split_arr[3], ",", "0", "255");
	if (!arr)
		return (ft_puterr("obj.rgb error"), 4);
	if (ins_rgb(&new->rgb, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -4);
	new->plane_constant = vec3_dot(new->cord, new->ori);
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

int	chk_normalised(t_cord ori)
{
	double	normal;

	normal = ori.x * ori.x + ori.y * ori.y + ori.z * ori.z;
	if (fabs(normal - 1.0) < EPSILON)
		return (0);
	ft_puterr("ori not normalised");
	return (1);
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
		return (ft_puterr("cylinder wrong number of fields"), -2);
	new->type = CY;
	arr = split_3_float(split_arr[1], ",");
	if (!arr)
		return (ft_puterr("cylinder obj.cord error"), 2);
	if (ins_vec3(&new->cord, arr[0], arr[1], arr[2]))
		return (free_arr(arr), -3);
	free_arr(arr);
	arr = split_3_double_range(split_arr[2], ",", -1, 1);
	if (!arr)
		return (ft_puterr("cylinder obj.ori error"), 2);
	if (ins_vec3(&new->ori, arr[0], arr[1], arr[2]) || chk_normalised(new->ori))
		return (ft_puterr("cylinder obj.ori error"), free_arr(arr), -3);
	free_arr(arr);
	if (ft_atof(split_arr[3]) <= 0 || ft_atof(split_arr[4]) <= 0)
		return (ft_puterr("cylinder diameter <= 0 or height <= 0"), 3);
	new->dia = ft_atod(split_arr[3]);
	new->higt = ft_atod(split_arr[4]);
	if (val_ins_rgb(split_arr[5], new) != 0)
		return (ft_puterr("add_rt_data_s_cy: cylinder failed to ins rgb"), 4);
	return (0);
}

t_obj *go_t_obj_last(t_obj *obj)
{
	t_obj	*cur;

	cur = obj;
	while (obj)
	{
		cur = obj;
		obj = obj->next;
	}
	return (cur);
}

t_obj	*cre_t_obj_new(void)
{
	t_obj	*new;

	new = malloc(sizeof(t_obj));
	if (!new)
		return (NULL);
	initialise_t_obj(&new);
	return (new);
}

t_obj	*cre_t_obj_next(t_obj *obj)
{
	t_obj	*new;
	
	new = cre_t_obj_new();
	if (!new)
		return (NULL);
	if (!obj)
		return (new);
	obj->next = new;
	return (new);
}

int	add_rt_data_s(const char **split_arr, t_obj **obj, t_data **data)
{
	int		err;
	t_obj	*new;

	new = cre_t_obj_next(go_t_obj_last(*obj));
	if (!new)
		return (ft_puterr("add_rt_data_s: failed to create new"), -1);
	if (!*obj)
	{
		*obj = new;
		(*data)->obj_head = new;
	}
	err = 0;
	if		(ft_strcmp(split_arr[0], "sp") == 0)
		err = add_rt_data_s_sp(split_arr, new);
	else if (ft_strcmp(split_arr[0], "pl") == 0)
		err = add_rt_data_s_pl(split_arr, new);
	else if (ft_strcmp(split_arr[0], "cy") == 0)
		err = add_rt_data_s_cy(split_arr, new);
	else
		return (ft_puterr("invalid shape identifier"), ft_sfree((void **)&new), -11);
	return (err);
}

int	add_rt_data(const char *trimmed, t_obj **obj, t_data **data)
{
	char	**split_arr;
	char	*curr;

	split_arr = ft_split(trimmed, " \t");
	if (!split_arr || !split_arr[0])
		return (free_arr(split_arr), -1);
	curr = split_arr[0];
	if (!ft_strcmp(curr, "A") || !ft_strcmp(curr, "C") || !ft_strcmp(curr, "L"))
	{
		if (add_rt_data_d((const char **)split_arr, data) != 0)
			return (free_arr(split_arr), 1);
	}
	else if (!ft_strcmp(curr, "sp") || !ft_strcmp(curr, "pl")
		|| !ft_strcmp(curr, "cy"))
	{
		if (add_rt_data_s((const char **)split_arr, obj, data) != 0)
			return (free_arr(split_arr), 2);
	}
	else
		return (ft_puterr("invalid data identifier: "), ft_puterr(split_arr[0]),
			free_arr(split_arr), -2);
	return (free_arr(split_arr), 0);
}

int	validate_required_data(t_data *data)
{
	if (!data)
		return (ft_puterr("missing scene data"), 1);
	if (data->ambi_loaded == FALSE)
		return (ft_puterr("missing ambient lighting"), 2);
	if (data->cam_loaded == FALSE)
		return (ft_puterr("missing camera"), 3);
	if (data->ligt_loaded == FALSE)
		return (ft_puterr("missing light"), 4);
	return (0);
}

int	initialise_rt(const char *str, t_obj **obj, t_data **data)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_puterr("cannot open scene file"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, " \n");
		ft_sfree((void **)&line);
		if (ft_strcmp(trimmed, "") != 0)
		{
			if (add_rt_data(trimmed, obj, data) != 0)
				return (ft_sfree((void **)&trimmed), close(fd), get_next_line(-69), 2);
		}
		ft_sfree((void **)&trimmed);
		line = get_next_line(fd);
	}
	close(fd);
	if (validate_required_data(*data) != 0)
		return (3);
	return (0);
}

// m = (P - C) dot N
double	calc_intersect_cy_tube_height(double t, t_calc calc)
{
	double	m;
	
	m = calc.sto2 + t * calc.sto1;
	return (m);
}

void	initialise_t_calc(t_calc *calc)
{
	calc->a = 0;
	calc->b = 0;
	calc->c = 0;
	calc->sto1 = 0;
	calc->sto2 = 0;
	calc->delta = 0;
	initialise_t_cord(&calc->x);
}

t_calc	calc_intersect_cy_tube_dis(t_ray *ray, t_obj *obj)
{
	t_calc	calc;
	double	r;

	initialise_t_calc(&calc);
	calc.x = vec3_sub(ray->cord, obj->cord);
	r = obj->dia / 2;
	calc.a = vec3_dot(ray->ori, obj->ori);
	calc.sto1 = calc.a;
	calc.a = vec3_dot(ray->ori, ray->ori) - (calc.a * calc.a);
	calc.b = 2 * (vec3_dot(calc.x, ray->ori) - vec3_dot(obj->ori, calc.x)
					* vec3_dot(ray->ori, obj->ori));
	calc.c = vec3_dot(obj->ori, calc.x);
	calc.sto2 = calc.c;
	calc.c = vec3_dot(calc.x, calc.x) - (calc.c * calc.c) - (r * r);
	calc.delta = ft_discriminant(calc.a, calc.b, calc.c);
	return (calc);
}

double	calc_intersect_cy_tube(t_ray *ray, t_obj *obj)
{
	t_calc	calc;
	double	t;
	double	m;

	calc = calc_intersect_cy_tube_dis(ray, obj);
	if (calc.delta < EPSILON)
		return (-1);
	t = ft_solve_quadratic_abd_near(calc.a, calc.b, calc.delta);
	m = calc_intersect_cy_tube_height(t, calc);
	if (m > -obj->higt / 2.0 && m < obj->higt / 2.0)
		return (t);
	t = ft_solve_quadratic_abd_far(calc.a, calc.b, calc.delta);
	m = calc_intersect_cy_tube_height(t, calc);
	if (m > -obj->higt / 2.0 && m < obj->higt / 2.0)
		return (t);
	return (-1);
}

double	calc_intersect_pl_hlp(t_cord rayori, t_cord raydir, t_cord center,
		t_cord normal)
{
	double	a;
	double	t;

	a = vec3_dot(raydir, normal);
	if (-EPSILON < a && a < EPSILON)
		return (-1);
	t = vec3_dot(center, normal) - vec3_dot(rayori, normal);
	t = t / a;
	if (t < EPSILON)
		return (-1);
	return (t);
}

double	ft_min_dbl(double f1, double f2)
{
	if (f1 < f2)
		return (f1);
	return (f2);
}

int	calc_intersect_cy_plin(double t, t_cord top, t_ray *ray, t_obj *obj)
{
	t_cord	p;
	t_cord	v;
	double	m;
	double	r;
	
	p = vec3_add(ray->cord, vec3_mul(ray->ori, t));
	v = vec3_sub(top, p);
	m = vec3_dot(v, v);
	r = obj->dia / 2;
	if (m <= r * r)
		return (1);
	return (0);
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

double	calc_intersect_cy_plin_lhit(double final, double res, t_obj *cur,
		t_lhit lhit)
{
	if (final < res)
		return (final);
	cur->lhit = lhit;
	return (res);
}

// cylinder: |((P - C) X N)|^2 = r^2
double	calc_intersect_cy(t_ray *ray, t_obj *obj)
{
	double	res1;
	double	final;
	t_cord	top;
	t_cord	bot;

	final = DBL_MAX;
	top = vec3_add(obj->cord, vec3_mul(obj->ori, obj->higt / 2.0));
	bot = vec3_sub(obj->cord, vec3_mul(obj->ori, obj->higt / 2.0));
	res1 = calc_intersect_cy_tube(ray, obj);
	if (res1 > 0)
	{
		final = res1;
		obj->lhit = TUBE;
	}
	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, top, obj->ori);
	if (res1 > 0 && calc_intersect_cy_plin(res1, top, ray, obj) == 1)
		final = calc_intersect_cy_plin_lhit(final, res1, obj, FLAT_TOP);
	res1 = calc_intersect_pl_hlp(ray->cord, ray->ori, bot, obj->ori);
	if (res1 > 0 && calc_intersect_cy_plin(res1, bot, ray, obj) == 1)
		final = calc_intersect_cy_plin_lhit(final, res1, obj, FLAT_BOT);
	if (final == DBL_MAX)
		return (-1);
	return (final);
}

double	calc_ray_t(t_ray *ray, t_obj *obj)
{
	double	res;

	res = -1.0;
	if (obj->type == SP)
	{
		res = calc_intersect_sp(ray, obj);
	}
	else if (obj->type == PL)
	{
		res = calc_intersect_pl(ray, obj);
	}
	else if (obj->type == CY)
	{
		res = calc_intersect_cy(ray, obj);
	}
	return (res);
}


t_obj	*calc_pixel_frt_s(t_ray *ray, t_obj *frt, t_obj *obj)
{
	double	near;
	double	curr;

	if (frt == NULL)
	{
		curr = calc_ray_t(ray, obj);
		if (curr <= EPSILON)
			return (NULL);
		ray->t = curr;
		return (obj);
	}
	near = ray->t;
	curr = calc_ray_t(ray, obj);
	if (curr >= EPSILON && near > curr)
	{
		ray->t = curr;
		return (obj);
	}
	return (frt);
}

t_obj	*calc_pixel_frt(t_ray *ray, t_obj *obj)
{
	t_obj	*frt;

	if (!ray || !obj)
		return (NULL);
	frt = NULL;
	while (obj != NULL)
	{
		frt = calc_pixel_frt_s(ray, frt, obj);
		obj = obj->next;
	}
	return (frt);
}

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

t_rgb	rgb_amp_capped(t_rgb rgb, double ratio)
{
	rgb.r = (double)rgb.r * ratio;
	rgb.r = ft_min(rgb.r, 255);
	rgb.r = ft_max(rgb.r, 0);
	rgb.g = (double)rgb.g * ratio;
	rgb.g = ft_min(rgb.g, 255);
	rgb.g = ft_max(rgb.g, 0);
	rgb.b = (double)rgb.b * ratio;
	rgb.b = ft_min(rgb.b, 255);
	rgb.b = ft_max(rgb.b, 0);
	return (rgb);
}

t_cord	calc_point(t_ray *ray)
{
	t_cord	res;

	initialise_t_cord(&res);
	res = vec3_mul(ray->ori, ray->t);
	res = vec3_add(ray->cord, res);
	return (res);
}

double	calc_surface_normal_cy_distance(t_cord p, t_obj *cur)
{
	t_cord	vector;
	double	res;

	initialise_t_cord(&vector);
	vector = vec3_sub(p, cur->cord);
	res = vec3_dot(vector, cur->ori);
	return (res);
}

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

t_cord	calc_surface_normal(t_cord p, t_obj *cur)
{
	t_cord	res;
	double	m;
	t_cord	new_center;

	initialise_t_cord(&res);
	if		(cur->type == SP)
		res = vec3_sub(p, cur->cord);
	else if (cur->type == PL)
		res = cur->ori;
	else if (cur->type == CY)
	{
		if		(cur->lhit == FLAT_TOP)
			res = cur->ori;
		else if (cur->lhit == FLAT_BOT)
			res = vec3_mul(cur->ori, -1);
		else if (cur->lhit == TUBE)
		{
			m = calc_surface_normal_cy_distance(p, cur);
			new_center = vec3_mul(cur->ori, m);
			new_center = vec3_add(new_center, cur->cord);
			res = vec3_sub(p, new_center);
		}
	}
	res = vec3_normalise(res);
	return (res);
}

double	calc_pixel_l_sdwvslit(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
{
	t_ray	shadow;
	t_cord	p;
	t_cord	sur_vec;
	t_cord	s2l_vec;
	double	factor;

	p = calc_point(ray);
	sur_vec = calc_surface_normal(p, cur);
	s2l_vec = vec3_sub(data->ligt.cord, p);
	s2l_vec = vec3_normalise(s2l_vec);
	factor = vec3_dot(sur_vec, s2l_vec);
	if (factor < 0)
		return (factor);
	initialise_t_ray(&shadow);
	shadow.cord = vec3_add(p, vec3_mul(sur_vec, EPSILON));
	shadow.ori = s2l_vec;
	calc_pixel_frt(&shadow, obj);
	if (shadow.t <= EPSILON
			|| shadow.t * shadow.t > vec3_len_sq(p, data->ligt.cord))
		return (factor);
	return (0.0);
}

t_rgb	rgb_add(t_rgb l1, t_rgb l2)
{
	l1.r = l1.r + l2.r;
	l1.g = l1.g + l2.g;
	l1.b = l1.b + l2.b;
	return (l1);
}

t_rgb	rgb_mul(t_rgb l1, t_rgb l2, int bound)
{
	l1.r = l1.r * l2.r / bound;
	l1.g = l1.g * l2.g / bound;
	l1.b = l1.b * l2.b / bound;
	return (l1);
}

t_rgb	calc_pixel_l_diffused(double factor, t_obj *cur, t_data *data)
{
	t_rgb	light;

	initialise_t_rgb(&light);
	light = rgb_amp_capped(data->ligt.rgb, data->ligt.bright);
	light = rgb_amp_capped(light, factor);
	light = rgb_mul(cur->rgb, light, 255);
	return (light);
}

t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_obj *obj, t_data *data)
{
	t_rgb	ambi;
	double	factor;

	initialise_t_rgb(&ambi);
	if (!ray || !cur || !obj || !data)
		return (ambi);
	ambi = rgb_amp_capped(data->ambi.rgb, data->ambi.ratio);
	ambi = rgb_mul(ambi, cur->rgb, 255);
	factor = calc_pixel_l_sdwvslit(ray, cur, obj, data);
	if (factor > 0)
	{
		ambi = rgb_add(ambi, calc_pixel_l_diffused(factor, cur, data));
		ambi = rgb_amp_capped(ambi, 1);
	}
	return (ambi);
}

#define BITS_PER_BYTE 8
#define RGB_BUFFER 8

// endian == 0 is little, endian == 1 is big
int	conv_rgb2str(char *dest, t_rgb rgb, t_data *data)
{
	int		bpp;
	int		endian;

	bpp = data->bits_p_pixel;
	endian = data->endian;
	if (bpp == 32)
	{
		if (endian == 0)
		{
			ft_memcpy(dest, &rgb.b, 1);
			ft_memcpy(dest + 1, &rgb.g, 1);
			ft_memcpy(dest + 2, &rgb.r, 1);
		}
		else if (endian == 1)
		{
			ft_memcpy(dest, (char *)&rgb.r + sizeof(int) - 1, 1);
			ft_memcpy(dest + 1, (char *)&rgb.g + sizeof(int) - 1, 1);
			ft_memcpy(dest + 2, (char *)&rgb.b + sizeof(int) - 1, 1);
		}
	}
	else
		return (ft_puterr("conv_rgb2str err; bpp value unaccounted for"), 1);
	return (0);
}

int	calc_pixel_a(int y, int x, t_rgb rgb, t_data *data)
{
	int		loc;
	char	rgb_str[RGB_BUFFER];
	int		n_bytes;

	n_bytes = data->bits_p_pixel / BITS_PER_BYTE;
	loc = y * data->size_line;
	loc = loc + (n_bytes * x);
	ft_memset(rgb_str, 0, RGB_BUFFER);
	if (conv_rgb2str(rgb_str, rgb, data))
		return (ft_puterr("calc_pixel_a rgb_str is NULL"), 1);
	ft_memcpy(data->addr + loc, rgb_str, n_bytes);
	return (0);
}

int	calc_pixel(t_obj **obj, t_data **data)
{
	t_obj	*frt;
	t_ray	ray;
	int		x;
	int		y;

	frt = NULL;
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			initialise_t_ray(&ray);
			calc_ray_screen2obj(&ray, x, y, *data);
			frt = calc_pixel_frt(&ray, *obj);
			if (calc_pixel_a(y, x, calc_pixel_l(&ray, frt, *obj, *data), *data))
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

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

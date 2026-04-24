/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:04:22 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/02 22:04:22 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

enum e_type
{
	SP,
	PL,
	CY
};

typedef	enum	e_type	t_type;

struct s_cord
{
	double	x;
	double	y;
	double	z;
};

typedef struct	s_cord	t_cord;

struct s_calc
{
	double	a;
	double	b;
	double	c;
	double	sto1;
	double	sto2;
	double	delta;
	t_cord	x;
};

typedef struct	s_calc	t_calc;

struct s_rgb
{
	int	r;
	int	g;
	int	b;
};

typedef struct	s_rgb	t_rgb;

// ori is the direction/orientation, cord is the origin/coordinate
struct s_obj
{
	t_type			type;
	t_cord			cord;
	double			dia;
	t_cord			ori;
	double			higt;
	t_rgb			rgb;
	double			plane_constant;
	int				id;
	struct s_obj	*next;
};

typedef struct	s_obj	t_obj;

struct s_ambi
{
	double	ratio;
	t_rgb	rgb;
};

typedef struct	s_ambi	t_ambi;

struct s_cam
{
	t_cord	cord;
	t_cord	ori;
	int		fov;
};

typedef struct	s_cam	t_cam;

struct s_ligt
{
	t_cord	cord;
	double	bright;
	t_rgb	rgb;
};

typedef struct	s_ligt	t_ligt;

struct s_data
{
	t_bool	ambi_loaded;
	t_ambi	ambi;
	t_bool	cam_loaded;
	t_cam	cam;
	t_bool	ligt_loaded;
	t_ligt	ligt;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_p_pixel;
	int		size_line;
	int		endian;
};

typedef struct	s_data	t_data;

// origin == cord; orientation == ori
struct s_ray
{
	double	t;
	t_cord	cord;
	t_cord	ori;
};

typedef struct s_ray	t_ray;

#endif

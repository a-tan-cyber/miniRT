/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_struct.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/02 22:04:22 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/29 19:29:07 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_STRUCT_H
# define MINIRT_STRUCT_H

typedef enum e_type
{
	SP,
	PL,
	CY
}	t_type;

typedef enum e_lhit
{
	FLAT_TOP,
	FLAT_BOT,
	TUBE
}	t_lhit;

typedef struct s_cord
{
	double	x;
	double	y;
	double	z;
}	t_cord;

typedef struct s_calc
{
	double	a;
	double	b;
	double	c;
	double	sto1;
	double	sto2;
	double	delta;
	t_cord	x;
}	t_calc;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_obj
{
	t_type			type;
	t_cord			cord;
	double			dia;
	t_cord			ori;
	double			higt;
	t_rgb			rgb;
	double			plane_constant;
	struct s_obj	*next;
}	t_obj;

typedef struct s_ambi
{
	double	ratio;
	t_rgb	rgb;
}	t_ambi;

typedef struct s_cam
{
	t_cord	cord;
	t_cord	ori;
	int		fov;
}	t_cam;

typedef struct s_ligt
{
	t_cord	cord;
	double	bright;
	t_rgb	rgb;
}	t_ligt;

typedef struct s_data
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
	t_obj	*obj_head;
}	t_data;


typedef struct s_thrd
{
	pthread_t		thrd;
	t_data			*data;
	t_obj			*obj;
	struct s_thrd	*next;
	t_bool			created;
	int				id;
	int				starty;
	int				endy;
}	t_thrd;

typedef struct s_ray
{
	double	t;
	t_cord	cord;
	t_cord	ori;
	t_lhit	lhit;
}	t_ray;

typedef struct s_box
{
	t_cord	p;
	t_cord	sur_vec;
	t_cord	s2l_vec;
	double	ln_dotp;
}	t_box;

#endif

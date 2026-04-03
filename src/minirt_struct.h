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

struct s_obj
{
	t_type	type;
	float	x;
	float	y;
	float	z;

};


typedef struct	s_obj	t_obj;


typedef struct	s_data	t_data;


#endif
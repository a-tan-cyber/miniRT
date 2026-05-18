/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:56:29 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GETOPT_H
# define FT_GETOPT_H

// arg = argument of the command
// x = argv first dimension
// y = argv second dimension
// err = error no.
// opt = command
typedef struct s_ft_getopt_o
{
	const char	*arg;
	int			x;
	int			y;
	int			err;
	int			opt;
	int			res;
}				t_ft_getopt_o;

int				ft_getopt(int argc, const char **argv, t_ft_getopt_o *opt,
					const char *optstring);

#endif
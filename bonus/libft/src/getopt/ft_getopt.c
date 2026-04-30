/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getopt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:35:29 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// arg = argument of the command
// x = argv first dimension
// y = argv second dimension
// err = error no.
// opt = command
// typedef struct s_ft_getopt_o
// {
// 	char	*arg;
// 	int		x;
// 	int		y;
// 	int		err;
// 	int		opt;
// 	int		res;
// }	s_ft_getopt_o;

int	ft_strchar_n(const char *str, char to_find)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == to_find)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_get_optarg(t_ft_getopt_o *opt, int argc, const char **argv)
{
	int	x;
	int	y;

	x = opt->x;
	y = opt->y;
	while (x < argc)
	{
		if (argv[x][y] && (argv[x][y] != '-'))
		{
			opt->arg = argv[x] + y;
			opt->x = x + 1;
			opt->y = 1;
			return (0);
		}
		x++;
		y = 0;
	}
	return (-1);
}

int	ft_inser_err(t_ft_getopt_o *opt, int errn, int optopt, int errc)
{
	opt->err = errn;
	opt->opt = optopt;
	return (errc);
}

int	ft_find_next_opt(int argc, const char **argv, t_ft_getopt_o *opt,
		const char *optstring)
{
	int	i;

	while (argv[opt->x][opt->y])
	{
		i = ft_strchar_n(optstring, argv[opt->x][opt->y]);
		if (i >= 0)
		{
			opt->res = (int)argv[opt->x][opt->y];
			opt->y++;
			if (optstring[i + 1] && optstring[i + 1] == ':'
				&& ft_get_optarg(opt, argc, argv) == -1)
			{
				opt->res = ft_inser_err(opt, 2, opt->res, ':');
				return (opt->res);
			}
			return (opt->res);
		}
		else
		{
			opt->res = ft_inser_err(opt, 1, argv[opt->x][opt->y++], '?');
			return (opt->res);
		}
	}
	opt->res = 0;
	return (opt->res);
}

//>0 then opt; ==0 then filename
int	ft_getopt(int argc, const char **argv, t_ft_getopt_o *opt,
		const char *optstring)
{
	opt->arg = NULL;
	while (opt->x < argc)
	{
		if (argv[opt->x][0] == '-')
		{
			if (argv[opt->x][1] == '-')
			{
				opt->x++;
				opt->y = 1;
				return (-1);
			}
			opt->res = ft_find_next_opt(argc, argv, opt, optstring);
			if (opt->res != 0)
				return (opt->res);
		}
		else
		{
			opt->arg = argv[opt->x++];
			opt->res = 0;
			return (opt->res);
		}
		opt->x += 1;
		opt->y = 1;
	}
	return (-1);
}

// int	main(int argc, char **argv)
// {
// 	s_ft_getopt_o opt;
// 	opt.arg = NULL;
// 	opt.err = 0;
// 	opt.x = 1;
// 	opt.y = 1;
// 	opt.opt = 0;
// 	opt.res = 0;
// }

// char *optarg;
// 当前选项的参数（如-o foo时，optarg指向"foo"）
// int optind;
// 当前argv索引，下次getopt从这里继续
// int opterr;
// 是否自动打印错误信息（非0为自动）
// int optopt;
// 当前遇到的不合法选项字符

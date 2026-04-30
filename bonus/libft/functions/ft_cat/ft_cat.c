/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:00:43 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <unistd.h>

#define READ_SIZE 220

void	ft_puterr(char *str)
{
	while (*str)
	{
		write(2, &(*str), 1);
		str++;
	}
}

void	read_file_error(char *filename)
{
	ft_puterr("ft_cat: ");
	ft_puterr(basename(filename));
	ft_puterr(": ");
	ft_puterr(strerror(errno));
	ft_puterr("\n");
}

int	read_file(char *filename)
{
	int		rd;
	int		gt;
	char	str[READ_SIZE];
	int		str_size;

	str_size = sizeof(str);
	rd = open(filename, O_RDONLY);
	if (rd < 0)
		return (-1);
	gt = read(rd, str, str_size);
	while (gt > 0)
	{
		write(1, str, gt);
		gt = read(rd, str, str_size);
	}
	if (gt < 0)
	{
		close(rd);
		return (-2);
	}
	close(rd);
	return (0);
}

void	show_txt(void)
{
	char	output[READ_SIZE];
	int		output_size;

	output_size = read(0, output, sizeof(output));
	while (output > 0)
	{
		write(1, output, output_size);
		output_size = read(0, output, sizeof(output));
	}
}

int	main(int argc, char **argv)
{
	char	*filename;
	int		c;
	int		res;

	res = 0;
	if (argc == 1)
		show_txt();
	c = 1;
	while (c < argc)
	{
		filename = argv[c];
		if (read_file(filename) < 0)
		{
			read_file_error(filename);
			res = 1;
		}
		c++;
	}
	return (res);
}

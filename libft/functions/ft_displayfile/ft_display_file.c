/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:58:02 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	ft_puterr(char *str)
{
	while (*str)
	{
		write(2, &(*str), 1);
		str++;
	}
}

void	ft_putnstr(char *str, int n)
{
	write(1, &(*str), n);
}

int	read_file(char *filename)
{
	int		rd;
	int		gt;
	char	str[128];
	int		str_size;

	str_size = sizeof(str);
	rd = open(filename, O_RDONLY);
	if (rd < 0)
	{
		return (-1);
	}
	gt = read(rd, str, str_size);
	while (gt > 0)
	{
		ft_putnstr(str, gt);
		gt = read(rd, str, str_size);
	}
	close(rd);
	return (0);
}

int	main(int argc, char **argv)
{
	char	*filename;

	if (argc < 2)
	{
		ft_puterr("File name missing.\n");
		return (-2);
	}
	else if (argc > 2)
	{
		ft_puterr("Too many arguments.\n");
		return (1);
	}
	filename = argv[1];
	if (read_file(filename) < 0)
	{
		ft_puterr("Cannot read file.\n");
		return (-1);
	}
	return (0);
}

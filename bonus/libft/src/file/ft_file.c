/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 15:04:40 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	read_file(char *filename)
{
	int		rd;
	int		gt;
	char	str[FILE_READ_SIZE];
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

int	check_file_size(const char *filename)
{
	int		rd;
	int		gt;
	char	str[FILE_READ_SIZE];
	int		str_size;
	int		res;

	str_size = sizeof(str);
	rd = open(filename, O_RDONLY);
	if (rd < 0)
		return (-1);
	gt = read(rd, str, str_size);
	res = gt;
	while (gt > 0)
	{
		gt = read(rd, str, str_size);
		res += gt;
	}
	if (gt < 0)
	{
		close(rd);
		return (-2);
	}
	close(rd);
	return (res);
}

void	read_file_from_nbyte(const char *filename, int start)
{
	int		rd;
	int		gt;
	char	str[FILE_READ_SIZE];
	int		str_size;

	str_size = sizeof(str);
	rd = open(filename, O_RDONLY);
	while (start > str_size)
	{
		read(rd, str, str_size);
		start -= str_size;
	}
	read(rd, str, start);
	gt = read(rd, str, str_size);
	while (gt > 0)
	{
		write(1, str, gt);
		gt = read(rd, str, str_size);
	}
	close(rd);
}

size_t	file_count_lines(char *filename)
{
	int		fd;
	size_t	lines;
	char	*buf;

	fd = open(filename, O_RDONLY);
	if (fd <= 0)
		return (0);
	lines = 0;
	buf = get_next_line(fd);
	while (buf != NULL)
	{
		lines += 1;
		free(buf);
		buf = get_next_line(fd);
	}
	close(fd);
	return (lines);
}

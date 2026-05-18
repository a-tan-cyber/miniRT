/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 23:07:09 by amtan             #+#    #+#             */
/*   Updated: 2026/03/17 22:59:04 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static void	recur_putdigits_fd(unsigned int num, int fd)
{
	if (num > 9)
		recur_putdigits_fd(num / 10, fd);
	ft_putchar_fd(num % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				is_neg;
	unsigned int	num;

	is_neg = (n < 0);
	num = (unsigned int)n;
	if (is_neg)
	{
		num = -num;
		ft_putchar_fd('-', fd);
	}
	recur_putdigits_fd(num, fd);
}

void	ft_putchar_fd(char c, int fd)
{
	ft_write_all(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_write_all(fd, s, ft_strlen(s));
}

void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

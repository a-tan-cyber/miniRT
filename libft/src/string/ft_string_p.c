/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/18 00:37:43 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_putchar(char c)
{
	ft_write_all(STDOUT_FILENO, &c, 1);
}

void	ft_putstr(const char *str)
{
	ft_write_all(STDOUT_FILENO, str, ft_strlen(str));
}

void	ft_puterr(char *str)
{
	ft_write_all(STDERR_FILENO, str, ft_strlen(str));
}

void	ft_putnstr(char *str, int n)
{
	ft_write_all(STDOUT_FILENO, str, (size_t)n);
}

void	ft_putnbr(int nb)
{
	int		negative;
	char	digit;

	negative = 1;
	if (nb < 0)
	{
		ft_write_all(STDOUT_FILENO, "-", 1);
		negative = -1;
	}
	if (-10 < nb && nb < 10)
	{
		digit = nb * negative;
		digit = digit + '0';
	}
	else
	{
		digit = nb % 10;
		digit = digit * negative;
		digit = digit + '0';
		ft_putnbr((int)(negative * (nb / 10)));
	}
	ft_write_all(STDOUT_FILENO, &digit, 1);
}

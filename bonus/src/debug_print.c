/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:48:59 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 21:49:04 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <unistd.h>

static void	debug_put_str(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

static void	debug_put_long(long n)
{
	char	c;

	if (n >= 10)
		debug_put_long(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
}

static void	debug_put_double(double n)
{
	long	i_part;
	long	f_part;

	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	i_part = (long)n;
	f_part = (long)((n - i_part) * 1000.0 + 0.5);
	if (f_part >= 1000)
	{
		i_part++;
		f_part = 0;
	}
	debug_put_long(i_part);
	write(1, ".", 1);
	if (f_part < 100)
		write(1, "0", 1);
	if (f_part < 10)
		write(1, "0", 1);
	debug_put_long(f_part);
}

void	ft_print_t_cord(t_cord cord)
{
	debug_put_double(cord.x);
	debug_put_str(", ");
	debug_put_double(cord.y);
	debug_put_str(", ");
	debug_put_double(cord.z);
	debug_put_str("; ");
}

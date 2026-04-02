/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:05:08 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	res = 1;
	while (nb > 0)
	{
		res = res * nb;
		nb = nb - 1;
	}
	return (res);
}

int	ft_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	while (power > 0)
	{
		res = res * nb;
		power--;
	}
	return (res);
}

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	ft_sqrt(int nb)
{
	int	count;
	int	product;

	count = 1;
	product = 0;
	while (product < nb)
	{
		product = count * count;
		count++;
	}
	if (product == nb)
		return (count - 1);
	else
		return (0);
}

int	ft_range(int **range, int min, int max)
{
	long	length;
	int		*range_start;

	length = (long)max - (long)min;
	if (length <= 0)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(**range) * length);
	if (!*range)
		return (-1);
	range_start = *range;
	while (min < max)
	{
		**range = min;
		(*range)++;
		min++;
	}
	*range = range_start;
	return ((int)length);
}

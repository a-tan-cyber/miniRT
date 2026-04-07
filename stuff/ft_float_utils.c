/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:12 by amtan             #+#    #+#             */
/*   Updated: 2026/04/06 15:57:27 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

int	ft_skip_space(const char *s, int i)
{
	while (s[i] && ft_is_space(s[i]))
		i++;
	return (i);
}

void	ft_read_frac(const char *s, int *i, float *nb)
{
	float	div;

	div = 10.0f;
	while (ft_is_digit(s[*i]))
	{
		*nb = *nb + (s[*i] - '0') / div;
		div = div * 10.0f;
		(*i)++;
	}
}

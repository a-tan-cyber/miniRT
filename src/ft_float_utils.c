/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:12 by amtan             #+#    #+#             */
/*   Updated: 2026/04/10 18:02:09 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

static int	ft_is_space(char c)
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

double	ft_read_frac(const char *s, int *i)
{
	double	frac;
	double	div;

	frac = 0.0;
	div = 10.0;
	while (ft_is_digit(s[*i]))
	{
		frac = frac + (s[*i] - '0') / div;
		div = div * 10.0;
		(*i)++;
	}
	return (frac);
}

int	ft_read_exp(const char *s, int *i, int *exp, int *exp_sign)
{
	int	has_digit;

	has_digit = 0;
	if (s[*i] != 'e' && s[*i] != 'E')
		return (1);
	(*i)++;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			*exp_sign = -1;
		(*i)++;
	}
	while (ft_is_digit(s[*i]))
	{
		has_digit = 1;
		*exp = (*exp * 10) + (s[*i] - '0');
		(*i)++;
	}
	return (has_digit);
}

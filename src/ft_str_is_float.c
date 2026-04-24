/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:33 by amtan             #+#    #+#             */
/*   Updated: 2026/04/10 18:02:24 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

static int	ft_has_number(const char *s, int *i)
{
	int	has_digit;

	has_digit = 0;
	while (ft_is_digit(s[*i]))
	{
		has_digit = 1;
		(*i)++;
	}
	if (s[*i] == '.')
		(*i)++;
	while (ft_is_digit(s[*i]))
	{
		has_digit = 1;
		(*i)++;
	}
	return (has_digit);
}

int	ft_str_is_float(const char *s)
{
	int	i;
	int	exp;
	int	exp_sign;

	if (!s)
		return (0);
	i = ft_skip_space(s, 0);
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_has_number(s, &i))
		return (0);
	exp = 0;
	exp_sign = 1;
	if (!ft_read_exp(s, &i, &exp, &exp_sign))
		return (0);
	i = ft_skip_space(s, i);
	return (s[i] == '\0');
}

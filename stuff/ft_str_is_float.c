/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_float.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:33 by amtan             #+#    #+#             */
/*   Updated: 2026/04/06 15:57:26 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

static int	ft_read_exp(const char *s, int *i)
{
	int	has_digit;

	has_digit = 0;
	if (s[*i] == 'e' || s[*i] == 'E')
	{
		(*i)++;
		if (s[*i] == '+' || s[*i] == '-')
			(*i)++;
		while (ft_is_digit(s[*i]))
		{
			has_digit = 1;
			(*i)++;
		}
		if (!has_digit)
			return (0);
	}
	return (1);
}

int	ft_str_is_float(const char *s)
{
	int	i;
	int	has_digit;

	if (!s)
		return (0);
	i = ft_skip_space(s, 0);
	has_digit = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_is_digit(s[i]))
	{
		has_digit = 1;
		i++;
	}
	if (s[i] == '.')
		i++;
	while (ft_is_digit(s[i]))
	{
		has_digit = 1;
		i++;
	}
	if (!has_digit || !ft_read_exp(s, &i))
		return (0);
	i = ft_skip_space(s, i);
	return (s[i] == '\0');
}

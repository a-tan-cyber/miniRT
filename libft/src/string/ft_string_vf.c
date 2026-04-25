/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_vf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/24 16:26:37 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/24 16:26:37 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static int	ft_is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f' || c == '\r');
}

int	ft_skip_space(const char *s, int i)
{
	while (s[i] && ft_is_space(s[i]))
		i++;
	return (i);
}

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

// 1 is true, 0 is false
int	ft_str_is_float(const char *str)
{
	int	i;
	int	exp;
	int	exp_sign;

	if (!str)
		return (0);
	i = ft_skip_space(str, 0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!ft_has_number(str, &i))
		return (0);
	exp = 0;
	exp_sign = 1;
	if (!ft_read_exp(str, &i, &exp, &exp_sign))
		return (0);
	i = ft_skip_space(str, i);
	return (str[i] == '\0');
}
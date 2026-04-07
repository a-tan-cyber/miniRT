/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:52 by amtan             #+#    #+#             */
/*   Updated: 2026/04/06 15:57:29 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_float.h"

static int	ft_get_sign(const char *s, int *i)
{
	int	sign;

	sign = 1;
	if (s[*i] == '+' || s[*i] == '-')
	{
		if (s[*i] == '-')
			sign = -1;
		(*i)++;
	}
	return (sign);
}

static void	ft_read_exp(const char *s, int *i, int *exp, int *exp_sign)
{
	if (s[*i] == 'e' || s[*i] == 'E')
	{
		(*i)++;
		*exp_sign = ft_get_sign(s, i);
		while (ft_is_digit(s[*i]))
		{
			*exp = (*exp * 10) + (s[*i] - '0');
			(*i)++;
		}
	}
}

static float	ft_apply_exp(float nb, int exp, int exp_sign)
{
	while (exp > 0)
	{
		if (exp_sign < 0)
			nb = nb / 10.0f;
		else
			nb = nb * 10.0f;
		exp--;
	}
	return (nb);
}

float	ft_atof(const char *s)
{
	int		i;
	int		sign;
	int		exp_sign;
	int		exp;
	float	nb;

	if (!ft_str_is_float(s))
		return (0.0f);
	i = ft_skip_space(s, 0);
	sign = ft_get_sign(s, &i);
	exp_sign = 1;
	exp = 0;
	nb = 0.0f;
	while (ft_is_digit(s[i]))
		nb = (nb * 10.0f) + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		ft_read_frac(s, &i, &nb);
	}
	ft_read_exp(s, &i, &exp, &exp_sign);
	nb = nb * sign;
	return (ft_apply_exp(nb, exp, exp_sign));
}

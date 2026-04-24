/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:47:52 by amtan             #+#    #+#             */
/*   Updated: 2026/04/10 18:02:37 by amtan            ###   ########.fr       */
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

static double	ft_apply_exp(double nb, int exp, int exp_sign)
{
	while (exp > 0)
	{
		if (exp_sign < 0)
			nb = nb / 10.0;
		else
			nb = nb * 10.0;
		exp--;
	}
	return (nb);
}

double	ft_atod(const char *s)
{
	int		i;
	int		sign;
	int		exp;
	int		exp_sign;
	double	nb;

	if (!ft_str_is_float(s))
		return (0.0);
	i = ft_skip_space(s, 0);
	sign = ft_get_sign(s, &i);
	exp = 0;
	exp_sign = 1;
	nb = 0.0;
	while (ft_is_digit(s[i]))
		nb = (nb * 10.0) + (s[i++] - '0');
	if (s[i] == '.')
	{
		i++;
		nb = nb + ft_read_frac(s, &i);
	}
	ft_read_exp(s, &i, &exp, &exp_sign);
	return (ft_apply_exp(nb * sign, exp, exp_sign));
}

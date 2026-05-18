/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:01:23 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:01:27 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ins_chkr(t_bool *chkr, const char *str)
{
	if (!ft_strcmp("is_chkr", str))
		*chkr = TRUE;
	else if (!ft_strcmp("no_chkr", str))
		*chkr = FALSE;
	else
		return (ft_puterr("ins_chkr value is invalid"), -1);
	return (0);
}

int	ins_bump(t_bump *bump_type, const char *str)
{
	if (!ft_strcmp("sine", str))
		*bump_type = SINE;
	else if (!ft_strcmp("perlin", str))
		*bump_type = PERLIN;
	else if (!ft_strcmp("empty", str))
		*bump_type = EMPTY;
	else
		return (ft_puterr("bump type value is invalid"), -1);
	return (0);
}

int	is_chkr_token(const char *str)
{
	return (!ft_strcmp("is_chkr", str) || !ft_strcmp("no_chkr", str));
}

int	is_bump_token(const char *str)
{
	return (!ft_strcmp("sine", str) || !ft_strcmp("perlin", str)
		|| !ft_strcmp("empty", str));
}

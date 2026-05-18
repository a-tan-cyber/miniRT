/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_object_bonus_apply_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:01:12 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:01:19 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	ins_obj_bonus_first(const char **split_arr, int first_bonus,
			t_obj *new, int len)
{
	if (is_chkr_token(split_arr[first_bonus]))
	{
		if (ins_chkr(&new->chkr, split_arr[first_bonus]))
			return (-1);
		return (0);
	}
	if (len == first_bonus + 1 && is_bump_token(split_arr[first_bonus]))
	{
		if (ins_bump(&new->bump, split_arr[first_bonus]))
			return (-1);
		return (0);
	}
	return (ft_puterr("object bonus field is invalid"), -1);
}

int	ins_obj_bonus(const char **split_arr, int first_bonus, t_obj *new)
{
	int	len;

	len = ft_arrlen(split_arr);
	if (len == first_bonus)
		return (0);
	if (len > first_bonus + 2)
		return (ft_puterr("object wrong number of bonus fields"), -1);
	if (ins_obj_bonus_first(split_arr, first_bonus, new, len))
		return (-1);
	if (len == first_bonus + 2 && ins_bump(&new->bump,
			split_arr[first_bonus + 1]))
		return (-1);
	return (0);
}

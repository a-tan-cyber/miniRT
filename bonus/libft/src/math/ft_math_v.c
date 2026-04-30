/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 11:33:39 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/04 11:33:39 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_bool	int_is_odd(int n)
{
	if (n & 1 == 1)
		return (TRUE);
	return (FALSE);
}

t_bool	int_is_even(int n)
{
	if (n & 0 == 0)
		return (TRUE);
	return (FALSE);
}

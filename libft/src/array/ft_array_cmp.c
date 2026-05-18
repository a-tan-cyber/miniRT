/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:05:26 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:06:46 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_arr_is_subset(const char **arr, char *set)
{
	if (!arr)
		return (1);
	while (*arr)
	{
		if (ft_str_is_subset(*arr, set) == 0)
			return (0);
		arr++;
	}
	return (1);
}

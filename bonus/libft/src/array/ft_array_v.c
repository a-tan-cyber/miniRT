/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_v.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:48:58 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/15 13:48:58 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	arr_is_int(char **arr, size_t arr_c)
{
	size_t	i;

	i = 0;
	while (i < arr_c)
	{
		if (ft_str_is_int(arr[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

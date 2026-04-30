/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cvt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:53:23 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/15 13:53:23 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	*arr_to_iarr(char **arr, size_t arr_c)
{
	int		*iarr;
	size_t	i;

	if (arr_is_int(arr, arr_c) != 1)
		return (NULL);
	iarr = malloc(sizeof(int) * arr_c);
	if (!iarr)
		return (NULL);
	i = 0;
	while (i < arr_c)
	{
		iarr[i] = ft_atoi(arr[i]);
		i++;
	}
	return (iarr);
}

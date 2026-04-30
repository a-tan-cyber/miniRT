/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarr_cpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:04:46 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/24 22:04:46 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_iarr_cpy(int *dest, const int *src, size_t iarr_c)
{
	size_t	i;

	i = 0;
	while (i < iarr_c)
	{
		dest[i] = src[i];
		i++;
	}
	return (i);
}

void	ft_iarr_cpy_mul(int *iarr_mul, size_t times, const int *iarr,
		size_t iarr_c)
{
	size_t	c;

	c = 0;
	while (c < times)
	{
		ft_iarr_cpy(iarr_mul + (iarr_c * c), iarr, iarr_c);
		c++;
	}
}

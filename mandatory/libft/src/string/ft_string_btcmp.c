/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_btcmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:03:19 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:24 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_str_is_subset(const char *pool, const char *legal)
{
	unsigned char	l_mask[32];
	int				c;

	ft_memset(l_mask, 0, 32);
	while (*legal)
	{
		c = (unsigned char)*legal;
		l_mask[c / 8] = (l_mask[c / 8]) | (1u << (c % 8));
		legal++;
	}
	while (*pool)
	{
		c = (unsigned char)*pool;
		if (((l_mask[c / 8]) & (1U << (c % 8))) == 0)
			return (0);
		pool++;
	}
	return (1);
}

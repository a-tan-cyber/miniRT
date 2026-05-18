/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_iss.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:21:22 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:06:48 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_is_rect(const char **arr)
{
	size_t	width;

	if (!arr || !*arr)
		return (0);
	width = ft_strlen(*arr);
	arr++;
	while (*arr)
	{
		if (width != ft_strlen(*arr))
			return (0);
		arr++;
	}
	return (1);
}

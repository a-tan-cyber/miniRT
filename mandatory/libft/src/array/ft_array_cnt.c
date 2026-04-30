/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cnt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 11:32:13 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:06:42 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_count_cina(const char **arr, char c)
{
	int	count;

	if (!arr || !*arr)
		return (0);
	count = 0;
	while (*arr)
	{
		count += ft_count_cins(*arr, c);
		arr++;
	}
	return (count);
}

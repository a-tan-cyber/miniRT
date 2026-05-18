/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cat.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:23 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	char	*dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*dest_start;

	dest_start = dest;
	while (*dest)
		dest++;
	while (nb > 0 && *src)
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (dest_start);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	count;

	count = 0;
	while (size > 0 && *dest)
	{
		dest++;
		count++;
		size--;
	}
	while (size > 1 && *src)
	{
		*dest++ = *src++;
		count++;
		size--;
	}
	while (*src++)
		count++;
	if (size > 0)
		*dest = '\0';
	return (count);
}

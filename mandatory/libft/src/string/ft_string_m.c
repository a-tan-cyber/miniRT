/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:20 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	char	*dest_start;

	dest = malloc(sizeof(char) * (ft_strlen(src) + 1));
	dest_start = dest;
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest_start);
}

char	*ft_strndup(const char *src, size_t n)
{
	char	*dest;
	char	*dest_start;

	dest = malloc(sizeof(char) * (n + 1));
	if (!dest)
		return (NULL);
	dest_start = dest;
	while (n > 0 && *src)
	{
		*dest++ = *src++;
		n--;
	}
	while (n > 0)
	{
		*dest++ = '\0';
		n--;
	}
	*dest = '\0';
	return (dest_start);
}

void	*ft_bzero(void *dest, size_t size)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	while (i < size)
	{
		d[i] = 0;
		i++;
	}
	return (dest);
}

void	*ft_calloc(size_t len, size_t size)
{
	void	*dest;
	size_t	max_size;
	size_t	i;
	char	*d;

	if ((len > 0) && (SIZE_MAX / len) < size)
		return (NULL);
	max_size = len * size;
	dest = malloc(max_size);
	if (!dest)
		return (NULL);
	d = (char *)dest;
	i = 0;
	while (i < max_size)
	{
		d[i] = 0;
		i++;
	}
	return (dest);
}

void	*ft_realloc(void *p, size_t oldn, size_t newn)
{
	char	*d;

	if (!p || (p && newn == 0))
	{
		if (p && newn == 0)
			free(p);
		return (malloc(newn));
	}
	d = malloc(newn);
	if (!d)
		return (NULL);
	if (oldn < newn)
		ft_memmove(d, p, oldn);
	else
		ft_memmove(d, p, newn);
	free(p);
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_mem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:18 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	*ft_memset(void *dest, int n, size_t size)
{
	size_t			i;
	unsigned char	*d;

	i = 0;
	d = (unsigned char *)dest;
	while (i < size)
	{
		d[i] = (unsigned char)n;
		i++;
	}
	return (dest);
}

void	*ft_memcpy(void *dest, const void *src, size_t size)
{
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	while (size > 0)
	{
		*d++ = *s++;
		size--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	size_t	i;

	d = (char *)dest;
	i = 0;
	if (d < (char *)src)
	{
		while (n > i)
		{
			d[i] = ((char *)src)[i];
			i++;
		}
	}
	else
	{
		while (n > 0)
		{
			n--;
			d[n] = ((char *)src)[n];
		}
	}
	return (dest);
}

// void	*ft_memmove(void *dest, const void *src, size_t n)
// {
// 	char	*d;
// 	char	*s;
// 	size_t	i;

// 	if (!dest || !src)
// 		return (NULL);
// 	d = (char *)dest;
// 	s = (char *)src;
// 	i = 0;
// 	if (d < s)
// 	{
// 		while (n > i)
// 		{
// 			d[i] = s[i];
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		while (n > 0)
// 		{
// 			n--;
// 			d[n] = s[n];
// 		}
// 	}
// 	return (dest);
// }

void	*ft_memchr(const void *src, int c, size_t size)
{
	unsigned char	*s;

	s = (unsigned char *)src;
	while (size > 0)
	{
		if (*s == (unsigned char)c)
		{
			return ((void *)s);
		}
		s++;
		size--;
	}
	return (NULL);
}

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t n)
{
	const unsigned char	*s1;
	const unsigned char	*s2;

	s1 = (const unsigned char *)ptr1;
	s2 = (const unsigned char *)ptr2;
	while (n > 0)
	{
		if (*s1 != *s2)
		{
			return (*s1 - *s2);
		}
		s1++;
		s2++;
		n--;
	}
	return (0);
}

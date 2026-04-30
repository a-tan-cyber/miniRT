/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_mem2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:56:58 by yunguo            #+#    #+#             */
/*   Updated: 2026/01/17 11:18:00 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// remalloc s2, add s1 to front
char	*ft_memappend_front(const char *s1, size_t len1, char *s2, size_t len2)
{
	char	*res;
	char	*res_start;
	char	*s2_ptr;

	s2_ptr = s2;
	res = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
	{
		free(s2);
		return (NULL);
	}
	res_start = res;
	while (len1 > 0)
	{
		*res++ = *s1++;
		len1--;
	}
	while (len2 > 0)
	{
		*res++ = *s2++;
		len2--;
	}
	*res = '\0';
	free(s2_ptr);
	return (res_start);
}

// // remalloc s1, append s2
// char	*ft_memappend_back(char *s1, size_t len1, char const *s2, size_t len2)
// {
// 	char	*res;
// 	char	*res_start;
// 	char	*s1_ptr;

// 	s1_ptr = s1;
// 	res = malloc(sizeof(char) * (len1 + len2 + 1));
// 	if (!res)
// 	{
// 		free(s1);
// 		return (NULL);
// 	}
// 	res_start = res;
// 	while (len1 > 0)
// 	{
// 		*res++ = *s1++;
// 		len1--;
// 	}
// 	while (len2 > 0)
// 	{
// 		*res++ = *s2++;
// 		len2--;
// 	}
// 	*res = '\0';
// 	free(s1_ptr);
// 	return (res_start);
// }

// len == size of byte for void pointer str
void	*ft_memappend_back(void *s1, size_t len1, const void *s2, size_t len2)
{
	char	*d;
	size_t	i;
	size_t	j;

	if (!s1)
		return (NULL);
	d = malloc(sizeof(char) * (len1 + len2 + 1));
	if (!d)
		return (free(s1), NULL);
	i = 0;
	while (i < len1)
	{
		d[i] = ((char *)s1)[i];
		i++;
	}
	j = 0;
	while (j < len2)
	{
		d[i + j] = ((char *)s2)[j];
		j++;
	}
	d[i + j] = '\0';
	free(s1);
	return (d);
}

void	*ft_memjoin2(void const *s1, size_t len1, void const *s2, size_t len2)
{
	unsigned char	*res;
	unsigned char	*res_start;
	unsigned char	*src1;
	unsigned char	*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	res = malloc(len1 + len2 + 1);
	if (!res)
		return (NULL);
	res_start = res;
	while (len1 > 0)
	{
		*res++ = *src1++;
		len1--;
	}
	while (len2 > 0)
	{
		*res++ = *src2++;
		len2--;
	}
	*res = '\0';
	return ((void *)res_start);
}

// char	*ft_memjoin2(char const *s1, size_t len1, char const *s2, size_t len2)
// {
// 	char	*res;
// 	char	*res_start;

// 	res = malloc(sizeof(char) * (len1 + len2 + 1));
// 	if (!res)
// 		return (NULL);
// 	res_start = res;
// 	while (len1 > 0)
// 	{
// 		*res++ = *s1++;
// 		len1--;
// 	}
// 	while (len2 > 0)
// 	{
// 		*res++ = *s2++;
// 		len2--;
// 	}
// 	*res = '\0';
// 	return (res_start);
// }

char	*ft_strjoin2(char const *s1, char const *s2)
{
	size_t	len;
	char	*res;
	char	*res_start;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res_start = res;
	while (*s1)
		*res++ = *s1++;
	while (*s2)
		*res++ = *s2++;
	*res = '\0';
	return (res_start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:03:05 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break ;
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	while (n > 0)
	{
		if ((*s1 != *s2) || (*s1 == '\0'))
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	char	*str_temp;
	char	*to_find_temp;

	if (*to_find == '\0')
		return (str);
	while (*str)
	{
		str_temp = str;
		to_find_temp = to_find;
		while ((*str_temp == *to_find_temp) && *str_temp)
		{
			str_temp++;
			to_find_temp++;
		}
		if (*to_find_temp == '\0')
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strchr(const char *str, int to_find)
{
	while (*str)
	{
		if ((unsigned char)*str == (unsigned char)to_find)
			return ((char *)str);
		str++;
	}
	if ((unsigned char)*str == (unsigned char)to_find)
	{
		return ((char *)str);
	}
	return (NULL);
}

//if found then idx >= 0; if str is null then -1; if not found then -2.
int	ft_strchr_idx(const char *str, int to_find)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i] && str[i] != to_find)
		i++;
	if (str[i] == to_find)
		return (i);
	return (-2);
}

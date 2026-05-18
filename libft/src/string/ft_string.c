/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:58:37 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_reverse_string(char *string, char *reverse_string, int length)
{
	int	index;

	index = 0;
	while (length > 0)
	{
		reverse_string[index] = string[length - 1];
		length--;
		index++;
	}
	reverse_string[index] = '\0';
}

// takes string[] return malloced reverse string
// caller free()
char	*ft_reverse_string_malloc(char *string)
{
	int		length;
	char	*string_p;
	char	*reversed_string;
	int		j;

	length = ft_strlen(string);
	reversed_string = malloc((length + 1) * (sizeof(char)));
	string_p = reversed_string;
	j = length - 1;
	while (j >= 0)
	{
		string_p = concat_char_insitu(string_p, string[j]);
		j--;
	}
	return (reversed_string);
}

char	*ft_str_replace(char *text, size_t start, size_t len, char *expanded)
{
	size_t	total_len;
	size_t	expanded_len;
	char	*res;

	expanded_len = ft_strlen(expanded);
	total_len = ft_strlen(text) - len + expanded_len;
	res = malloc((total_len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	ft_memcpy(res, text, start);
	ft_memcpy(res + start, expanded, expanded_len);
	ft_strcpy(res + start + expanded_len, text + start + len);
	return (res);
}

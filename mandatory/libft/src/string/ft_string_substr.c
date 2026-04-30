/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_substr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:58:48 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_substr(char const *s, size_t start, size_t len)
{
	char	*res;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		len = 0;
	res = ft_strndup(s + start, len);
	return (res);
}

void	ft_str_replace_chr(char *text, int original, int target)
{
	while (*text)
	{
		if (*text == original)
			*text = target;
		text++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cnt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 10:23:06 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:02:59 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_count_cins(const char *str, char c)
{
	int	count;

	if (!str)
		return (0);
	count = 0;
	while (*str)
	{
		if (*str == c)
			count += 1;
		str++;
	}
	return (count);
}

int	num_of_x_ignore_y_substr(const char *line, char x, char y)
{
	size_t	i;
	size_t	count;

	if (!line)
		return (0);
	count = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == y)
		{
			i++;
			while (line[i] && line[i] != y)
				i++;
			if (line[i] == '\0')
				break ;
		}
		else if (line[i] == x)
			count++;
		i++;
	}
	return (count);
}

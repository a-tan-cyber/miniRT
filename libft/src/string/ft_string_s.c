/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:16 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

static unsigned int	ft_strjoin_total_len(int size, char **strs, char *sep)
{
	int	res_len;
	int	sep_len;
	int	i;

	res_len = 1;
	i = 0;
	if (strs == NULL)
		return (-1);
	while (i < size)
	{
		if (strs[i] == NULL)
			return (-1);
		res_len += ft_strlen(strs[i]);
		i++;
	}
	if (sep == NULL)
		return (-1);
	sep_len = ft_strlen(sep);
	res_len += sep_len * (size - 1);
	return ((unsigned int)res_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		res_len;
	char	*res;
	int		count;

	res_len = ft_strjoin_total_len(size, strs, sep);
	if (res_len < 0)
	{
		res_len = 1;
		size = 0;
	}
	res = malloc(res_len * sizeof(**strs));
	if (!res)
		return (NULL);
	*res = '\0';
	count = 0;
	while (count < size)
	{
		ft_strcat(res, strs[count]);
		if (count++ != size - 1)
			ft_strcat(res, sep);
	}
	return (res);
}

size_t	find_split_count(char *str, char *charset)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = 0;
	while (str[i])
	{
		if (ft_btmsk_cins(str[i], charset))
		{
			if (len > 0)
				c++;
			len = 0;
		}
		else
			len++;
		i++;
	}
	if (len > 0)
		c++;
	return ((size_t)c);
}

void	ft_sp_run(char *str, char *charset, char ***res)
{
	int	i;
	int	c;
	int	len;

	i = 0;
	c = 0;
	len = 0;
	while (str[i])
	{
		if (ft_btmsk_cins(str[i], charset))
		{
			if (len > 0)
				(*res)[c++] = ft_strndup(str + i - len, len);
			len = 0;
		}
		else
			len++;
		i++;
	}
	if (len > 0)
		(*res)[c++] = ft_strndup(str + i - len, len);
	(*res)[c] = NULL;
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	size_t	res_count;

	if (!str || !(*str))
		return (NULL);
	res_count = find_split_count(str, charset) + 1;
	if (res_count <= 1)
		return (NULL);
	res = malloc(sizeof(char *) * (res_count));
	if (!res)
		return (NULL);
	ft_sp_run(str, charset, &res);
	return (res);
}

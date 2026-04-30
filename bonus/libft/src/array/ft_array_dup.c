/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_dup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 13:51:10 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/15 13:51:10 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	**ft_arrdup(const char **arr)
{
	char	**res;
	char	**res_start;
	size_t	len;

	if (!arr)
		return (NULL);
	len = ft_arrlen(arr);
	res = malloc(sizeof(char *) * (len + 1));
	if (!res)
		return (NULL);
	res_start = res;
	while (*arr)
	{
		*res = ft_strdup(*arr);
		if (!(*res))
		{
			free_arr(res_start);
			return (NULL);
		}
		res++;
		arr++;
	}
	*res = NULL;
	return (res_start);
}

int	ft_arrdup_mk2(char ***dest, const char **src)
{
	char	**dest_start;
	size_t	len;

	if (!dest || !src)
		return (1);
	len = ft_arrlen(src);
	*dest = ft_calloc(len + 1, sizeof(char *));
	if (!*dest)
		return (2);
	dest_start = *dest;
	while (*src)
	{
		**dest = ft_strdup(*src);
		if (!(**dest))
		{
			*dest = dest_start;
			free_arr(dest_start);
			return (3);
		}
		(*dest)++;
		src++;
	}
	**dest = NULL;
	*dest = dest_start;
	return (0);
}

int	*ft_iarrdup(int *iarr, size_t arr_c)
{
	int		*new_iarr;
	size_t	i;

	new_iarr = malloc(sizeof(int) * arr_c);
	if (!new_iarr)
		return (NULL);
	i = 0;
	while (i < arr_c)
	{
		new_iarr[i] = iarr[i];
		i++;
	}
	return (new_iarr);
}

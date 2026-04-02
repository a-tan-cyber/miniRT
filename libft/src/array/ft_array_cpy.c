/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_cpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 08:51:47 by yunguo            #+#    #+#             */
/*   Updated: 2026/02/26 15:52:54 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_arrcpy(char ***dest, const char **src)
{
	char	**tmp;
	int		ret;

	if (!dest || !src)
		return (1);
	tmp = NULL;
	ret = ft_arrdup_mk2(&tmp, src);
	if (ret != 0)
		return (ret);
	if (*dest)
		free_arr(*dest);
	*dest = tmp;
	return (0);
}

// init_env(&my_env, envp)
// int		ft_arrcpy(char ***dest, const char **src)
// {
	// size_t	len;
	// len = ft_arrlen(src);
	// res = malloc(sizeof(char *) * (len + 1));
	// if (!res)
	// 	return (NULL);
	// res_start = res;
	// while (*arr)
	// {
	// 	*res = ft_strdup(*arr);
	// 	if (!(*res))
	// 	{
	// 		free_arr(res_start);
	// 		return (NULL);
	// 	}
	// 	res++;
	// 	arr++;
	// }
	// *res = NULL;
	// return (res_start);
// 	return (1);
// }

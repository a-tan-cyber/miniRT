/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarr_print.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 08:58:24 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:58:43 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/libft.h"

// #include <stdio.h>
// void	ft_print_arr(char *name, char **arr)
// {
// 	size_t	i;

// 	printf("%s: {", name);
// 	if (!arr || !*arr)
// 		printf("(error)}\n");
// 	i = 0;
// 	while (arr[i + 1] != NULL)
// 	{
// 		printf("%s, ", arr[i]);
// 		i++;
// 	}
// 	printf("%s}\n", arr[i]);
// }
// void	ft_print_iarr(char *name, const int *iarr, size_t iarr_c)
// {
// 	size_t	i;
// 	(void)name;
// 	(void)iarr;
// 	printf("%s: {", name);
// 	i = 0;
// 	while (i + 1 < iarr_c)
// 	{
// 		printf("% d, ", iarr[i]);
// 		i++;
// 	}
// 	printf("% d}\n", iarr[i]);	
// }
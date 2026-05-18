/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iarr_chk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 08:58:08 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/24 08:58:08 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

//if no repeat return 0, have repeat return 1
int	ft_iarr_chkrep(int **arr, size_t arr_c)
{
	size_t	i;

	i = 0;
	while (i + 1 < arr_c)
	{
		if ((*arr)[i] == (*arr)[i + 1])
			return (1);
		i++;
	}
	return (0);
}

int	ft_iarr_chkrep_sorted(int *iarr, size_t arr_c)
{
	size_t	i;

	i = 0;
	while (i + 1 < arr_c)
	{
		if (iarr[i] == iarr[i + 1])
			return (1);
		i++;
	}
	return (0);
}

//return the idx that pin fits on iarr. O(NlogN)
// size_t	iarr_search_sorted_ins(const int *iarr, size_t iarr_c, int pin)
// {
// 	size_t	min;
// 	size_t	mid;
// 	size_t	max;

// 	min = 0;
// 	max = iarr_c;
// 	while (TRUE)
// 	{
// 		mid = (min + max) / 2;
// 		if (mid == 0 || mid == iarr_c - 1 || iarr[mid] == pin
// 			 || (iarr[mid - 1] < pin && iarr[mid] > pin))
// 			break ;
// 		if (iarr[mid] < pin)
// 			min = mid;
// 		else if (iarr[mid] > pin)
// 			max = mid;
// 	}
// 	if (iarr[mid] < pin)
// 		return (mid + 1);
// 	return (mid);
// }

size_t	iarr_search_sorted_ins(const int *iarr, size_t iarr_c, int pin)
{
	size_t	min;
	size_t	mid;
	size_t	max;

	min = 0;
	max = iarr_c;
	while (min < max)
	{
		mid = (min + max) / 2;
		if (iarr[mid] < pin)
			min = mid + 1;
		else
			max = mid;
	}
	return (min);
}
// #include <stdio.h>
// int main()
// {
// 	int iarr[] = {1, 2};
// 	// int iarr[] = {10, 20, 30, 40, 50, 60};
// 	size_t iarr_c = sizeof(iarr) / sizeof(int);
// 	int pin = -1;
// 	int res = -1;

// 	res = iarr_search_sorted_ins(iarr, iarr_c, pin);
// 	printf("res: %d\n", res);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:54:47 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:20:05 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_bbsort_carr_from_n(char ***arr, int arr_c, size_t n)
{
	int	count;
	int	swapped;

	count = n;
	swapped = TRUE;
	while (swapped == TRUE)
	{
		swapped = FALSE;
		count = n;
		while (count + 1 < arr_c)
		{
			if (ft_strcmp((*arr)[count], (*arr)[count + 1]) > 0)
			{
				ft_swap_str(&((*arr)[count]), &((*arr)[count + 1]));
				swapped = 1;
			}
			count++;
		}
	}
}

void	ft_bbsort_iarr_from_n(int **arr, int arr_c, size_t n)
{
	int	count;
	int	swapped;

	count = n;
	swapped = TRUE;
	while (swapped == TRUE)
	{
		swapped = FALSE;
		count = n;
		while (count + 1 < arr_c)
		{
			if ((*arr)[count] > (*arr)[count + 1])
			{
				ft_swap_int(&((*arr)[count]), &((*arr)[count + 1]));
				swapped = 1;
			}
			count++;
		}
	}
}

//sorts array 1 (the index), sorts the corresponding array 2 (the content)
void	ft_bbsort_dbl_iarr_from_n(int **arr1, int **arr2, int arr_c, size_t n)
{
	int	count;
	int	swapped;

	count = n;
	swapped = TRUE;
	while (swapped == TRUE)
	{
		swapped = FALSE;
		count = n;
		while (count + 1 < arr_c)
		{
			if ((*arr1)[count] > (*arr1)[count + 1])
			{
				ft_swap_int(&((*arr1)[count]), &((*arr1)[count + 1]));
				ft_swap_int(&((*arr2)[count]), &((*arr2)[count + 1]));
				swapped = 1;
			}
			count++;
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_search.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 14:26:04 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/18 14:26:04 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	binary_search_sorted(int pin, int *s_stack, int size)
{
	int		i;
	int		min;
	int		max;

	if (size < 1)
		return (-1);
	i = size / 2;
	min = 0;
	max = size;
	while ((max - min > 1) && s_stack[i] != pin)
	{
		if (s_stack[i] > pin)
			max = i;
		else if (s_stack[i] < pin)
			min = i;
		i = min + ((max - min) / 2);
	}
	if (s_stack[i] == pin)
		return (i);
	return (-1);
}

// int	binary_search_sorted(int pin, int *s_stack, int size)
// {
// 	int		i;
// 	int		inter;
// 	int		last;

// 	if (size < 1)
// 		return (-1);
// 	i = size / 2;
// 	inter = (size + 1) / 2;
// 	last = 2;
// 	while (inter != 0 && i >= 0 && i < size && s_stack[i] != pin)
// 	{
// 		inter = (inter + 1) / 2;
// 		if (s_stack[i] > pin)
// 			i = i - inter;
// 		else if (s_stack[i] < pin)
// 			i = i + inter;
// 		if (last == 0)
// 			break ;
// 		if (inter == 1)
// 			last -= 1;
// 	}
// 	if (i >= 0 && i < size && s_stack[i] == pin)
// 		return (i);
// 	return (-1);
// }
// #include <stdio.h>
// int main(void)
// {
// 	int arr[101] = {
//     0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
//     10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
//     20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
//     30, 31, 32, 33, 34, 35, 36, 37, 38, 39,
//     40, 41, 42, 43, 44, 45, 46, 47, 48, 49,
//     50, 51, 52, 53, 54, 55, 56, 57, 58, 59,
//     60, 61, 62, 63, 64, 65, 66, 67, 68, 69,
//     70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
//     80, 81, 82, 83, 84, 85, 86, 87, 88, 89,
//     90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
//     100
// 	};

//     int size = sizeof(arr) / sizeof(arr[0]);
// 	// printf("%d", size);
//     for (int pin = -4; pin <= 15; pin++)
//         printf("pin %2d -> index %d\n", pin, 
// binary_search_sorted(pin, arr, size));

//     return 0;
// }
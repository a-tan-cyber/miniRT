/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:43:27 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

size_t	ft_arrlen(const char **arr)
{
	size_t	i;

	i = 0;
	while (arr[i])
	{
		i += 1;
	}
	return (i);
}

void	free_arr(char **arr)
{
	char	**arr_start;

	if (!arr)
		return ;
	arr_start = arr;
	while (*arr)
	{
		free(*arr);
		arr++;
	}
	free(arr_start);
}

// modifies the arr by function applied
void	ft_foreach_arr(char **arr, void (*f)(char **, size_t, size_t))
{
	size_t	i;
	size_t	j;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			f(arr, i, j);
			j++;
		}
		i++;
	}
}

int	ft_checkeach_arr(char **arr, int (*f)(char **, size_t, size_t))
{
	size_t	i;
	size_t	j;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
	{
		j = 0;
		while (arr[i][j])
		{
			if (arr[i][j] == 'F' && f(arr, i, j) == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

// //applies a given function to all elements of an integer array.
// void ft_foreach(int *tab, int length, void(*f)(int))
// {
// 	int i;

// 	i = 0;
// 	while (i < length)
// 	{
// 		f(tab[i]);
// 		i++;
// 	}
// }

// //applies a given function to all elements of an integer array (in order)
// //and returns a new array containing all the return values
// int	*ft_map(int *tab, int length, int(*f)(int))
// {
// 	int *arr;
// 	int i;

// 	if (!tab || length < 1)
// 		return (0);
// 	arr = malloc(length * sizeof(*tab));
// 	if (!arr)
// 		return (0);
// 	i = 0;
// 	while (i < length)
// 	{
// 		arr[i] = f(tab[i]);
// 		i++;
// 	}
// 	return (arr);
// }

// // Create a function ft_any, which returns 1 if,
// when passed to the function f, at
// // least one element of the array returns a value other than 0. Otherwise,
// it should return 0
// int ft_any(char **tab, int(*f)(char*))
// {
// 	int	i;
// 	int v;

// 	i = 0;
// 	while (tab[i])
// 	{
// 		v = f(tab[i]);
// 		if (v)
// 		{
// 			return (1);
// 		}
// 		i++;
// 	}
// 	return (0);
// }

// // returns the number of elements in the array
// // for which the function f does not return 0
// int ft_count_if(char **tab, int length, int(*f)(char*))
// {
// 	int	i;
// 	int c;
// 	int v;

// 	i = 0;
// 	c = 0;
// 	while (i < length)
// 	{
// 		v = f(tab[i]);
// 		if (v)
// 		{
// 			c++;
// 		}
// 		i++;
// 	}
// 	return (c);
// }

// // returns 1 if the array is sorted and 0 if it is not
// int ft_is_sort(int *tab, int length, int(*f)(int, int))
// {
// 	int	i;
// 	int	v;
// 	int ori;

// 	i = 0;
// 	while (i < (length - 1))
// 	{
// 		v = f(tab[i], tab[i + 1]);
// 		if (v != 0)
// 		{
// 			ori = v;
// 			break ;
// 		}
// 		i++;
// 	}
// 	while (i < (length - 1))
// 	{
// 		v = f(tab[i], tab[i + 1]);
// 		if (v != ori && v != 0)
// 		{
// 			return (0);
// 		}
// 		i++;
// 	}
// 	return (1);
// }

// #include "bool/ft_bool.h"
// #include "string/ft_string.h"
// #include "utils/ft_utils.h"

// // sorts the strings in tab in ASCII order.
// void ft_sort_string_tab(char **tab)
// {
// 	int	i;
// 	int	swapped;

// 	swapped = true;
// 	while (swapped == true)
// 	{
// 		swapped = false;
// 		i = 0;
// 		while (tab[i + 1])
// 		{
// 			if (ft_strcmp(tab[i], tab[i + 1]) > 0)
// 			{
// 				ft_swap_str(&tab[i], &tab[i + 1]);
// 				swapped = true;
// 			}
// 			i++;
// 		}
// 	}
// }

//
// sorts depending on the return value of the function provided as an argument.
// void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
// {
// 	int	i;
// 	int	swapped;

// 	swapped = true;
// 	while (swapped == true)
// 	{
// 		swapped = false;
// 		i = 0;
// 		while (tab[i + 1])
// 		{
// 			if (cmp(tab[i], tab[i + 1]) > 0)
// 			{
// 				ft_swap_str(&tab[i], &tab[i + 1]);
// 				swapped = true;
// 			}
// 			i++;
// 		}
// 	}
// }
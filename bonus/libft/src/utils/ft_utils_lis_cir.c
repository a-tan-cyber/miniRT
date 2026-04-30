/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lis_cir.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 18:24:01 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/04 00:03:19 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// #include <stdlib.h>
// #include <stdio.h>
// typedef int	t_bool;
// // # define true 1
// // # define false 0
// # define TRUE 1
// # define FALSE 0

// static void	*ft_calloc(size_t len, size_t size)
// {
// 	void	*dest;
// 	size_t	max_size;
// 	size_t	i;
// 	char	*d;

// 	if ((len > 0) && (SIZE_MAX / len) < size)
// 		return (NULL);
// 	max_size = len * size;
// 	dest = malloc(max_size);
// 	if (!dest)
// 		return (NULL);
// 	d = (char *)dest;
// 	i = 0;
// 	while (i < max_size)
// 	{
// 		d[i] = 0;
// 		i++;
// 	}
// 	return (dest);//
// }

// size_t	ft_iarr_cpy(int *dest, const int *src, size_t iarr_c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < iarr_c)
// 	{
// 		dest[i] = src[i];
// 		i++;
// 	}
// 	return (i);
// }

// int	ft_max(int n1, int n2)
// {
// 	if (n1 < n2)
// 		return (n2);
// 	return (n1);
// }
// size_t	iarr_search_sorted_ins(const int *iarr, size_t iarr_c, int pin)
// {
// 	size_t	min;
// 	size_t	mid;
// 	size_t	max;

// 	min = 0;
// 	max = iarr_c;
// 	while (min < max)
// 	{
// 		mid = (min + max) / 2;
// 		if (iarr[mid] < pin)
// 			min = mid + 1;
// 		else
// 			max = mid;
// 	}
// 	return (min);
// }

// static void	iarr_lis_unique_fun_cpy(const int *iarr, size_t tmp_c,
// 	int *res, int *idx)
// {
// 	size_t	i;
// 	size_t	j;

// 	j = res[tmp_c - 1];
// 	i = tmp_c;
// 	while (i > 0)
// 	{
// 		i--;
// 		res[i] = j;
// 		j = idx[j];
// 	}
// 	ft_iarr_cpy(idx, res, tmp_c);
// 	i = 0;
// 	while (i < tmp_c)
// 	{
// 		res[i] = iarr[idx[i]];
// 		i++;
// 	}
// }

// static size_t	iarr_lis_unique_fun(const int *iarr, size_t iarr_c,
// 	int *res, int *idx)
// {
// 	int		*res_val;
// 	size_t	tmp_c;
// 	size_t	i;
// 	size_t	j;

// 	res_val = ft_calloc(iarr_c, sizeof(int));
// 	if (!res_val)
// 		return (0);
// 	tmp_c = 0;
// 	i = 0;
// 	j = 0;
// 	while (i < iarr_c)
// 	{
// 		j = iarr_search_sorted_ins(res_val, tmp_c, iarr[i]);
// 		idx[i] = -1;
// 		if (j > 0)
// 			idx[i] = res[j - 1];
// 		tmp_c = ft_max(j + 1, tmp_c);
// 		res_val[j] = iarr[i];
// 		res[j] = i;
// 		i++;
// 	}
// 	iarr_lis_unique_fun_cpy(iarr, tmp_c, res, idx);
// 	free(res_val);
// 	return (tmp_c);
// }

// size_t	iarr_lis_unique(const int *iarr, size_t iarr_c, int *res, int *idx)
// {
// 	int		*f_res;
// 	int		*f_idx;
// 	size_t	tmp_c;

// 	if (!iarr || iarr_c == 0)
// 		return (0);
// 	f_res = NULL;
// 	f_idx = NULL;
// 	tmp_c = 0;
// 	if (!res)
// 	{
// 		f_res = ft_calloc(iarr_c, sizeof(int));
// 		res = f_res;
// 	}
// 	if (!idx)
// 	{
// 		f_idx = ft_calloc(iarr_c, sizeof(int));
// 		idx = f_idx;
// 	}
// 	if (res && idx)
// 		tmp_c = iarr_lis_unique_fun(iarr, iarr_c, res, idx);
// 	free(f_res);
// 	free(f_idx);
// 	return (tmp_c);
// }

// void	ft_print_iarr(const int *iarr, size_t iarr_c, char *name)
// {
// 	size_t	i;

// 	printf("%s: {", name);
// 	i = 0;
// 	while (i + 1 < iarr_c)
// 	{
// 		printf("% d, ", iarr[i]);
// 		i++;
// 	}
// 	printf("% d}\n", iarr[i]);	
// }

// void	ft_swap_int(int *a, int *b)
// {
// 	int	temp;

// 	temp = *a;
// 	*a = *b;
// 	*b = temp;
// }

// //sorts array 1 (the index), sorts the corresponding array 2 (the content)
// void	ft_bbsort_dbl_iarr_from_n(int **arr1, int **arr2, int arr_c, size_t n)
// {
// 	int	count;
// 	int	swapped;

// 	count = n;
// 	swapped = TRUE;
// 	while (swapped == TRUE)
// 	{
// 		swapped = FALSE;
// 		count = n;
// 		while (count + 1 < arr_c)
// 		{
// 			if ((*arr1)[count] > (*arr1)[count + 1])
// 			{
// 				ft_swap_int(&((*arr1)[count]), &((*arr1)[count + 1]));
// 				ft_swap_int(&((*arr2)[count]), &((*arr2)[count + 1]));
// 				swapped = 1;
// 			}
// 			count++;
// 		}
// 	}
// }

void	shift_cir_idx(int *idx, size_t idx_c, size_t offset, size_t bounds)
{
	size_t	j;

	j = 0;
	while (j < idx_c)
	{
		if (idx[j] + offset >= bounds)
			idx[j] += offset - bounds;
		else
			idx[j] += offset;
		j++;
	}
}

static void	fetch_res_from_idx(int *res, int *idx, const int *iarr,
			size_t idx_c)
{
	size_t	i;

	i = 0;
	while (i < idx_c)
	{
		res[i] = iarr[idx[i]];
		i++;
	}
	ft_bbsort_dbl_iarr_from_n(&idx, &res, idx_c, 0);
}

// vars[3]: vars[0] = i; vars[1] = temp; vars[2] = max
static size_t	iarr_lis_cir_unique_fun(const int *iarr, size_t iarr_c,
				int *res, int *idx)
{
	int		*cir_arr;
	int		*max_idx;
	size_t	vars[3];

	cir_arr = ft_calloc(iarr_c * 2, sizeof(int));
	max_idx = ft_calloc(iarr_c, sizeof(int));
	if (!cir_arr || !max_idx)
		return (free(cir_arr), free(max_idx), 0);
	ft_iarr_cpy_mul(cir_arr, 2, iarr, iarr_c);
	vars[0] = 0;
	vars[2] = 0;
	while (vars[0] < iarr_c)
	{
		vars[1] = iarr_lis_unique(cir_arr + vars[0], iarr_c, res, idx);
		if (vars[1] > vars[2])
		{
			ft_iarr_cpy(max_idx, idx, vars[1]);
			shift_cir_idx(max_idx, vars[1], vars[0], iarr_c);
			vars[2] = vars[1];
		}
		vars[0]++;
	}
	ft_iarr_cpy(idx, max_idx, vars[2]);
	fetch_res_from_idx(res, idx, iarr, vars[2]);
	return (free(cir_arr), free(max_idx), vars[2]);
}

// static size_t	iarr_lis_cir_unique_fun(const int *iarr, size_t iarr_c,
// 				int *res, int *idx)
// {
// 	int		*cir_arr;
// 	int		*max_res;
// 	int		*max_idx;
// 	size_t	i;
// 	// size_t	j;
// 	size_t	temp;
// 	size_t	max;

// 	cir_arr = ft_calloc(iarr_c * 2, sizeof(int));
// 	if (!cir_arr)
// 		return (0);
// 	max_res = ft_calloc(iarr_c, sizeof(int));
// 	if (!max_res)
// 		return (free(cir_arr), 0);
// 	max_idx = ft_calloc(iarr_c, sizeof(int));
// 	if (!max_idx)
// 		return (free(cir_arr), free(max_res), 0);
// 	ft_iarr_cpy(cir_arr, iarr, iarr_c);
// 	ft_iarr_cpy(cir_arr + iarr_c, iarr, iarr_c);
// 	i = 0;
// 	max = 0;
// 	while (i < iarr_c)
// 	{
// 		temp = iarr_lis_unique(cir_arr + i, iarr_c, res, idx);
// 		if (temp > max)
// 		{
// 			ft_iarr_cpy(max_res, res, temp);
// 			ft_iarr_cpy(max_idx, idx, temp);
// 			// each item + i
// 			for (size_t j = 0; j < temp; j++)
// 			{
// 				if (max_idx[j] + i >= iarr_c)
// 					max_idx[j] += i - iarr_c;
// 				else
// 					max_idx[j] += i;
// 			}			
// 			max = temp;
// 		}
// 		i++;
// 	}
// 	ft_iarr_cpy(res, max_res, max);
// 	ft_iarr_cpy(idx, max_idx, max);
// 	ft_bbsort_dbl_iarr_from_n(&idx, &res, max, 0);
// 	return (free(cir_arr), free(max_res), free(max_idx), max);
// }

size_t	iarr_lis_cir_unique(const int *iarr, size_t iarr_c, int *res, int *idx)
{
	int		*f_res;
	int		*f_idx;
	size_t	tmp_c;

	if (!iarr || iarr_c == 0)
		return (0);
	f_res = NULL;
	f_idx = NULL;
	tmp_c = 0;
	if (!res)
	{
		f_res = ft_calloc(iarr_c, sizeof(int));
		res = f_res;
	}
	if (!idx)
	{
		f_idx = ft_calloc(iarr_c, sizeof(int));
		idx = f_idx;
	}
	if (res && idx)
		tmp_c = iarr_lis_cir_unique_fun(iarr, iarr_c, res, idx);
	free(f_res);
	free(f_idx);
	return (tmp_c);
}

// int main()
// {
// 	int iarr[] = {3, 5, 2, 1, 4}; // 1 4 5
// 	size_t iarr_c = sizeof(iarr) / sizeof(int);
// 	int res[100] = {0};
// 	int idx[100] = {0};
// 	int j = 0;
// 	size_t i = iarr_lis_cir_unique(iarr, iarr_c, res, idx);
// 	printf("size: %d\n", i);
// 	ft_print_iarr(res, i, "res: ");
// 	ft_print_iarr(idx, i, "idx: ");
// }

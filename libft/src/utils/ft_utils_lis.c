/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_lis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 09:11:23 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/23 09:11:23 by yunguo           ###   ########.fr       */
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

// // size_t	iarr_lis_unique(const int *iarr, 
// size_t iarr_c, int *res, int *idx)
// // {
// // 	int		*res_idx = ft_calloc(iarr_c, sizeof(int));
// // 	size_t	tmp_c;
// // 	size_t	i;
// // 	size_t	j;

// // 	tmp_c = 0;
// // 	i = 0;
// // 	j = 0;
// // 	while (i < iarr_c)
// // 	{
// // 		j = iarr_search_sorted_ins(res, tmp_c, iarr[i]);
// // 		if (j > 0)
// // 			idx[i] = res_idx[j - 1];
// // 		else
// // 			idx[i] = -1;
// // 		if (j + 1 > tmp_c)
// // 			tmp_c = j + 1;
// // 		res[j] = iarr[i];
// // 		res_idx[j] = i;
// // 		i++;
// // 	}
// // 	// ft_print_iarr(iarr, iarr_c, "iarr");
// // 	// ft_print_iarr(res, (size_t)tmp_c, "res ");
// // 	// ft_print_iarr(res_idx, (size_t)tmp_c, "resi");
// // 	// ft_print_iarr(idx, iarr_c, "idx ");
// // 	// printf("\n");
// // 	j = res_idx[tmp_c - 1];
// // 	i = tmp_c;
// // 	while (i > 0)
// // 	{
// // 		i--;
// // 		res[i] = iarr[j];
// // 		res_idx[i] = j;
// // 		j = idx[j];
// // 	}
// // 	// res[i] = iarr[j];
// // 	// res_idx[i] = j;
// // 	// ft_print_iarr(res, (size_t)tmp_c, "res ");
// // 	// ft_print_iarr(res_idx, (size_t)tmp_c, "resi");
// // 	// ft_print_iarr(iarr, iarr_c, "iarr");
// // 	// ft_print_iarr(idx, iarr_c, "idx ");
// // 	// printf("\n");
// // 	i = 0;
// // 	while (i < tmp_c)
// // 	{
// // 		idx[i] = res_idx[i];
// // 		i++;
// // 	}
// // 	// ft_safefree(res_idx);
// // 	free(res_idx);
// // 	return (tmp_c);
// // }

// void	ft_safefree(void *ptr)
// {
// 	free(ptr);
// 	ptr = NULL;
// }

// int	ft_max(int n1, int n2)
// {
// 	if (n1 < n2)
// 		return (n2);
// 	return (n1);
// }

// size_t	ft_iarr_cpy(int *dest, int *src, size_t iarr_c)
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

static void	iarr_lis_unique_fun_cpy(const int *iarr, size_t tmp_c,
	int *res, int *idx)
{
	size_t	i;
	size_t	j;

	j = res[tmp_c - 1];
	i = tmp_c;
	while (i > 0)
	{
		i--;
		res[i] = j;
		j = idx[j];
	}
	ft_iarr_cpy(idx, res, tmp_c);
	i = 0;
	while (i < tmp_c)
	{
		res[i] = iarr[idx[i]];
		i++;
	}
}

static size_t	iarr_lis_unique_fun(const int *iarr, size_t iarr_c,
	int *res, int *idx)
{
	int		*res_val;
	size_t	tmp_c;
	size_t	i;
	size_t	j;

	res_val = ft_calloc(iarr_c, sizeof(int));
	if (!res_val)
		return (0);
	tmp_c = 0;
	i = 0;
	j = 0;
	while (i < iarr_c)
	{
		j = iarr_search_sorted_ins(res_val, tmp_c, iarr[i]);
		idx[i] = -1;
		if (j > 0)
			idx[i] = res[j - 1];
		tmp_c = ft_max(j + 1, tmp_c);
		res_val[j] = iarr[i];
		res[j] = i;
		i++;
	}
	iarr_lis_unique_fun_cpy(iarr, tmp_c, res, idx);
	free(res_val);
	return (tmp_c);
}

size_t	iarr_lis_unique(const int *iarr, size_t iarr_c, int *res, int *idx)
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
		tmp_c = iarr_lis_unique_fun(iarr, iarr_c, res, idx);
	free(f_res);
	free(f_idx);
	return (tmp_c);
}

// #include <stdio.h>
// int main()
// {
// 	// int iarr[] = {1, 2, -1, 5, -2, -3, 7, -5}; //0136
// 	int iarr[] = {50, 10}; //0136
// 	size_t iarr_c = sizeof(iarr) / sizeof(int);

// 	int res[100] = {0};
// 	int idx[100] = {0};
// 	int j = 0;
// 	size_t i = iarr_lis_unique(iarr, iarr_c, res, idx);
// 	printf("size: %d\n", i);
// 	ft_print_iarr(res, i, "res: ");
// 	ft_print_iarr(idx, i, "idx: ");
// }

// size_t	iarr_lis_unique(const int *iarr, size_t iarr_c, int *res, int *idx)
// {
// 	size_t	i;
// 	size_t	j;
// 	int		prev;
// 	int		prev_i;
// 	int		*tmp;
// 	size_t	len;

// 	if (!iarr)
// 		return (0);
// 	tmp = ft_calloc(iarr_c, sizeof(int));
// 	if (!tmp)
// 		return (0);
// 	prev = INT_MIN;
// 	len = 0;
// 	i = 0;
// 	prev_i = -1;
// 	idx[0] = i;
// 	int tmp_c = 0;
// 	while (i < iarr_c)
// 	{
// 		j = search_insf_unique(tmp, len, iarr[i]);
// 		if (idx)
// 		{
// 			if (j == 0)
// 				idx[len] = -1;
// 			else
// 			{
// 				idx[len] = prev_i;
// 			}
// 		}
// 		if (tmp[len - 1] > iarr[i])
// 		{
// 			// printf("idx: %d\n", idx[len]);
// 			// printf("res: %d\n", len);
// 			// printf("res: %d\n",res[len]);
// 			if (tmp_c < j)
// 				tmp_c = j;
// 			tmp[j] = iarr[i];
// 			prev = iarr[i];
// 			prev_i = i;
// 			j++;
// 		}
// 		i++;
// 		len++;
// 	}
// 	// if (res)
// 	// {
// 	// 	size_t res_c = cpy_lis_by_idx(iarr, res, idx, iarr_c);
// 	//	
// 	// }
// 	printf("tmp: ");
// 	int z = 0;
// 	while (z < tmp_c)
// 	{
// 		printf("%d, ", tmp[z]);
// 		z++;
// 	}
// 	printf("last ele: %d\n", prev_i);
// 	free(tmp);
// 	// i = iarr_lis_unique_run(iarr, iarr_c, res, idx);
// 	return (len);
// }

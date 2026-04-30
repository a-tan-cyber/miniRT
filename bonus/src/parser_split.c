/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:19:29 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 21:20:36 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	**split_3_float(const char *string, const char *charset)
{
	char	**arr;

	if (!string || !charset)
		return (NULL);
	arr = ft_split(string, charset);
	if (!arr)
		return (ft_puterr("malloc failed"), NULL);
	if (ft_arrlen((const char **)arr) != 3)
		return (ft_puterr("wrong no. of vector"), free_arr(arr), NULL);
	if (!ft_str_is_float(arr[0]) || !ft_str_is_float(arr[1])
		|| !ft_str_is_float(arr[2]))
		return (ft_puterr("vector or ori is not float"), free_arr(arr), NULL);
	return (arr);
}

char	**split_3_double_range(const char *string, const char *charset,
			double min, double max)
{
	char	**arr;
	double	curr;

	arr = split_3_float(string, charset);
	if (!arr)
		return (NULL);
	curr = ft_atod(arr[0]);
	if (curr < min || max < curr)
		return (ft_puterr("double number x out of range"), free_arr(arr), NULL);
	curr = ft_atod(arr[1]);
	if (curr < min || max < curr)
		return (ft_puterr("double number y out of range"), free_arr(arr), NULL);
	curr = ft_atod(arr[2]);
	if (curr < min || max < curr)
		return (ft_puterr("double number z out of range"), free_arr(arr), NULL);
	return (arr);
}

char	**split_3_int(const char *string, const char *charset)
{
	char	**arr;

	if (!string || !charset)
		return (NULL);
	arr = ft_split(string, charset);
	if (!arr)
		return (ft_puterr("malloc failed"), NULL);
	if (ft_arrlen((const char **)arr) != 3)
		return (ft_puterr("wrong no. of int (rgb)"), free_arr(arr), NULL);
	if (!ft_str_is_int(arr[0]) || !ft_str_is_int(arr[1])
		|| !ft_str_is_int(arr[2]))
		return (ft_puterr("rgb is not int"), free_arr(arr), NULL);
	return (arr);
}

char	**split_3_int_range(const char *string, const char *charset,
			const char *min_str, const char *max_str)
{
	char	**arr;
	int		curr;
	int		min;
	int		max;

	arr = split_3_int(string, charset);
	if (!arr)
		return (NULL);
	min = ft_atoi(min_str);
	max = ft_atoi(max_str);
	curr = ft_atoi(arr[0]);
	if (curr < min || max < curr)
		return (ft_puterr("int number r out of range"), free_arr(arr), NULL);
	curr = ft_atoi(arr[1]);
	if (curr < min || max < curr)
		return (ft_puterr("int number g out of range"), free_arr(arr), NULL);
	curr = ft_atoi(arr[2]);
	if (curr < min || max < curr)
		return (ft_puterr("int number b out of range"), free_arr(arr), NULL);
	return (arr);
}

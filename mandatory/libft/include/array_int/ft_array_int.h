/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_int.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:40:42 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_INT_H
# define FT_ARRAY_INT_H

# include <stddef.h>

// ft_iarr_chk.c
int		ft_iarr_chkrep(int **arr, size_t arr_c);
int		ft_iarr_chkrep_sorted(int *iarr, size_t arr_c);
size_t	iarr_search_sorted_ins(const int *iarr, size_t iarr_c, int pin);

// ft_iarr_cpy.c
size_t	ft_iarr_cpy(int *dest, const int *src, size_t iarr_c);
void	ft_iarr_cpy_mul(int *iarr_mul, size_t times, const int *iarr,
			size_t iarr_c);

// ft_iarr_print.c
// void	ft_print_iarr(char *name, const int *iarr, size_t iarr_c);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/04 00:04:55 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_UTILS_H
# define FT_UTILS_H

# include <stddef.h>

// ft_utils_free.c
void	ft_sfree(void **ptr);

// ft_utils_hexdump.c
void	ft_phd_offset(unsigned int value);
void	ft_phd_hex(void *addr, unsigned int size, unsigned int c_perline);
void	ft_phd_txt(void *addr, unsigned int size);
void	*ft_print_hexdump(void *addr, unsigned int size, unsigned int offset);

// ft_utils_lis.c
size_t	iarr_lis_unique(const int *iarr, size_t iarr_c, int *res, int *idx);

// ft_utils_lis_cir.c
size_t	iarr_lis_cir_unique(const int *iarr, size_t iarr_c, int *res, int *idx);

// ft_utils_pmem.c
void	ft_print_m(void *addr);
void	ft_print_hc(void *addr, unsigned int size);
void	*ft_print_memory(void *addr, unsigned int size);

// ft_utils_search.c
int		binary_search_sorted(int pin, int *s_stack, int size);

// ft_utils_sort.c
void	ft_bbsort_carr_from_n(char ***arr, int arr_c, size_t n);
void	ft_bbsort_iarr_from_n(int **arr, int arr_c, size_t n);
void	ft_bbsort_dbl_iarr_from_n(int **arr1, int **arr2, int arr_c, size_t n);

// ft_utils_x.c
void	ft_swap_int(int *a, int *b);
void	ft_swap_str(char **a, char **b);

#endif
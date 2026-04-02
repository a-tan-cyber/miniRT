/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:40:12 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

size_t	ft_arrlen(const char **arr);
void	free_arr(char **arr);
void	ft_foreach_arr(char **arr, void (*f)(char **, size_t, size_t));
int		ft_checkeach_arr(char **arr, int (*f)(char **, size_t, size_t));

// void ft_foreach(int *tab, int length, void(*f)(int));
// int	*ft_map(int *tab, int length, int(*f)(int));
// int ft_any(char **tab, int(*f)(char*));
// int ft_count_if(char **tab, int length, int(*f)(char*));
// int ft_is_sort(int *tab, int length, int(*f)(int, int));
// void ft_sort_string_tab(char **tab);
// void ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

// ft_array_chk.c
int		ft_iarr_chkrep(int **arr, size_t arr_c);
int		ft_iarr_chkrep_sorted(int *iarr, size_t arr_c);
size_t	iarr_search_ins(const int *iarr, size_t iarr_c, int pin);

// ft_array_cmp.c
int		ft_arr_is_subset(const char **arr, char *set);

// ft_array_cnt.c
int		ft_count_cina(const char **arr, char c);

// ft_array_cpy.c
int		ft_arrcpy(char ***dest, const char **src);

// ft_array_cvt.c
int		*arr_to_iarr(char **arr, size_t arr_c);

// ft_array_dup.c
char	**ft_arrdup(const char **arr);
int		ft_arrdup_mk2(char ***dest, const char **src);
int		*ft_iarrdup(int *iarr, size_t arr_c);

// ft_array_iss.c
int		ft_is_rect(const char **arr);

// ft_array_v.c
int		arr_is_int(char **arr, size_t arr_c);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:42:44 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# include "../bool/ft_bool.h"
// # define ABS(Value) ((Value) < 0 ? -(Value) : (Value))

// ft_math_c.c
int		ft_find_num_len(int n);

// ft_math_m.c
int		ft_max(int n1, int n2);
int		ft_min(int n1, int n2);

// ft_math_u.c
int		ft_factorial(int nb);
int		ft_power(int nb, int power);
int		ft_fibonacci(int index);
int		ft_sqrt(int nb);
int		ft_range(int **range, int min, int max);

// ft_math_p.c
int		ft_is_prime(int nb);
int		ft_find_next_prime(int nb);

// ft_math_v.c
t_bool	int_is_odd(int n);
t_bool	int_is_even(int n);

#endif
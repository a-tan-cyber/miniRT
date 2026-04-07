/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_float.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:46:32 by amtan             #+#    #+#             */
/*   Updated: 2026/04/06 15:57:09 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FLOAT_H
# define FT_FLOAT_H

int		ft_str_is_float(const char *s);
float	ft_atof(const char *s);
int		ft_is_space(char c);
int		ft_is_digit(char c);
int		ft_skip_space(const char *s, int i);
void	ft_read_frac(const char *s, int *i, float *nb);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:41:22 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

# include "../bool/ft_bool.h"

// ctype.c
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_is_white_space(char base);
// int	ft_isprint(int c);

// ctype_special.c
t_bool			is_operator(char c);
t_bool			is_bracket(char c);

//strtobit.c
char			*ft_conv_chartobitstr(unsigned char x, char *byte);
char			*ft_conv_strtobitstr(char *msg, char *bitstr);
unsigned char	ft_conv_bitstrtochar(char *byte);

#endif
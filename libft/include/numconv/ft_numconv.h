/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconv.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:46:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NUMCONV_H
# define FT_NUMCONV_H

// ft_numconv_str.c
// ft_atoi diff fulfillment
int		ft_atoi(char *str);
// caller free()
char	*ft_itoa(int n);
char	*ft_itoa_fast(int n, char *dest);
char	*ft_ldtoa(long long n);
// //base to int
// int 	ft_btoi(char *str, char *base);
// //int to base
// char    *ft_itob(int n, char *base);
// //base to base
// char    *ft_btob(char *nbr, char *base_from, char *base_to);
// //pointer to malloc'd str
// char	*ft_ptoa(void *addr);
// //unsigned int to hex
// char	*ft_uitoh(unsigned int u);

// ft_numconv_base.c
// putnbr long long n, no validity check
void	ft_print_in_base(long long n, char *base, int base_size);
// convert int n to string in base
void	ft_convert_to_base(int n, char *base, int base_size,
			char *base_nbr_string);
// checks base for validity and prints base
void	ft_putnbr_base(int nbr, char *base);
int		base_to_int(char *str, char *base);

// ft_numconv_hex.c
void	ft_num_to_2hex(unsigned int i);

#endif
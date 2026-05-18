/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:46:58 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIT_H
# define FT_BIT_H

// //ft_bit_set.c
// typedef struct
// {
//     const void      *buf;
//     size_t          buf_len;
//     size_t          elem_size;
//     unsigned char   *mask;
//     size_t          mask_bitlen;
//     unsigned int    (*get_index)(const void *elem)
// } s_btmsk_param;

// ft_bit_set.c
int		ft_btmsk_cins(const char c, const char *str);
int		ft_btmsk_ckrep_str(char *word, unsigned char *mask);
void	ft_btmsk_cins_cm(const char *str, unsigned char *mask);
int		ft_btmsk_cins_mm(const char c, const unsigned char *mask);
// int	ft_str_is_subset(char *pool, char *legal);
// int	ft_btmsk_ckrep_any(const s_btmsk_param *p);

#endif
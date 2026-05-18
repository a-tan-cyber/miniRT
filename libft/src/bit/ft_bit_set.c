/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:06:27 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include "../../include/bit/ft_bit.h"
#include "../../include/string/ft_string.h"

int	ft_btmsk_cins(char c, const char *str)
{
	unsigned char	mask[32];
	int				a;

	ft_memset(mask, 0, 32);
	a = (unsigned char)c;
	mask[a / 8] = mask[a / 8] | (1u << (a % 8));
	while (*str)
	{
		a = (unsigned char)*str;
		if ((mask[a / 8]) & (1u << (a % 8)))
			return (1);
		str++;
	}
	return (0);
}

void	ft_btmsk_cins_cm(const char *str, unsigned char *mask)
{
	int	a;

	while (*str)
	{
		a = (unsigned char)*str;
		mask[a / 8] = (mask[a / 8]) | (1u << (a % 8));
		str++;
	}
}

int	ft_btmsk_cins_mm(const char c, const unsigned char *mask)
{
	int	a;

	a = (unsigned char)c;
	if (mask[a / 8] & (1u << (a % 8)))
	{
		return (1);
	}
	return (0);
}

// int ft_btmsk_cins(char c, const char *str)
// {
//     unsigned char mask[32] = {0};
//     int a;

//     while (*str)
//     {
//         a = (unsigned char)*str;
//         mask[a / 8] = (mask[a / 8]) | (1u << (a % 8));
//         str++;
//     }
//     a = (unsigned char)c;
//     if (mask[a / 8] & (1u << (a % 8)))
//     {
//         return (1);
//     }
//     return (0);
// }

// 1 = word string has repeated char
// mask use "unsigned char mask[32] = {0};" for ASCII
int	ft_btmsk_ckrep_str(char *word, unsigned char *mask)
{
	unsigned char	*c;

	while (*word)
	{
		c = (unsigned char *)word;
		if ((mask[*c / 8]) & (1U << (*c % 8)))
			return (1);
		else
			mask[*c / 8] = mask[*word / 8] | (1U << (*c % 8));
		word++;
	}
	return (0);
}

// int	ft_str_is_subset(char *pool, char *legal)
// {
// 	unsigned char	l_mask[32];
// 	int				c;

// 	ft_memset(l_mask, 0, 32);
//     while (*legal)
//     {
//         c = (unsigned char)*legal;
//         l_mask[c / 8] = (l_mask[c / 8]) | (1u << (c % 8));
//         legal++;
//     }
//     while (*pool)
//     {
// 		c = (unsigned char)*pool;
//         if (((l_mask[c / 8]) & (1U << (c % 8))) == 0)
//             return (0);
//         pool++;
//     }
//     return (1);
// }

/* typedef struct
{
	const void      *buf;
	size_t          buf_len;
	size_t          elem_size;
	unsigned char   *mask;
	size_t          mask_bitlen;
	unsigned int    (*get_index)(const void *elem);
}				s_btmsk_param;
 */

/*
unsigned int	get_index_struct(const void *elem)
{
	return (((const s_struct*)elem)->id);
}
 */

// int	ft_btmsk_ckrep_any(const s_btmsk_param *p)
// {
//     size_t          i;
//     size_t          c;
//     unsigned char   *mask;
//     int             created_mask;

//     created_mask = 0;
//     mask = p->mask;
//     if (!mask)
//     {
//         mask = ft_calloc(((p->mask_bitlen + 7) / 8), 1);
//         if (!mask)
//             return (-1);
//         created_mask = 1;
//     }
//     i = 0;
//     while (i < p->buf_len)
//     {
//         c = p->get_index(p->buf + (i++ * p->elem_size));
//         if (mask[c / 8] & (1u << (c % 8)))
//             return (1);
//         mask[c / 8] |= 1u << (c % 8);
//     }
//     if (created_mask)
//         free(mask);
//     return (0);
// }
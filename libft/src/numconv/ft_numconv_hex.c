/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconv_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:03:20 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_num_to_2hex(unsigned int i)
{
	unsigned int	tens;
	unsigned int	ones;
	char			*hex_str;

	hex_str = "0123456789abcdef";
	tens = i / 16;
	ones = i % 16;
	write(1, &hex_str[tens], 1);
	write(1, &hex_str[ones], 1);
}

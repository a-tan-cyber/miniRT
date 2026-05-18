/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtobit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 23:56:30 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/11 00:11:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_conv_chartobitstr(unsigned char x, char *byte)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((x >> (1u * (7 - i)) & 1) == 1)
			byte[i] = '1';
		else
			byte[i] = '0';
		i++;
	}
	byte[i] = '\0';
	return (byte);
}

char	*ft_conv_strtobitstr(char *msg, char *bitstr)
{
	char	byte[8 + 1];
	size_t	i;

	i = 0;
	while (msg[i])
	{
		ft_conv_chartobitstr((unsigned char)msg[i], byte);
		ft_memcpy(bitstr + (i * 8), byte, 8);
		i++;
	}
	ft_conv_chartobitstr((unsigned char)msg[i], byte);
	ft_memcpy(bitstr + (i * 8), byte, 8);
	i++;
	bitstr[i * 8] = '\0';
	return (bitstr);
}

unsigned char	ft_conv_bitstrtochar(char *byte)
{
	int	i;
	int	c;

	i = 0;
	c = 0;
	while (i < 8)
	{
		if (byte[i] == '1')
		{
			c = c << 1u | 1;
		}
		else
			c = c << 1u | 0;
		i++;
	}
	return ((unsigned char)c);
}

// unsigned char	ft_conv_bitstrtochar(char *byte)
// {
// 	int	i;
// 	int	c;

// 	if (ft_strlen(byte) != 8)
// 		return (0);
// 	i = 7;
// 	c = 0;
// 	while (i >= 0)
// 	{
// 		if (byte[i] == '1')
// 		{
// 			c += ft_power(2, 7 - i);
// 		}
// 		i--;
// 	}
// 	return ((unsigned char)c);
// }

// #include <stdio.h>
// int	main()
// {
// 	unsigned char c = ft_conv_bitstrtochar("11111111");
// 	printf("%d\n", (int)c);
// 	return (0);
// }
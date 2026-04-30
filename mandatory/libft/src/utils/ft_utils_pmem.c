/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_pmem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:54:51 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 15:11:02 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

/*
void	ft_print_in_base(long long n, char *base, int base_size)
{
	if (n >= base_size)
	{
		ft_print_in_base(n / base_size, base, base_size);
	}
	write(1, &base[n % base_size], 1);
	return ;
}
 */
/*
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
 */

void	ft_print_m(void *addr)
{
	int			count;
	char		hex_str[17];
	long long	value;
	long long	temp_value;

	ft_strcpy(hex_str, "0123456789abcdef");
	value = (uintptr_t)addr;
	temp_value = value;
	count = 0;
	while (temp_value > 15)
	{
		temp_value /= 16;
		count++;
	}
	count++;
	write(1, "0000000000000000", 16 - count);
	ft_print_in_base(value, hex_str, 16);
	write(1, ": ", 2);
}

void	ft_print_hc(void *addr, unsigned int size)
{
	int	c;

	c = -1;
	while (c++ < 15)
	{
		if (c < (int)size)
			ft_num_to_2hex(((unsigned char *)addr)[c]);
		else
			write(1, "  ", 2);
		if (c % 2 == 1)
			write(1, " ", 1);
	}
	c = -1;
	while (c++ < (int)size - 1)
	{
		if (32 <= (((unsigned char *)addr)[c])
			&& (((unsigned char *)addr)[c]) <= 126)
			write(1, &((unsigned char *)addr)[c], 1);
		else
			write(1, ".", 1);
	}
	write(1, "\n", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	int		count;
	void	*addr_start;

	addr_start = addr;
	count = size;
	while (count > 16)
	{
		ft_print_m(addr);
		ft_print_hc(addr, 16);
		addr = (unsigned char *)addr + 16;
		count -= 16;
	}
	if (count > 0)
	{
		ft_print_m(addr);
		ft_print_hc(addr, count);
	}
	return (addr_start);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_hexdump.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:54:41 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:19:48 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
// #include <stdint.h>
// #include <sys/stat.h>
// #include <unistd.h>

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

void	ft_phd_offset(unsigned int value)
{
	int				count;
	char			hex_str[17];
	unsigned int	temp_value;

	ft_strcpy(hex_str, "0123456789abcdef");
	temp_value = value;
	count = 0;
	while (temp_value > 15)
	{
		temp_value /= 16;
		count++;
	}
	count++;
	write(1, "00000000", 8 - count);
	ft_print_in_base(value, hex_str, 16);
	write(1, "  ", 2);
}

void	ft_phd_hex(void *addr, unsigned int size, unsigned int c_perline)
{
	unsigned int	c;
	unsigned int	bound;

	c = 0;
	bound = (int)size;
	while (c < bound)
	{
		ft_num_to_2hex(((unsigned char *)addr)[c]);
		write(1, " ", 1);
		if ((c + 1) % 8 == 0)
			write(1, " ", 1);
		c++;
	}
	while (c < c_perline)
	{
		write(1, "  ", 2);
		write(1, " ", 1);
		if ((c + 1) % 8 == 0)
			write(1, " ", 1);
		c++;
	}
}

void	ft_phd_txt(void *addr, unsigned int size)
{
	int	c;

	c = 0;
	write(1, "|", 1);
	while (c < (int)size)
	{
		if (32 <= (((unsigned char *)addr)[c])
			&& (((unsigned char *)addr)[c]) <= 126)
			write(1, &((unsigned char *)addr)[c], 1);
		else
			write(1, ".", 1);
		c++;
	}
	write(1, "|", 1);
	write(1, "\n", 1);
}

void	*ft_print_hexdump(void *addr, unsigned int size, unsigned int offset)
{
	unsigned int	count;
	void			*addr_start;
	unsigned int	c_perline;

	c_perline = 16;
	addr_start = addr;
	count = size;
	while (count > c_perline)
	{
		ft_phd_offset(offset);
		ft_phd_hex(addr, c_perline, c_perline);
		ft_phd_txt(addr, c_perline);
		addr = (unsigned char *)addr + c_perline;
		count -= c_perline;
	}
	if (count > 0)
	{
		ft_phd_offset(offset);
		ft_phd_hex(addr, count, c_perline);
		ft_phd_txt(addr, count);
	}
	return (addr_start);
}

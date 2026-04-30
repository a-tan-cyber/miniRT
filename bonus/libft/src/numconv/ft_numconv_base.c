/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconv_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:04:31 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

// putnbr long long n, no validity check
void	ft_print_in_base(long long n, char *base, int base_size)
{
	if (n >= base_size)
	{
		ft_print_in_base(n / base_size, base, base_size);
	}
	write(1, &base[n % base_size], 1);
	return ;
}

// int n convert to string in base
void	ft_convert_to_base(int n, char *base, int base_size,
		char *base_nbr_string)
{
	int		i;
	char	reverse_base_string[32 * 6];
	int		negative;

	negative = 1;
	if (n < 0)
		negative = -1;
	i = 0;
	while ((n <= -base_size) || (base_size <= n))
	{
		reverse_base_string[i] = base[negative * (n % base_size)];
		n = n / base_size;
		i++;
	}
	reverse_base_string[i++] = base[negative * (n % base_size)];
	if (negative == -1)
		reverse_base_string[i++] = '-';
	reverse_base_string[i] = '\0';
	ft_reverse_string(reverse_base_string, base_nbr_string, i);
}

// checks base for validity and prints base
void	ft_putnbr_base(int nbr, char *base)
{
	char			base_nbr_string[32 * 6];
	int				base_size;
	unsigned char	mask[32];
	int				c;

	ft_memset(mask, 0, 32);
	base_size = ft_strlen(base);
	if (base_size <= 1)
		return ;
	if (ft_btmsk_ckrep_str(base, mask))
		return ;
	c = 0;
	while (base[c])
	{
		if (base[c] == '+' || base[c] == '-')
			return ;
		c++;
	}
	ft_convert_to_base(nbr, base, base_size, base_nbr_string);
	c = 0;
	while (base_nbr_string[c])
		write(1, &base_nbr_string[c++], 1);
}

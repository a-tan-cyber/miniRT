/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numconv_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:02:20 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	ft_atoi(char *str)
{
	int	result;
	int	sign;
	int	digit;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
	{
		str++;
	}
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		digit = *str - '0';
		result = result * 10 + digit;
		str++;
	}
	return (sign * result);
}

char	*ft_itoa(int n)
{
	int			i;
	long long	num;
	char		string[12];
	int			negative;

	negative = (n < 0);
	i = 0;
	num = (long long)n;
	if (num < 0)
		num = -num;
	else if (num == 0)
		string[i++] = '0';
	while (num > 0)
	{
		string[i++] = '0' + (num % 10);
		num = num / 10;
	}
	if (negative)
		string[i++] = '-';
	string[i] = '\0';
	return (ft_reverse_string_malloc(string));
}

char	*ft_itoa_fast(int n, char *dest)
{
	int			i;
	long long	num;
	char		string[12];
	int			negative;

	negative = (n < 0);
	i = 0;
	num = (long long)n;
	if (num < 0)
		num = -num;
	else if (num == 0)
		string[i++] = '0';
	while (num > 0)
	{
		string[i++] = '0' + (num % 10);
		num = num / 10;
	}
	if (negative)
		string[i++] = '-';
	string[i] = '\0';
	ft_reverse_string(string, dest, i);
	return (dest);
}

char	*ft_ldtoa(long long n)
{
	int		i;
	char	string[21];
	int		negative;

	negative = 1;
	i = 0;
	if (n < 0)
		negative = -1;
	while (n <= -10 || 10 <= n)
	{
		string[i++] = '0' + (negative * (n % 10));
		n = n / 10;
	}
	string[i++] = '0' + (negative * (n % 10));
	if (negative == -1)
		string[i++] = '-';
	string[i] = '\0';
	return (ft_reverse_string_malloc(string));
}

// int	base_to_int(char *str, char *base)
// {
// 	int	i;
// 	int	res;
// 	int	base_len;

// 	base_len = ft_strlen(base);
// 	res = 0;
// 	while (*str)
// 	{
// 		i = 0;
// 		while (i < base_len && base[i] != *str)
// 			i++;
// 		if (i == base_len)
// 			break ;
// 		res = res * base_len + i;
// 		str++;
// 	}
// 	return (res);
// }

// int	ft_btoi(char *str, char *base)
// {
// 	unsigned char	mask[32] = {0};
// 	int				i;
// 	int				negative;

// 	if (ft_strlen(base) <= 1 || ft_btmsk_ckrep_str(base, mask))
// 		return (0);
// 	i = 0;
// 	while (i < (int)ft_strlen(base))
// 	{
// 		if (ft_is_white_space(base[i]) || base[i] == '-' || base[i] == '+')
// 			return (0);
// 		i++;
// 	}
// 	while (ft_is_white_space(*str))
// 		str++;
// 	negative = 1;
// 	while (*str == '-' || *str == '+')
// 	{
// 		if (*str++ == '-')
// 			negative = -negative;
// 	}
// 	return (negative * base_to_int(str, base));
// }

// char    *ft_itob(int n, char *base)
// {
// 	int     i;
// 	char    reverse_base_string[33 + 1];
// 	int     negative;
//     int     base_size;
//     char    *base_nbr_string;

//     base_size = ft_strlen(base);
// 	negative = 1;
// 	if (n < 0)
// 		negative = -1;
// 	i = 0;
// 	while ((n <= -base_size) || (base_size <= n))
// 	{
// 		reverse_base_string[i++] = base[negative * (n % base_size)];
// 		n = n / base_size;
// 	}
// 	reverse_base_string[i++] = base[negative * (n % base_size)];
// 	if (negative == -1)
// 		reverse_base_string[i++] = '-';
//     base_nbr_string = malloc((i + 1) * sizeof(char));
//     ft_reverse_string(reverse_base_string, base_nbr_string, i);
// 	return (base_nbr_string);
// }

// int ft_check_base_valid(char *base)
// {
//     int base_len;
//     int i;
// 	unsigned char	mask[32] = {0};

//     base_len = ft_strlen(base);
//     if (base_len <= 1 || ft_btmsk_ckrep_str(base, mask)) return (0);
// 	i = 0;
// 	while (i < base_len)
// 	{
// 		if (ft_is_white_space(base[i]) || base[i] == '-' || base[i] == '+')
// 			return (0);
// 		i++;
// 	}
//     return (1);
// }

// char *ft_btob(char *nbr, char *base_from, char *base_to)
// {
//     int     dec;
//     char    *res;

//     if (!ft_check_base_valid(base_from) || !ft_check_base_valid(base_to))
//         return (NULL);
//     dec = ft_btoi(nbr, base_from);
//     res = ft_itob(dec, base_to);
//     return (res);
// }
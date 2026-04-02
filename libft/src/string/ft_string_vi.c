/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_vi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 17:38:15 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/14 17:38:15 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
/* 
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
} \(2,147,483,647\) 
 */
static char	*skip_zeroes(char *str)
{
	while (*str == '0')
		str++;
	return (str);
}

int	ft_str_is_int(char *str)
{
	size_t	len;
	int		neg;

	neg = 1;
	if (str[0] == '-' || str[0] == '+')
	{
		if (*str == '-')
			neg = -1;
		str++;
	}
	if (ft_str_is_num(str) == 0)
		return (0);
	if (*str == '0')
	{
		str = skip_zeroes(str);
		if (*str == '\0')
			str--;
	}
	len = ft_strlen(str);
	if (len < 10)
		return (1);
	if (len > 10 || (neg == -1 && ft_strcmp(str, "2147483648") > 0)
		|| len == 0 || (neg == 1 && ft_strcmp(str, "2147483647") > 0))
		return (0);
	return (1);
}

int	ft_str_is_num(char *str)
{
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if ((*str < '0') || ('9' < *str))
			return (0);
		str++;
	}
	return (1);
}

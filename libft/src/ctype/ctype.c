/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctype.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:05:42 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z'))
	{
		return (0);
	}
	return (1);
}

int	ft_isdigit(int c)
{
	if ((c < '0') || ('9' < c))
		return (0);
	return (1);
}

int	ft_isalnum(int c)
{
	if (!('a' <= c && c <= 'z') && !('A' <= c && c <= 'Z') && !('0' <= c
			&& c <= '9'))
	{
		return (0);
	}
	return (1);
}

int	ft_isascii(int c)
{
	if (0 <= c && c <= 255)
	{
		return (1);
	}
	return (0);
}

// int	ft_isprint(int c)
// {
// 	if (c < 32 || 126 < c)
// 		return (0);
// 	return (1);
// }

int	ft_is_white_space(char base)
{
	if (base == ' ' || base == '\f' || base == '\n' || base == '\r'
		|| base == '\t' || base == '\v')
		return (1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_v.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:01:33 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_str_is_alpha(char *str)
{
	while (*str)
	{
		if (!('a' <= *str && *str <= 'z') && !('A' <= *str && *str <= 'Z'))
		{
			return (0);
		}
		str++;
	}
	return (1);
}

int	ft_str_is_lower(char *str)
{
	while (*str)
	{
		if (*str < 'a' || 'z' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_upper(char *str)
{
	while (*str)
	{
		if (*str < 'A' || 'Z' < *str)
			return (0);
		str++;
	}
	return (1);
}

int	ft_str_is_printable(char *str)
{
	while (*str)
	{
		if (*str < 32 || 126 < *str)
			return (0);
		str++;
	}
	return (1);
}

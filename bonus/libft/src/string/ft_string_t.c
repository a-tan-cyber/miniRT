/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:14 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_str_toupper(char *str)
{
	char	*str_start;

	str_start = str;
	while (*str)
	{
		if ('a' <= *str && *str <= 'z')
			*str = *str - 32;
		str++;
	}
	return (str_start);
}

char	*ft_str_tolower(char *str)
{
	int	count;

	count = 0;
	while (str[count])
	{
		if ('A' <= str[count] && str[count] <= 'Z')
		{
			str[count] = str[count] + 32;
		}
		count++;
	}
	return (str);
}

char	*ft_str_titlecase(char *str)
{
	int		new_word;
	char	*ptr;

	ptr = str;
	new_word = 1;
	while (*str)
	{
		if (new_word == 1 && ('a' <= *str && *str <= 'z'))
			*str = *str - 32;
		else if (new_word == 0 && ('A' <= *str && *str <= 'Z'))
			*str = *str + 32;
		if (('0' <= *str && *str <= '9') || ('a' <= *str && *str <= 'z')
			|| ('A' <= *str && *str <= 'Z'))
			new_word = 0;
		else
			new_word = 1;
		str++;
	}
	return (ptr);
}

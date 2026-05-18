/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_con.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:02:50 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// get start of string append to the end return start of str
char	*concat_char(char *string, char c)
{
	char	*string_start;

	string_start = string;
	while (*string)
	{
		string++;
	}
	*string = c;
	string++;
	*string = '\0';
	return (string_start);
}

// get current pos of location needed to be appended return new end
char	*concat_char_insitu(char *string, char c)
{
	*string = c;
	string++;
	*string = '\0';
	return (string);
}

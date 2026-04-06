/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_cmp2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 07:19:15 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/06 07:19:15 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_bool	check_str_end(const char *s1, const char *end)
{
	int	s1_len;
	int	end_len;
	int	end_loc;

	if (!s1 || !end)
		return (FALSE);
	s1_len = (int)ft_strlen(s1);
	end_len = (int)ft_strlen(end);
	end_loc = s1_len - end_len;
	if (end_loc < 0)
		return (FALSE);
	if (ft_strcmp(s1 + end_loc, end) == 0)
		return (TRUE);
	return (FALSE);
}

// return -1 if s1 is smaller than s2, 0 if same, 1 if s1 is bigger than s2
// return -2 if NULL
int	ft_str_numcmp(const char *s1, const char *s2)
{
	int	len;

	if (!s1 || !s2)
		return (-2);
	if (s1[0] == '-')
	{
		if (s2[0] == '-')
			return (ft_str_numcmp(s2 + 1, s1 + 1));
		return (-1);
	}
	else if (s2[0] == '-')
		return (1);
	if (ft_strlen(skip_zeroes(s1)) == ft_strlen(skip_zeroes(s2)))
	{
		len = ft_strcmp(skip_zeroes(s1), skip_zeroes(s2));
		if (len == 0)
			return (0);
		else if (len < 0)
			return (-1);
		return (1);
	}
	else if (ft_strlen(skip_zeroes(s1)) < ft_strlen(skip_zeroes(s2)))
		return (-1);
	return (1);
}

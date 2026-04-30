/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:02:19 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t			l;
	size_t			r;
	unsigned char	mask[32];

	if (!s1 || !set)
		return (NULL);
	ft_memset(mask, 0, 32);
	ft_btmsk_cins_cm(set, mask);
	l = 0;
	while (s1[l] && ft_btmsk_cins_mm(s1[l], mask) > 0)
		l++;
	r = ft_strlen(s1);
	if (r > 0)
		r--;
	while ((r > 0) && (ft_btmsk_cins_mm(s1[r], mask) > 0))
		r--;
	if (l > r)
		return (ft_strndup(s1 + l, 0));
	else
		return (ft_strndup(s1 + l, (r - l + 1)));
}

char	*ft_strtrim_ws(char const *s1)
{
	return (ft_strtrim(s1, " \t\n\r\v\f"));
}

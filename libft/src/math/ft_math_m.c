/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_m.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:47 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_max(int n1, int n2)
{
	if (n1 < n2)
		return (n2);
	return (n1);
}

int	ft_min(int n1, int n2)
{
	if (n1 > n2)
		return (n2);
	return (n1);
}

int	list_max(int *nums, int numscount)
{
	int	max;
	int	i;

	max = INT_MIN;
	i = 0;
	while (i < numscount)
	{
		if (nums[i] > max)
			max = nums[i];
		i++;
	}
	return (max);
}

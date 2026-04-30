/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 08:54:44 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:14:04 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_str(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_list_data(t_list **a, t_list **b)
{
	void	*temp;

	temp = (*a)->data;
	(*a)->data = (*b)->data;
	(*b)->data = temp;
}

void	ft_swap_list_adr(t_list **a, t_list **b)
{
	t_list	*temp1;
	t_list	*temp2;

	temp1 = *a;
	temp2 = (*b)->next;
	*a = *b;
	(*a)->next = temp1;
	((*a)->next)->next = temp2;
}

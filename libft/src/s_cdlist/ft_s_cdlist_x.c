/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_cdlist_x.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 22:37:59 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:23:19 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_cdlist	*ft_cdlist_swap_pos(t_cdlist *a, t_cdlist *b)
{
	if (!a || !b)
		return (NULL);
	a->next = b->next;
	b->next->prev = a;
	b->next = a;
	b->prev = a->prev;
	a->prev->next = b;
	a->prev = b;
	return (b);
}

void	ft_cdlist_insf(t_cdlist **head, t_cdlist *node)
{
	t_cdlist	*top;

	if (!head || !*head)
	{
		*head = node;
		return ;
	}
	if (!node)
		return ;
	top = *head;
	top->prev->next = node;
	node->next = top;
	node->prev = top->prev;
	top->prev = node;
	*head = node;
}

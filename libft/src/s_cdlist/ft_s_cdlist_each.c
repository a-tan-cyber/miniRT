/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_dlist_each.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 23:40:29 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/13 23:40:29 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_cdlist_each(t_cdlist **head, void (*f)(void *))
{
	t_cdlist	*top;
	t_cdlist	*temp;

	if (!head || !*head)
		return ;
	top = *head;
	temp = *head;
	f(temp->data);
	temp = temp->next;
	while (temp != top)
	{
		f(temp->data);
		temp = temp->next;
	}
}

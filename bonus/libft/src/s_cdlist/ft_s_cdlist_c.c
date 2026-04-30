/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_dlist_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 20:37:32 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/12 20:37:32 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_cdlist	*ft_cdlist_new(void *data)
{
	t_cdlist	*new;

	new = malloc(sizeof(t_cdlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = new;
	new->prev = new;
	return (new);
}

t_cdlist	*ft_cdlist_pushnext(t_cdlist **head, void *data)
{
	t_cdlist	*new;
	t_cdlist	*temp;

	new = ft_cdlist_new(data);
	if (!new)
		return (NULL);
	if (*head == NULL)
	{
		*head = new;
	}
	else
	{
		temp = (*head)->next;
		(*head)->next = new;
		new->next = temp;
		temp->prev = new;
		new->prev = *head;
	}
	return (*head);
}

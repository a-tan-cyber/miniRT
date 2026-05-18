/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:07:13 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_create_elem(void *data)
{
	t_list	*first;

	first = malloc(sizeof(t_list));
	if (!first)
		return (NULL);
	first->data = data;
	first->next = NULL;
	return (first);
}

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*first;

	first = ft_create_elem(data);
	first->next = *begin_list;
	*begin_list = first;
}

t_list	*ft_list_last(t_list *begin_list)
{
	t_list	*res;

	res = begin_list;
	while (begin_list)
	{
		res = begin_list;
		begin_list = begin_list->next;
	}
	return (res);
}

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*last;
	t_list	*temp;

	if (*begin_list == NULL)
	{
		ft_list_push_front(begin_list, data);
		return ;
	}
	else
	{
		temp = ft_list_last(*begin_list);
		last = ft_create_elem(data);
		(temp)->next = last;
	}
}

int	ft_list_size(t_list *begin_list)
{
	int	c;

	c = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		c++;
	}
	return (c);
}

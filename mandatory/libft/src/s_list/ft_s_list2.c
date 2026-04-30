/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_list2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:42:32 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*res;
	int		i;

	res = NULL;
	i = 0;
	while (i < size)
	{
		ft_list_push_front(&res, strs[i]);
		i++;
	}
	return (res);
}

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*temp;

	while (begin_list)
	{
		free_fct(begin_list->data);
		temp = begin_list;
		begin_list = begin_list->next;
		free(temp);
	}
}

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (begin_list && (nbr > 0))
	{
		begin_list = begin_list->next;
		nbr--;
	}
	return (begin_list);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*temp;
	t_list	*go;

	temp = NULL;
	while (*begin_list)
	{
		go = (*begin_list)->next;
		(*begin_list)->next = temp;
		temp = *begin_list;
		*begin_list = go;
	}
	*begin_list = temp;
}

// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (!lst || !del)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }

// void	ft_lstdelone(t_gnl **head, t_gnl *cull)
// {
// 	t_gnl	**curr;

// 	if (!head || !cull)
// 		return ;
// 	curr = head;
// 	while (*curr && *curr != cull)
// 	{
// 		curr = &((*curr)->next);
// 	}
// 	if (*curr == cull)
// 	{
// 		*curr = cull->next;
// 		free(cull->s);
// 		free(cull);
// 	}
// }
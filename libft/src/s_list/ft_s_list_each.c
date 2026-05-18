/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_list_each.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:49:04 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		f(begin_list->data);
		begin_list = begin_list->next;
	}
}

// void ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
// void *data_ref, int (*cmp)())
// {
// 	while (begin_list)
// 	{
// 		if (cmp(begin_list->data, data_ref) == 0)
// 		{
// 			f(begin_list->data);
// 		}
// 		begin_list = begin_list->next;
// 	}
// }

// t_list *ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
// {
// 	while (begin_list)
// 	{
// 		if (cmp(begin_list->data, data_ref) == 0)
// 		{
// 			return (begin_list);
// 		}
// 		begin_list = begin_list->next;
// 	}
// 	return (NULL);
// }

// void ft_list_remove_if(t_list **begin_list, void *data_ref,
// int (*cmp)(char *, char *),	void (*free_fct)(void *))
// {
// 	t_list	**cpy;
// 	t_list	*del;

// 	cpy = begin_list;
// 	while (*cpy)
// 	{
// 		if (cmp((*cpy)->data, data_ref) == 0)
// 		{
// 			del = *cpy;
// 			*cpy = (*cpy)->next;
// 			free_fct(del->data);
// 			free(del);
// 		}
// 		else
// 		{
// 			cpy = &(*cpy)->next;
// 		}
// 	}
// }

// void ft_list_merge(t_list **begin_list1, t_list *begin_list2)
// {
// 	t_list **cpy;

// 	cpy = begin_list1;
// 	while (*cpy)
// 	{
// 		cpy = &(*cpy)->next;
// 	}
// 	*cpy = begin_list2;
// }

// // #define true 1
// // #define false 0

// // void    ft_swap_list_data(t_list **a, t_list **b)
// // {
// //     void	*temp;

// //     temp = (*a)->data;
// //     (*a)->data = (*b)->data;
// //     (*b)->data = temp;
// // }

// // void ft_list_sort(t_list **begin_list, int (*cmp)(char *str1, char *str2))
// void ft_list_sort(t_list **begin_list, int (*cmp)())
// {
// 	t_list	**cpy;
// 	void	*data1;
// 	void	*data2;
// 	int		swapped;

// 	if (!begin_list || !(*begin_list))
// 		return ;
// 	swapped = true;
// 	while (swapped == true)
// 	{
// 		swapped = false;
// 		cpy = begin_list;
// 		while ((*cpy)->next)
// 		{
// 			data1 = (*cpy)->data;
// 			data2 = ((*cpy)->next)->data;
// 			if (cmp(data1, data2) > 0)
// 			{
// 				ft_swap_list_data(cpy, &((*cpy)->next));
// 				swapped = true;
// 			}
// 			cpy = &(*cpy)->next;
// 		}
// 	}
// }

// void    ft_swap_list_data(t_list **a, t_list **b)
// {
//     void	*temp;

//     temp = (*a)->data;
//     (*a)->data = (*b)->data;
//     (*b)->data = temp;
// }

// void ft_list_reverse_fun(t_list *begin_list)
// {
// 	t_list	*nlist[1024];
// 	int		l;
// 	int		r;

// 	r = 0;
// 	while (begin_list)
// 	{
// 		nlist[r] = begin_list;
// 		begin_list = begin_list->next;
// 		r++;
// 	}
// 	l = 0;
// 	r = r - 1;
// 	while (l < r)
// 	{
// 		ft_swap_list_data(&(nlist[l]), &(nlist[r]));
// 		l++;
// 		r--;
// 	}
// }

// //insert behind the current list item
// void	ft_list_push_insitu(t_list **begin_list, void *data)
// {
// 	t_list	*elem;

// 	elem = ft_create_elem(data);
// 	elem->next = (*begin_list)->next;
// 	(*begin_list)->next = elem;
// }

// void ft_sorted_list_insert(t_list **begin_list, void *data,
// int (*cmp)(char *, char *))
// // void ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
// {
// 	t_list	**curr;

// 	if (!begin_list)
// 		return ;
// 	curr = begin_list;
// 	while (*curr)
// 	{
// 		if (cmp(((*curr)->data), data) >= 0)
// 		{
// 			break ;
// 		}
// 		curr = &(*curr)->next;
// 	}
// 	ft_list_push_front(curr, data);
// }

// void ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
// int (*cmp)())
// {
// 	t_list	**curr;
// 	t_list	*temp2;

// 	if (!begin_list1)
// 		return ;
// 	curr = begin_list1;
// 	while (*curr && begin_list2)
// 	{
// 		if (cmp((*curr)->data, begin_list2->data) > 0)
// 		{
// 			temp2 = begin_list2;
// 			begin_list2 = begin_list2->next;
// 			temp2->next = *curr;
// 			*curr = temp2;
// 		}
// 		else
// 			curr = &(*curr)->next;
// 	}
// 	if (begin_list2)
// 	{
// 		*curr = begin_list2;
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_list.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:55:53 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_S_LIST_H
# define FT_S_LIST_H

typedef struct s_list
{
	void			*data;
	struct s_list	*next;
}					t_list;

// ft_s_list.c
t_list				*ft_create_elem(void *data);
// adds a new element of type t_list to the beginning of the list.
void				ft_list_push_front(t_list **begin_list, void *data);
// adds a new element of t_list type at the end of the list.
void				ft_list_push_back(t_list **begin_list, void *data);
// returns the last element of the list
t_list				*ft_list_last(t_list *begin_list);
// returns the number of elements in the list.
int					ft_list_size(t_list *begin_list);

// creates a new list that includes all the strings pointed to
// by the elements in strs
t_list				*ft_list_push_strs(int size, char **strs);
// removes and frees all links from the list
void				ft_list_clear(t_list *begin_list, void (*free_fct)(void *));
// returns the Nth element of the list,
// knowing that the first element of the list is when nbr equals 0.
t_list				*ft_list_at(t_list *begin_list, unsigned int nbr);
// reverses the order of a list’s elements.
void				ft_list_reverse(t_list **begin_list);
// void	ft_lstdelone(t_gnl **head, t_gnl *cull);

// applies the function given as an argument to each of the list’s elements
void				ft_list_foreach(t_list *begin_list, void (*f)(void *));
/*
// //applies the function given as an argument to some of the list’s elements
// void	ft_list_foreach_if(t_list *begin_list, void (*f)(void *),
		void *data_ref, int (*cmp)());
//
//returns the address of the first element’s data where comparing it to
//data_ref with cmp causes cmp to return 0
// t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
// // removes from the list all elements whose data,
	when compared to data_ref using cmp, causes cmp to return 0
// void	ft_list_remove_if(t_list **begin_list, void *data_ref,
			int (*cmp)(char *, char *),	void (*free_fct)(void *));
// //places elements of a list begin2 at the end of another list begin1
// void	ft_list_merge(t_list **begin_list1, t_list *begin_list2);
//
	// sorts the list’s elements in ascending order by comparing two
	//elements and their data using a comparison function
// void	ft_list_sort(t_list **begin_list, int (*cmp)());
// //swaps list data
// void	ft_swap_list_data(t_list **a, t_list **b);
// //reverses the order of the elements in the list
// void	ft_list_reverse_fun(t_list *begin_list);
// //insert behind the current list item
// void	ft_list_push_insitu(t_list **begin_list, void *data);
//
	// creates a new element and inserts it into a list sorted so that
	//it remains sorted in ascending order
// void	ft_sorted_list_insert(t_list **begin_list, void *data,
		int (*cmp)(char *, char *));
//
	// integrates the elements of a sorted list begin2 i
	//n another sorted list begin1,
	so that begin1 remains sorted by ascending order
// void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
		int (*cmp)());
*/
#endif
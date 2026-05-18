/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:00:20 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 11:47:51 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// size_t	ft_strlen(char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 		i++;
// 	return (i);
// }

// void	*ft_memjoin2(void const *s1, size_t len1, void const *s2, size_t len2)
// {
// 	unsigned char	*res;
// 	unsigned char	*res_start;
// 	unsigned char	*src1;
// 	unsigned char	*src2;

// 	src1 = (unsigned char *)s1;
// 	src2 = (unsigned char *)s2;
// 	res = malloc(len1 + len2 + 1);
// 	if (!res)
// 		return (NULL);
// 	res_start = res;
// 	while (len1 > 0)
// 	{
// 		*res++ = *src1++;
// 		len1--;
// 	}
// 	while (len2 > 0)
// 	{
// 		*res++ = *src2++;
// 		len2--;
// 	}
// 	*res = '\0';
// 	return ((void *)res_start);
// }

void	free_t_gnl(t_gnl **head)
{
	t_gnl	*cull;

	if (!head)
		return ;
	cull = *head;
	while (cull != NULL)
	{
		*head = (*head)->next;
		free((cull)->s);
		free(cull);
		cull = *head;
	}
	*head = NULL;
}

static t_gnl	*ft_create_elem_fd(char *data, int fd)
{
	t_gnl	*first;

	first = malloc(sizeof(t_gnl));
	if (!first)
		return (NULL);
	first->fd = fd;
	first->s = data;
	first->next = NULL;
	return (first);
}

static void	ft_list_push_front_fd(t_gnl **begin_list, char *data, int fd)
{
	t_gnl	*first;

	first = ft_create_elem_fd(data, fd);
	if (!first)
		return ;
	first->next = *begin_list;
	*begin_list = first;
}

t_gnl	*get_stored(t_gnl **head, int fd)
{
	t_gnl	*curr;
	char	*data;

	curr = *head;
	while (curr && curr->fd != fd)
	{
		curr = curr->next;
	}
	if (curr && curr->fd == fd)
		return (curr);
	data = malloc(1);
	if (!data)
		return (NULL);
	data[0] = '\0';
	ft_list_push_front_fd(head, data, fd);
	if (!*head || (*head)->fd != fd)
		return (free(data), NULL);
	if (*head && (*head)->fd == fd)
		return (*head);
	free(data);
	return (NULL);
}

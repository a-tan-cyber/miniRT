/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 10:00:33 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/08 11:06:01 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "../../include/string/ft_string.h"

int	check_newline(t_gnl *curr)
{
	int	i;

	if (!(curr->s))
		return (-1);
	i = 0;
	while ((curr->s)[i])
	{
		if ((curr->s)[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	ft_lstdelone(t_gnl **head, t_gnl **cull)
{
	t_gnl	**curr;

	if (!head || !cull || !*cull)
		return ;
	curr = head;
	while (*curr && *curr != *cull)
	{
		curr = &((*curr)->next);
	}
	if (*cull && *curr == *cull)
	{
		*curr = (*cull)->next;
		free((*cull)->s);
		free(*cull);
		*cull = NULL;
	}
}

char	*extract_line(t_gnl **head, t_gnl **curr)
{
	char	*res;
	int		i;
	int		r;

	if (!curr)
		return (NULL);
	r = check_newline(*curr);
	if (r == 0)
		while (((*curr)->s)[r])
			r++;
	res = malloc(sizeof(char) * (r + 1));
	if (!res)
	{
		ft_lstdelone(head, curr);
		return (res);
	}
	i = -1;
	while (++i < r)
		res[i] = ((*curr)->s)[i];
	res[i] = '\0';
	i = 0;
	while (((*curr)->s)[r])
		((*curr)->s)[i++] = ((*curr)->s)[r++];
	((*curr)->s)[i] = '\0';
	return (res);
}

int	get_newlinechar(t_gnl *curr, char *buf)
{
	int		gt;
	int		rd_size;
	char	*tmp;

	if (!curr)
		return (-1);
	rd_size = LIBFT_GNL_BUFFER_SIZE;
	if (curr->fd == STDIN_FILENO)
		rd_size = 1;
	gt = read(curr->fd, buf, rd_size);
	while (gt > 0)
	{
		tmp = curr->s;
		curr->s = ft_memjoin2(tmp, ft_strlen(tmp), buf, gt);
		free(tmp);
		if (!curr->s)
			return (-1);
		if (check_newline(curr) > 0)
			return (gt);
		gt = read(curr->fd, buf, rd_size);
	}
	return (gt);
}

char	*get_next_line(int fd)
{
	static t_gnl	*head;
	t_gnl			*curr;
	char			*buf;
	int				gt;

	if (fd == -69)
		return (free_t_gnl(&head), NULL);
	if (fd < 0 || LIBFT_GNL_BUFFER_SIZE <= 0)
		return (NULL);
	curr = get_stored(&head, fd);
	if (!curr)
		return (NULL);
	if (check_newline(curr) > 0)
		return (extract_line(&head, &curr));
	buf = malloc(sizeof(char) * LIBFT_GNL_BUFFER_SIZE);
	if (!buf)
		return (ft_lstdelone(&head, &curr), NULL);
	gt = get_newlinechar(curr, buf);
	free(buf);
	if (gt < 0 || (gt == 0 && (curr->s)[0] == '\0'))
	{
		ft_lstdelone(&head, &curr);
		return (NULL);
	}
	return (extract_line(&head, &curr));
}

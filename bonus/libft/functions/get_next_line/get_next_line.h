/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 23:00:03 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:14:24 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef LIBFT_GNL_BUFFER_SIZE
#  define LIBFT_GNL_BUFFER_SIZE 420
# endif

struct					s_gnl
{
	int					fd;
	char				*s;
	struct s_gnl		*next;
};

typedef struct s_gnl	t_gnl;

// get_next_line_utils.c
// size_t	ft_strlen(char *str);
// void	*ft_memjoin2(void const *s1, size_t len1, void const *s2, size_t len2);
// t_gnl	*ft_create_elem(char *data, int fd);
// void	ft_list_push_front(t_gnl **begin_list, char *data, int fd);
void	free_t_gnl(t_gnl **head);
t_gnl	*get_stored(t_gnl **head, int fd);

// get_next_line.c
int		check_newline(t_gnl *curr);
void	ft_lstdelone(t_gnl **head, t_gnl **cull);
char	*extract_line(t_gnl **head, t_gnl **curr);
int		get_newlinechar(t_gnl *curr, char *buf);
char	*get_next_line(int fd);

#endif
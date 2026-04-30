/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:18:13 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_QUEUE_H
# define FT_QUEUE_H

# define QUEUESIZE 1024
# define FTQ_EFULL 999
# define FTQ_EEMPTY -1

typedef struct s_cir_buf_1
{
	void	*buf[QUEUESIZE];
	int		size;
	int		front;
	int		back;
}			t_cir_buf_1;

typedef struct s_cir_buf_n
{
	void	*buf[QUEUESIZE];
	void	*buf2[QUEUESIZE];
	int		size;
	int		front;
	int		back;
}			t_cir_buf_n;

// ft_queue_1_base.c
int			initialise_queue_1(t_cir_buf_1 *q);
int			enqueue_1(t_cir_buf_1 *queue, void *elem);
void		*dequeue_1(t_cir_buf_1 *queue);
void		*peek_front_1(t_cir_buf_1 *queue);
void		*peek_back_1(t_cir_buf_1 *queue);

// ft_queue_n_base.c
int			initialise_queue_n(t_cir_buf_n *q);
int			enqueue_n(t_cir_buf_n *queue, void *elem1, void *elem2);
int			dequeue_n(t_cir_buf_n *queue);
int			peek_front_n(t_cir_buf_n *queue);
int			peek_back_n(t_cir_buf_n *queue);

// ft_queue_chk.c
int			is_empty_1(t_cir_buf_1 *queue);
int			is_full_1(t_cir_buf_1 *queue);
int			is_empty_n(t_cir_buf_n *queue);
int			is_full_n(t_cir_buf_n *queue);

#endif
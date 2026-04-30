/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue_chk.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2025/12/09 12:17:40 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	is_empty_1(t_cir_buf_1 *queue)
{
	if (queue->size > 0)
	{
		return (0);
	}
	return (1);
}

int	is_full_1(t_cir_buf_1 *queue)
{
	if (queue->size == QUEUESIZE)
	{
		return (1);
	}
	return (0);
}

int	is_empty_n(t_cir_buf_n *queue)
{
	if (queue->size > 0)
	{
		return (0);
	}
	return (1);
}

int	is_full_n(t_cir_buf_n *queue)
{
	if (queue->size == QUEUESIZE)
	{
		return (1);
	}
	return (0);
}

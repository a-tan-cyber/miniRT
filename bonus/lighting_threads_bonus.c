/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_threads_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:00:20 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:00:26 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

void	free_thrd(t_thrd **top)
{
	t_thrd	*head;
	t_thrd	*cur;

	head = *top;
	while (head)
	{
		cur = head;
		head = head->next;
		ft_sfree((void **)&cur);
	}
	*top = NULL;
}

t_thrd	*cre_t_thrd_new(int id, long nprocs, t_data *data)
{
	t_thrd	*new;
	int		total_len;
	int		thrd_len;

	new = malloc(sizeof(t_thrd));
	if (!new)
		return (NULL);
	new->created = FALSE;
	new->data = data;
	total_len = HEIGHT * WIDTH;
	thrd_len = total_len / nprocs;
	new->id = id;
	new->next = NULL;
	new->obj = data->obj_head;
	new->starty = id * thrd_len / WIDTH;
	if (id == nprocs - 1)
		new->endy = HEIGHT;
	else
		new->endy = (id * thrd_len + thrd_len) / WIDTH;
	return (new);
}

t_thrd	*cre_t_thrd_next(t_thrd *thrd, int id, long nprocs, t_data *data)
{
	t_thrd	*new;

	new = cre_t_thrd_new(id, nprocs, data);
	if (!new)
		return (NULL);
	if (!thrd)
		return (new);
	thrd->next = new;
	return (new);
}

t_thrd	*cre_thrddata(t_data *data)
{
	long	nprocs;
	long	i;
	t_thrd	*head;
	t_thrd	*curr;

	nprocs = sysconf(_SC_NPROCESSORS_CONF);
	if (nprocs < 1)
		return (ft_puterr("sysconf processor number < 1"), NULL);
	i = 0;
	head = cre_t_thrd_new(i, nprocs, data);
	if (!head)
		return (NULL);
	curr = head;
	i++;
	while (i < nprocs)
	{
		curr = cre_t_thrd_next(curr, i, nprocs, data);
		if (!curr)
			return (ft_puterr("cre_t_thrddata error"), free_thrd(&head), NULL);
		i++;
	}
	return (head);
}

void	calc_pixel_thrd_join(t_thrd *head)
{
	t_thrd	*thrd;

	thrd = head;
	while (thrd)
	{
		if (thrd->created == FALSE)
			break ;
		pthread_join(thrd->thrd, NULL);
		thrd = thrd->next;
	}
}

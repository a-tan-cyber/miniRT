/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_list_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:22:30 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:00:49 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_obj	*go_t_obj_last(t_obj *obj)
{
	t_obj	*cur;

	cur = obj;
	while (obj)
	{
		cur = obj;
		obj = obj->next;
	}
	return (cur);
}

t_obj	*cre_t_obj_new(void)
{
	t_obj	*new;

	new = malloc(sizeof(t_obj));
	if (!new)
		return (NULL);
	initialise_t_obj(&new);
	return (new);
}

t_obj	*cre_t_obj_next(t_obj *obj)
{
	t_obj	*new;

	new = cre_t_obj_new();
	if (!new)
		return (NULL);
	if (!obj)
		return (new);
	obj->next = new;
	return (new);
}

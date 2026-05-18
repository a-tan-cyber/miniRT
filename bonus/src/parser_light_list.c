/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_light_list.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 22:50:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 22:50:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialise_t_ligt(t_ligt *ligt)
{
	initialise_t_cord(&ligt->cord);
	ligt->bright = -1;
	initialise_t_rgb(&ligt->rgb);
	ligt->next = NULL;
}

t_ligt	*go_t_ligt_last(t_ligt *ligt)
{
	t_ligt	*cur;

	cur = ligt;
	while (ligt)
	{
		cur = ligt;
		ligt = ligt->next;
	}
	return (cur);
}

t_ligt	*cre_t_ligt_new(void)
{
	t_ligt	*new;

	new = malloc(sizeof(t_ligt));
	if (!new)
		return (NULL);
	initialise_t_ligt(new);
	return (new);
}

t_ligt	*cre_t_ligt_last(t_ligt *ligt)
{
	t_ligt	*new;

	if (ligt == NULL)
		return (cre_t_ligt_new());
	ligt = go_t_ligt_last(ligt);
	new = cre_t_ligt_new();
	if (!new)
		return (NULL);
	ligt->next = new;
	return (new);
}

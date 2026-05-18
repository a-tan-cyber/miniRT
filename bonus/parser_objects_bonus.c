/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_objects_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 01:01:42 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:01:46 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	val_ins_rgb(const char *string, t_obj *new)
{
	return (obj_parse_rgb(new, string, "val_ins_rgb: error"));
}

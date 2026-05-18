/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_main_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:15:05 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 01:01:10 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

int	add_rt_data_s(const char **split_arr, t_obj **obj, t_data **data)
{
	int		err;
	t_obj	*new;

	new = cre_t_obj_next(go_t_obj_last(*obj));
	if (!new)
		return (ft_puterr("add_rt_data_s: failed to create new"), -1);
	if (!*obj)
	{
		*obj = new;
		(*data)->obj_head = new;
	}
	err = 0;
	if (ft_strcmp(split_arr[0], "sp") == 0)
		err = add_rt_data_s_sp(split_arr, new);
	else if (ft_strcmp(split_arr[0], "pl") == 0)
		err = add_rt_data_s_pl(split_arr, new);
	else if (ft_strcmp(split_arr[0], "cy") == 0)
		err = add_rt_data_s_cy(split_arr, new);
	else if (ft_strcmp(split_arr[0], "el") == 0)
		err = add_rt_data_s_el(split_arr, new);
	else
		return (ft_puterr("invalid shape identifier"),
			ft_sfree((void **)&new), -11);
	return (err);
}

int	add_rt_data(const char *trimmed, t_obj **obj, t_data **data)
{
	char	**split_arr;
	char	*curr;

	split_arr = ft_split(trimmed, " \t\n");
	if (!split_arr || !split_arr[0])
		return (free_arr(split_arr), -1);
	curr = split_arr[0];
	if (!ft_strcmp(curr, "A") || !ft_strcmp(curr, "C") || !ft_strcmp(curr, "L"))
	{
		if (add_rt_data_d((const char **)split_arr, data) != 0)
			return (free_arr(split_arr), 1);
	}
	else if (!ft_strcmp(curr, "sp") || !ft_strcmp(curr, "pl")
		|| !ft_strcmp(curr, "cy") || !ft_strcmp(curr, "el"))
	{
		if (add_rt_data_s((const char **)split_arr, obj, data) != 0)
			return (free_arr(split_arr), 2);
	}
	else
		return (ft_puterr("invalid data identifier: "), ft_puterr(split_arr[0]),
			free_arr(split_arr), -2);
	return (free_arr(split_arr), 0);
}

int	initialise_rt(const char *str, t_obj **obj, t_data **data)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (ft_puterr("cannot open scene file"), 1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, " \r\n");
		ft_sfree((void **)&line);
		if (ft_strcmp(trimmed, "") != 0)
		{
			if (add_rt_data(trimmed, obj, data) != 0)
				return (ft_sfree((void **)&trimmed),
					close(fd), get_next_line(-69), 2);
		}
		ft_sfree((void **)&trimmed);
		line = get_next_line(fd);
	}
	close(fd);
	if (validate_required_data(*data) != 0)
		return (3);
	return (0);
}

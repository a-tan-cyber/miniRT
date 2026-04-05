/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yunguo <yunguo@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 17:17:44 by yunguo            #+#    #+#             */
/*   Updated: 2026/04/03 17:17:44 by yunguo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// if s1 is smaller than min or bigger than max, then return 0
int	validate_str_int_range(const char *s1, const char *min, const char *max)
{
	if (!ft_str_is_int(s1) || !ft_str_is_int(min) || !ft_str_is_int(max))
		return (ft_puterr("val is not an int"), 0);
	if (ft_str_numcmp(s1, min) == -1)
		return (ft_puterr("val is too small"), 0);
	if (ft_str_numcmp(s1, max) == 1)
		return (ft_puterr("val is too large"), 0);
	return (1);
}

int	add_rt_data_d_a(const char **split_arr, t_data **data)
{
	char	**arr;

	if (ft_arrlen(split_arr) != 3)
		return (-1);
	if (ft_str_is_float(split_arr[1]) == FALSE)
		return (ft_puterr("data.ambi ratio is not float"), 1);
	(*data)->ambi.ratio = ft_atof(split_arr[1]);
	if ((*data)->ambi.ratio > 1.0 || (*data)->ambi.ratio < 0.0)
		return (ft_puterr("data.ambi value is out of range"), -2);
	arr = ft_split(split_arr[2], ",");
	if (!arr)
		return (ft_puterr("malloc failed (data.ambi.rgb)"), 2);
	if (ft_arrlen(arr) != 3)
		return (ft_puterr("data.ambi wrong no. of rgb val"), free_arr(arr), 3);
	if (validate_str_int_range(arr[0], "0", "255") == FALSE)
		return (ft_puterr("data.ambi r value invalid"), free_arr(arr), 4);
	(*data)->ambi.r = ft_atoi(arr[0]);
	if (validate_str_int_range(arr[1], "0", "255") == FALSE)
		return (ft_puterr("data.ambi g value invalid"), free_arr(arr), 5);
	(*data)->ambi.g = ft_atoi(arr[1]);
	if (validate_str_int_range(arr[2], "0", "255") == FALSE)
		return (ft_puterr("data.ambi b value invalid"), free_arr(arr), 6);
	(*data)->ambi.b = ft_atoi(arr[2]);
	return (free_arr(arr), 0);
}

int	add_rt_data_d(const char **split_arr, t_data **data)
{
	char	**arr;
	t_data	*info;
	int		err;

	info = *data;
	err = 0;
	if (ft_strcmp(split_arr[0], "A") == 0)
		err = add_rt_data_d_a(split_arr, data);

	return (err);
}
// if (add_rt_data_s(split_arr, obj) != 0)

int	add_rt_data(const char *trimmed, t_obj **obj, t_data **data)
{
	char	**split_arr;
	char	*curr;

	split_arr = ft_split(trimmed, " ");
	if (!split_arr || !split_arr[0])
		return (-1);
	curr = split_arr[0];
	if (!ft_strcmp(curr, "A") || !ft_strcmp(curr, "C") || !ft_strcmp(curr, "L"))
	{
		if (add_rt_data_d(split_arr, data) != 0)
			return (free_arr(split_arr), 1);
	}
	else if (!ft_strcmp(curr, "sp") || !ft_strcmp(curr, "pl")
		|| !ft_strcmp(curr, "cy"))
	{
		if (add_rt_data_s(split_arr, obj) != 0)
			return (free_arr(split_arr), 2);
	}
	return (free_arr(split_arr), 0);
}

int	initialise_rt(const char *str, t_obj **obj, t_data **data)
{
	char	*line;
	char	*trimmed;
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd <= 0)
		return (1);
	line = get_next_line(fd);
	while (line != NULL)
	{
		trimmed = ft_strtrim(line, " \n");
		ft_sfree(&line);
		if (ft_strcmp(trimmed, "") != 0)
		{
			if (add_rt_data(trimmed, obj, data) != 0)
				return (ft_sfree(&trimmed), close(fd), get_next_line(-69), 2);
		}
		ft_sfree(&trimmed);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

	// if (initialise_minilibx(&data) != 0)
	// 	return (4);
	// if (calc_pixel(&obj, &data) != 0)
	// 	return (5);
	// if (add_event_hook(&data) != 0)
	// 	return (6);
	// if (run_window_loop(&obj, &data) != 0)
	// 	return (7);

int	main(int argc, char **argv)
{
	t_obj	*obj;
	t_data	*data;

	if (argc != 2)
		return (ft_puterr("invalid number of arg"), 1);
	if (check_str_end(argv[1], ".rt") != TRUE)
		return (ft_puterr("invalid extension"), 2);
	obj = NULL;
	data = NULL;
	if (initialise_rt(argv[1], &obj, &data) != 0)
		return (free_rt(&obj, &data), 3);
	if (initialise_minilibx(&data) != 0)
		return (free_rt(&obj, &data), 4);
	if (calc_pixel(&obj, &data) != 0)
		return (free_rt(&obj, &data), 5);
	if (add_event_hook(&data) != 0)
		return (free_rt(&obj, &data), 6);
	if (run_window_loop(&obj, &data) != 0)
		return (free_rt(&obj, &data), 7);
	return (free_rt(&obj, &data), 0);
}

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

int	initialise_rt(const char *str, t_obj **obj, t_data **data)
{
	int	fd;

	fd = open(str, O_RDONLY);
	get_next_line(fd);
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
		return (3);
	if (initialise_minilibx(&data) != 0)
		return (4);
	if (calc_pixel(&obj, &data) != 0)
		return (5);
	if (add_event_hook(&data) != 0)
		return (6);
	if (run_window_loop(&obj, &data) != 0)
		return (7);
	return (0);
}

#include "minirt.h"

t_bool	check_str_end(char *s1, char *end)
{
	int	s1_len;
	int	end_len;
	int	end_loc;

	if (!s1 || !end)
		return (FALSE);
	s1_len = (int)ft_strlen(s1);
	end_len = (int)ft_strlen(end);
	end_loc = s1_len - end_len;
	if (end_loc < 0)
		return (FALSE);
	if (ft_strcmp(s1 + end_loc, end) == 0)
		return (TRUE);
	return (FALSE);
}

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
	calc_pixel(&obj, &data);
	add_event_hook(&data);
	run_window_loop(&obj, &data);
	return (0);
}

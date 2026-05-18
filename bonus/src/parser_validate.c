/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_validate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 21:11:16 by amtan             #+#    #+#             */
/*   Updated: 2026/04/29 21:12:23 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// if s1 is smaller than min or bigger than max, then return 0
int	validate_str_int_range(const char *s1, const char *min, const char *max)
{
	if (!ft_str_is_int(s1) || !ft_str_is_int(min) || !ft_str_is_int(max))
		return (ft_puterr("val is not an int"), 0);
	if (ft_str_numcmp(min, max) == 1)
		return (ft_puterr("int min is greater than max"), 0);
	if (ft_str_numcmp(s1, min) == -1)
		return (ft_puterr("int val is too small"), 0);
	if (ft_str_numcmp(s1, max) == 1)
		return (ft_puterr("int val is too large"), 0);
	return (1);
}

int	validate_str_float_range(const char *s, float min, float max)
{
	float	target;

	if (!s)
		return (ft_puterr("missing float val"), 0);
	if (min > max)
		return (ft_puterr("float min > max"), 0);
	if (!ft_str_is_float(s))
		return (ft_puterr("val is not a float"), 0);
	target = ft_atof(s);
	if (target < min)
		return (ft_puterr("float val too small"), 0);
	if (target > max)
		return (ft_puterr("float val too large"), 0);
	return (1);
}

int	chk_normalised(t_cord ori)
{
	double	normal;

	normal = ori.x * ori.x + ori.y * ori.y + ori.z * ori.z;
	if (fabs(normal - 1.0) < EPSILON)
		return (0);
	ft_puterr("ori not normalised");
	return (1);
}

int	validate_required_data(t_data *data)
{
	if (!data)
		return (ft_puterr("missing scene data"), 1);
	if (data->ambi_loaded == FALSE)
		return (ft_puterr("missing ambient lighting"), 2);
	if (data->cam_loaded == FALSE)
		return (ft_puterr("missing camera"), 3);
	if (data->ligt == NULL)
		return (ft_puterr("missing light"), 4);
	return (0);
}

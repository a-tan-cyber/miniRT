/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_color_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:54:34 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:59:25 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_rgb	rgb_amp_cap(t_rgb rgb, double ratio)
{
	rgb.r = (double)rgb.r * ratio;
	rgb.r = ft_min(rgb.r, 255);
	rgb.r = ft_max(rgb.r, 0);
	rgb.g = (double)rgb.g * ratio;
	rgb.g = ft_min(rgb.g, 255);
	rgb.g = ft_max(rgb.g, 0);
	rgb.b = (double)rgb.b * ratio;
	rgb.b = ft_min(rgb.b, 255);
	rgb.b = ft_max(rgb.b, 0);
	return (rgb);
}

t_rgb	rgb_add(t_rgb l1, t_rgb l2)
{
	l1.r = l1.r + l2.r;
	l1.g = l1.g + l2.g;
	l1.b = l1.b + l2.b;
	return (l1);
}

t_rgb	rgb_mul(t_rgb l1, t_rgb l2, int bound)
{
	l1.r = l1.r * l2.r / bound;
	l1.g = l1.g * l2.g / bound;
	l1.b = l1.b * l2.b / bound;
	return (l1);
}

t_rgb	calc_pixel_l_diffused(t_rgb rgb, double factor, t_ligt *ligt)
{
	t_rgb	light;

	initialise_t_rgb(&light);
	light = rgb_amp_cap(ligt->rgb, ligt->bright);
	light = rgb_amp_cap(light, factor);
	light = rgb_mul(rgb, light, 255);
	return (light);
}

// endian == 0 is little, endian == 1 is big
int	conv_rgb2str(char *dest, t_rgb rgb, t_data *data)
{
	int		bpp;
	int		endian;

	bpp = data->bits_p_pixel;
	endian = data->endian;
	if (bpp == 32)
	{
		if (endian == 0)
		{
			ft_memcpy(dest, &rgb.b, 1);
			ft_memcpy(dest + 1, &rgb.g, 1);
			ft_memcpy(dest + 2, &rgb.r, 1);
		}
		else if (endian == 1)
		{
			ft_memcpy(dest, (char *)&rgb.r + sizeof(int) - 1, 1);
			ft_memcpy(dest + 1, (char *)&rgb.g + sizeof(int) - 1, 1);
			ft_memcpy(dest + 2, (char *)&rgb.b + sizeof(int) - 1, 1);
		}
	}
	else
		return (ft_puterr("conv_rgb2str err; bpp value unaccounted for"), 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_main_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 20:57:29 by amtan             #+#    #+#             */
/*   Updated: 2026/05/19 00:59:28 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt_bonus.h"

t_rgb	calc_pixel_l_each(t_rgb ambi, t_box box, t_obj *cur, t_data *data)
{
	double	factor;
	t_ligt	*cur_ligt;
	t_cord	bump_vec;

	initialise_t_cord(&bump_vec);
	cur_ligt = data->ligt;
	while (cur_ligt)
	{
		box.s2l_vec = vec3_2pvec_norm(cur_ligt->cord, box.p);
		bump_vec = calc_pixel_l_each_bump_deviation(box.p, box.sur_vec, cur);
		box.sur_vec = bump_vec;
		box.ln_dotp = vec3_dot(box.sur_vec, box.s2l_vec);
		factor = calc_pixel_l_sdwvslit(box, data->obj_head, cur_ligt);
		if (factor > 0)
		{
			ambi = rgb_add(ambi,
					calc_pixel_l_diffused(box.s, factor, cur_ligt));
			ambi = rgb_amp_cap(rgb_add(ambi,
						calc_pixel_l_specular(box, cur_ligt, data)), 1);
		}
		cur_ligt = cur_ligt->next;
	}
	return (ambi);
}

t_rgb	calc_pixel_l(t_ray *ray, t_obj *cur, t_ligt *ligt, t_data *data)
{
	t_rgb	ambi;
	t_box	box;

	initialise_t_rgb(&ambi);
	if (!ray || !cur || !ligt || !data)
		return (ambi);
	ambi = rgb_amp_cap(data->ambi.rgb, data->ambi.ratio);
	initialise_t_box(&box);
	box.p = calc_point(ray);
	if (cur->chkr == TRUE)
		box.s = calc_chkr(ray, box.p, cur);
	else
		box.s = cur->rgb;
	ambi = rgb_mul(ambi, box.s, 255);
	box.sur_vec = calc_surface_normal(box.p, cur, ray);
	ambi = calc_pixel_l_each(ambi, box, cur, data);
	return (ambi);
}

int	calc_pixel_a(int y, int x, t_rgb rgb, t_data *data)
{
	int		loc;
	int		n_bytes;

	n_bytes = data->bits_p_pixel / BITS_PER_BYTE;
	loc = y * data->size_line;
	loc = loc + (n_bytes * x);
	*(unsigned int *)(data->addr + loc) = (rgb.r << 16) | (rgb.g << 8) | rgb.b;
	return (0);
}

int	calc_pixel(t_obj **obj, t_data **data)
{
	t_thrd	*head;
	t_thrd	*thrd;

	(void) obj;
	head = cre_thrddata(*data);
	if (head == NULL)
		return (-1);
	thrd = head;
	while (thrd)
	{
		if (pthread_create(&thrd->thrd, NULL, calc_pixel_thrd_run,
				(void *)thrd))
			return (ft_puterr("calc_pixel pthread creation failed thread "),
				ft_putnbr(thrd->id), calc_pixel_thrd_join(head),
				free_thrd(&head), 1);
		thrd->created = TRUE;
		thrd = thrd->next;
	}
	calc_pixel_thrd_join(head);
	free_thrd(&head);
	return (0);
}

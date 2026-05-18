/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lighting_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/18 23:10:00 by amtan             #+#    #+#             */
/*   Updated: 2026/05/18 23:10:00 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

#define CHKR_SCALE 0.5

t_rgb	calc_chkr(t_ray *ray, t_cord p, t_obj *cur)
{
	t_calc	calc;
	int		sum;

	initialise_t_calc(&calc);
	calc_chkr_uv(&calc, p, ray, cur);
	sum = (int)(floor(calc.u * CHKR_SCALE) + floor (calc.v * CHKR_SCALE));
	if (sum % 2 == 0)
		return (cre_t_rgb(255, 255, 255));
	else
		return (cre_t_rgb(0, 0, 0));
}

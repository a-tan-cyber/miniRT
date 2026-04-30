/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/06 13:53:21 by amtan             #+#    #+#             */
/*   Updated: 2026/04/06 15:57:23 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_float.h"

static void	test_is_float(const char *s)
{
	printf("ft_str_is_float(\"%s\") = %d\n", s, ft_str_is_float(s));
}

static void	test_atof(const char *s)
{
	printf("ft_atof(\"%s\") = %f\n", s, ft_atof(s));
}

int	main(void)
{
	test_is_float("42");
	test_is_float("3.14");
	test_is_float("-0.25");
	test_is_float("1e3");
	test_is_float("  +12.5e-2  ");
	test_is_float("abc");
	test_is_float("1e");
	test_is_float(".");
	printf("\n");
	test_atof("42");
	test_atof("3.14");
	test_atof("-0.25");
	test_atof("1e3");
	test_atof("  +12.5e-2  ");
	test_atof("abc");
	return (0);
}

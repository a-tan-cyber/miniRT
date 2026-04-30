/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:21:46 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"

int	initialise_stack(t_stack *stk)
{
	stk->i = 0;
	return (0);
}

int	push_stack(t_stack *stk, void *stuff)
{
	if (stk->i >= STACKSIZE)
	{
		return (999);
	}
	stk->stack[stk->i] = stuff;
	stk->i++;
	return (0);
}

void	*pop_stack(t_stack *stk)
{
	if (stk->i == 0)
		return (0);
	stk->i--;
	return (stk->stack[stk->i]);
}

void	*peek(t_stack *stk)
{
	if (stk->i == 0)
		return (0);
	return (stk->stack[stk->i - 1]);
}

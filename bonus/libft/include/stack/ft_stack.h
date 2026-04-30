/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amtan <amtan@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 07:32:52 by yunguo            #+#    #+#             */
/*   Updated: 2026/03/01 14:21:20 by amtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STACK_H
# define FT_STACK_H

# define STACKSIZE 1024

typedef struct s_stack
{
	void	*stack[STACKSIZE];
	int		i;
}			t_stack;

// ft_stack_base.c
int			initialise_stack(t_stack *stk);
int			push_stack(t_stack *stk, void *stuff);
void		*pop_stack(t_stack *stk);
void		*peek(t_stack *stk);

// ft_stack_chk.c
int			is_full(t_stack *stk);
int			is_empty(t_stack *stk);

#endif
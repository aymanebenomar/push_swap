/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:37:04 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/26 13:10:28 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *stack)
{
	int	pos;
	int	best;
	int	min;

	pos = 0;
	best = 0;
	min = stack->value;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			best = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (best);
}

void	sort_simple(t_ctx *context)
{
	int	size;

	size = stack_size(context->stack_a);
	while (size > 1 && !is_sorted(context->stack_a))
	{
		rotate_stack(context, min_pos(context->stack_a), size, RA);
		exec_op(context, PB);
		size--;
	}
	while (context->stack_b)
		exec_op(context, PA);
}

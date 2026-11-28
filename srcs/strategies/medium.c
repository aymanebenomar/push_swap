/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:43:51 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/24 14:31:10 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_pos(t_stack *stack_b)
{
	int	pos;
	int	best;
	int	max;

	pos = 0;
	best = 0;
	max = -1;
	while (stack_b)
	{
		if (stack_b->index > max)
		{
			max = stack_b->index;
			best = pos;
		}
		pos++;
		stack_b = stack_b->next;
	}
	return (best);
}

static void	push_chunks(t_ctx *context, int range)
{
	int	pushed;

	pushed = 0;
	while (context->stack_a)
	{
		if (context->stack_a->index <= pushed)
		{
			exec_op(context, PB);
			if (context->stack_b->next)
				exec_op(context, RB);
			pushed++;
		}
		else if (context->stack_a->index <= pushed + range)
		{
			exec_op(context, PB);
			pushed++;
		}
		else
			exec_op(context, RA);
	}
}

static void	pull_back(t_ctx *context)
{
	int	size;

	size = stack_size(context->stack_b);
	while (size > 0)
	{
		rotate_stack(context, max_pos(context->stack_b), size, RB);
		exec_op(context, PA);
		size--;
	}
}

void	sort_medium(t_ctx *context)
{
	int	range;

	range = ft_isqrt(stack_size(context->stack_a)) * 3 / 2;
	if (range < 1)
		range = 1;
	push_chunks(context, range);
	pull_back(context);
}

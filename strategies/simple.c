/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:37:45 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/23 15:54:29 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *a)
{
	int	min;
	int	best;
	int	pos;

	if (!a)
		return (0);
	min = a->value;
	pos = 0;
	best = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			best = pos;
		}
		pos++;
		a = a->next;
	}
	return (best);
}

void	rotate_to_top(t_ctx *ctx, int pos, int size)
{
	int	i;

	if (pos <= size / 2)
	{
		i = 0;
		while (i < pos)
		{
			exec_op(ctx, RA);
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < size - pos)
		{
			exec_op(ctx, RRA);
			i++;
		}
	}
}

void	sort_simple(t_ctx *ctx)
{
	int	size;
	int	minpos;

	if (!ctx)
		return ;
	size = stack_size(ctx->a);
	while (size > 1 && !is_sorted(ctx->a))
	{
		minpos = min_pos(ctx->a);
		rotate_to_top(ctx, minpos, size);
		exec_op(ctx, PB);
		size--;
	}
	while (ctx->b)
		exec_op(ctx, PA);
}

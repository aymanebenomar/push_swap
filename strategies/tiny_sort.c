/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:40:57 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/23 17:04:47 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_ctx *ctx)
{
	int	top;
	int	middle;
	int	bottom;

	top = ctx->a->value;
	middle = ctx->a->next->value;
	bottom = ctx->a->next->next->value;
	if (top > middle && top > bottom)
		exec_op(ctx, RA);
	else if (middle > top && middle > bottom)
		exec_op(ctx, RRA);
	if (ctx->a->value > ctx->a->next->value)
		exec_op(ctx, SA);
}

void	sort_tiny(t_ctx *ctx)
{
	int	size;

	size = stack_size(ctx->a);
	if (size == 2)
	{
		if (ctx->a->value > ctx->a->next->value)
			exec_op(ctx, SA);
		return ;
	}
	while (size > 3)
	{
		rotate_to_top(ctx, min_pos(ctx->a), size);
		exec_op(ctx, PB);
		size--;
	}
	sort_three(ctx);
	while (ctx->b)
		exec_op(ctx, PA);
}

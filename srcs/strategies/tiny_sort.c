/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:44:26 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/21 18:39:33 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_ctx *context)
{
	int	x;
	int	y;
	int	z;

	x = context->stack_a->value;
	y = context->stack_a->next->value;
	z = context->stack_a->next->next->value;
	if (x > y && x > z)
		exec_op(context, RA);
	else if (y > x && y > z)
		exec_op(context, RRA);
	if (context->stack_a->value > context->stack_a->next->value)
		exec_op(context, SA);
}

void	sort_tiny(t_ctx *context)
{
	int	size;

	size = stack_size(context->stack_a);
	if (size == 2)
	{
		if (context->stack_a->value > context->stack_a->next->value)
			exec_op(context, SA);
		return ;
	}
	while (size > 3)
	{
		rotate_stack(context, min_pos(context->stack_a), size, RA);
		exec_op(context, PB);
		size--;
	}
	sort_three(context);
	while (context->stack_b)
		exec_op(context, PA);
}

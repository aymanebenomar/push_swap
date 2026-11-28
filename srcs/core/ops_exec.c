/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:32:24 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/23 20:29:42 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

const char	*op_name(t_op op)
{
	static const char	*names[] = {"sa", "sb", "ss", "pa", "pb", "ra",
		"rb", "rr", "rra", "rrb", "rrr"};

	return (names[op]);
}

void	run_op(t_ctx *context, t_op op)
{
	if (op == SA || op == SS)
		op_swap(&context->stack_a);
	if (op == SB || op == SS)
		op_swap(&context->stack_b);
	if (op == PA)
		op_push(&context->stack_b, &context->stack_a);
	if (op == PB)
		op_push(&context->stack_a, &context->stack_b);
	if (op == RA || op == RR)
		op_rotate(&context->stack_a);
	if (op == RB || op == RR)
		op_rotate(&context->stack_b);
	if (op == RRA || op == RRR)
		op_rev_rotate(&context->stack_a);
	if (op == RRB || op == RRR)
		op_rev_rotate(&context->stack_b);
}

static int	grow_ops(t_ctx *context)
{
	unsigned char	*bigger;
	int				cap;

	cap = context->ops_cap * 2;
	if (cap == 0)
		cap = 1024;
	bigger = malloc(cap);
	if (!bigger)
		return (0);
	if (context->ops)
	{
		ft_memcpy(bigger, context->ops, context->ops_len);
		free(context->ops);
	}
	context->ops = bigger;
	context->ops_cap = cap;
	return (1);
}

void	exec_op(t_ctx *context, t_op op)
{
	run_op(context, op);
	if (context->fail)
		return ;
	if (context->ops_len == context->ops_cap && !grow_ops(context))
	{
		context->fail = 1;
		return ;
	}
	context->ops[context->ops_len++] = (unsigned char)op;
}

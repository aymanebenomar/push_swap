/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:58:54 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/19 16:59:01 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	exec_op(t_ctx *ctx, t_op op)
{
	char	*names[11];

	names[SA] = "sa";
	names[SB] = "sb";
	names[SS] = "ss";
	names[PA] = "pa";
	names[PB] = "pb";
	names[RA] = "ra";
	names[RB] = "rb";
	names[RR] = "rr";
	names[RRA] = "rra";
	names[RRB] = "rrb";
	names[RRR] = "rrr";

	if (op == SA || op == SS)
		swap(&ctx->a);
	if (op == SB || op == SS)
		swap(&ctx->b);
	if (op == RA || op == RR)
		rotate(&ctx->a);
	if (op == RB || op == RR)
		rotate(&ctx->b);
	if (op == PA)
		push(&ctx->b, &ctx->a);
	if (op == PB)
		push(&ctx->a, &ctx->b);
	if (op == RRA || op == RRR)
		reverse_rotate(&ctx->a);
	if (op == RRB || op == RRR)
		reverse_rotate(&ctx->b);
	ctx->counts[op]++;
	ft_putendl_fd(names[op], 1);
}

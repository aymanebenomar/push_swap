/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:32:22 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/23 18:50:06 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	engine_run(t_ctx *context, t_flags *flag, double disorder)
{
	context->used = flag->strategy;
	if (flag->strategy == ADAPTIVE)
		context->used = pick_strategy(disorder);
	if (is_sorted(context->stack_a))
		return ;
	assign_rank(context->stack_a);
	if (flag->strategy == ADAPTIVE)
		sort_adaptive(context);
	else if (flag->strategy == SIMPLE)
		sort_simple(context);
	else if (flag->strategy == MEDIUM)
		sort_medium(context);
	else
		sort_complex(context);
}

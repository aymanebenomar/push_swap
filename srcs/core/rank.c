/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:32:27 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/18 16:05:58 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_rank(t_stack *stack)
{
	t_stack	*stack_i;
	t_stack	*stack_j;
	int		rank;

	stack_i = stack;
	while (stack_i)
	{
		rank = 0;
		stack_j = stack;
		while (stack_j)
		{
			if (stack_j->value < stack_i->value)
				rank++;
			stack_j = stack_j->next;
		}
		stack_i->index = rank;
		stack_i = stack_i->next;
	}
}

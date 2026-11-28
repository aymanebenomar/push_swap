/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/14 14:32:18 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/15 18:56:52 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *stack_a)
{
	t_stack	*stack_i;
	t_stack	*stack_j;
	long	mistakes;
	long	total;

	stack_i = stack_a;
	mistakes = 0;
	total = 0;
	while (stack_i)
	{
		stack_j = stack_i->next;
		while (stack_j)
		{
			total++;
			if (stack_i->value > stack_j->value)
				mistakes++;
			stack_j = stack_j->next;
		}
		stack_i = stack_i->next;
	}
	if (total == 0)
		return (0.0);
	return ((double)mistakes / total);
}

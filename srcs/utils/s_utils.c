/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:29:18 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/27 16:56:36 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *stack)
{
	int	n;

	n = 0;
	while (stack)
	{
		n++;
		stack = stack->next;
	}
	return (n);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	ft_isqrt(int n)
{
	int	r;

	r = 0;
	while (r + 1 <= n / (r + 1))
		r++;
	return (r);
}

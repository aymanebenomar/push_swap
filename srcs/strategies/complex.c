/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 23:17:43 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/26 13:10:42 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max_bits(int size)
{
	int	bits;

	bits = 0;
	while ((size - 1) >> bits)
		bits++;
	return (bits);
}

void	sort_complex(t_ctx *context)
{
	int	size;
	int	bit;
	int	i;

	size = stack_size(context->stack_a);
	bit = 0;
	while (bit < max_bits(size))
	{
		i = 0;
		while (i++ < size)
		{
			if ((context->stack_a->index >> bit) & 1)
				exec_op(context, RA);
			else
				exec_op(context, PB);
		}
		while (context->stack_b)
			exec_op(context, PA);
		bit++;
	}
}

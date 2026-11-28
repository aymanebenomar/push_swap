/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 15:37:48 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/21 18:42:47 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_op	rev_op(t_op op)
{
	if (op == RA)
		return (RRA);
	return (RRB);
}

void	rotate_stack(t_ctx *context, int pos, int size, t_op fwd)
{
	int	i;

	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			exec_op(context, fwd);
	}
	else
	{
		i = pos;
		while (i++ < size)
			exec_op(context, rev_op(fwd));
	}
}

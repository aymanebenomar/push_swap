/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 14:37:45 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/23 14:58:01 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	min_pos(t_stack *a)
{
	int	min;
	int	best;
	int	pos;

	if (!a)
		return (0);
	min = a->value;
	pos = 0;
	best = 0;
	while (a)
	{
		if (a->value < min)
		{
			min = a->value;
			best = pos;
		}
		pos++;
		a = a->next;
	}
	return (best);
}

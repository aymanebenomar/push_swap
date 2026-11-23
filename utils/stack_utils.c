/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:01:18 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/23 15:01:21 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_stack *a)
{
	int	len;

	len = 0;
	while (a)
	{
		len++;
		a = a->next;
	}
	return (len);
}

int	is_sorted(t_stack *a)
{
	t_stack	*nxt;

	if (!a)
		return (1);
	while (a->next)
	{
		nxt = a->next;
		if (a->value > nxt->value)
			return (0);
		a = a->next;
	}
	return (1);
}
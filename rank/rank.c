/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/19 16:58:41 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/19 17:17:28 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	assign_index(t_stack *a)
{
	t_stack	*cur;
	t_stack	*cmp;
	int		count;

	cur = a;
	while (cur)
	{
		count = 0;
		cmp = a;
		while (cmp)
		{
			if (cmp->value < cur->value)
				count++;
			cmp = cmp->next;
		}
		cur->index = count;
		cur = cur->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disorder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 15:00:52 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/23 15:00:55 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

double	compute_disorder(t_stack *a)
{
	long	mistakes;
	long	total;
	t_stack	*cur;
	t_stack	*cmp;

	mistakes = 0;
	total = 0;
	cur = a;
	while (cur)
	{
		cmp = cur->next;
		while (cmp)
		{
			total++;
			if (cmp->value < cur->value)
				mistakes++;
			cmp = cmp->next;
		}
		cur = cur->next;
	}
	if (total == 0)
		return (0);
	return ((double)mistakes / total);
}
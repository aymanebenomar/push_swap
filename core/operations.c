/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:18:17 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/18 18:33:41 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **s)
{
	t_stack	*save;
	t_stack	*first;
	t_stack	*second;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	second = (*s)->next;
	save = second->next;
	first->next = save;
	second->next = first;
	*s = second;
}

void	push(t_stack **from, t_stack **to)
{
	t_stack	*save;
	t_stack	*topush;

	if (!*from)
		return ;
	topush = *from;
	*from = (*from)->next;
	save = *to;
	*to = topush;
	topush->next = save;
}

void	rotate(t_stack **s)
{
	t_stack	*first;
	t_stack	*cpy;

	if (!*s || !(*s)->next)
		return ;
	first = *s;
	cpy = *s;
	while (cpy->next)
		cpy = cpy->next;
	*s = first->next;
	cpy->next = first;
	first->next = NULL;
}

void	reverse_rotate(t_stack **s)
{
	t_stack	*last;
	t_stack	*beforelast;

	if (!*s || !(*s)->next)
		return ;
	last = *s;
	beforelast = *s;
	while (beforelast->next->next)
		beforelast = beforelast->next;
	last = beforelast->next;
	last->next = *s;
	*s = last;
	beforelast->next = NULL;
}
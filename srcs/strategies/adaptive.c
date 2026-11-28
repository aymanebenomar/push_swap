/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 20:28:56 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/21 18:17:47 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pick_strategy(double disorder)
{
	if (disorder < 0.2)
		return (SIMPLE);
	if (disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

void	sort_adaptive(t_ctx *context)
{
	if (stack_size(context->stack_a) <= 5)
		sort_tiny(context);
	else if (context->used == SIMPLE)
		sort_simple(context);
	else if (context->used == MEDIUM)
		sort_medium(context);
	else
		sort_complex(context);
}

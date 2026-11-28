/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/15 18:57:53 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/25 12:52:40 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	finish(t_ctx *context, t_flags *flags, double disorder)
{
	int	ok;

	ok = flush_ops(context);
	if (ok && flags->bench)
		print_bench(context, flags, disorder);
	stack_clear(&context->stack_a);
	stack_clear(&context->stack_b);
	free(context->ops);
	if (!ok)
		return (write(2, "Error\n", 6), 1);
	return (!ok);
}

int	main(int ac, char **av)
{
	t_ctx	context;
	t_flags	flags;
	double	disorder;

	if (ac < 2)
		return (0);
	if (parse_flags(ac, av, &flags) < 0)
		return (write(2, "Error\n", 6), 1);
	ft_bzero(&context, sizeof(context));
	if (!parse_args(ac, av, &context.stack_a))
		return (write(2, "Error\n", 6), 1);
	if (!context.stack_a)
		return (0);
	disorder = compute_disorder(context.stack_a);
	engine_run(&context, &flags, disorder);
	return (finish(&context, &flags, disorder));
}

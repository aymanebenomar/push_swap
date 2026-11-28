/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:13:12 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/27 16:55:48 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

static int	print_error(t_ctx *context)
{
	stack_clear(&context->stack_a);
	stack_clear(&context->stack_b);
	write(2, "Error\n", 6);
	return (1);
}

static int	has_flag(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_ctx	context;

	if (ac < 2)
		return (0);
	ft_bzero(&context, sizeof(context));
	if (has_flag(ac, av) || !parse_args(ac, av, &context.stack_a))
		return (print_error(&context));
	if (!read_ops(&context))
		return (print_error(&context));
	if (is_sorted(context.stack_a) && !context.stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	stack_clear(&context.stack_a);
	stack_clear(&context.stack_b);
	return (0);
}

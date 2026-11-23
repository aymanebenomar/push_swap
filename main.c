/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 16:10:07 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/23 16:10:08 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_ctx	ctx;

	if (ac < 2)
		return (0);
	ctx.b = NULL;
	ft_bzero(ctx.counts, sizeof(ctx.counts));
	if (parse_flags(ac, av, &ctx.flags) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ctx.a = parse_args(ac, av);
	assign_index(ctx.a);
	sort_simple(&ctx);

	//print_stack("simple", ctx.a);
	free_stack(&ctx.a);
	free_stack(&ctx.b);
	return (0);
}
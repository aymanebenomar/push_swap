/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bench.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 20:44:48 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/25 12:57:25 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static const char	*strategy_name(t_flags *flag)
{
	static const char	*names[] = {"Adaptive", "Simple", "Medium",
		"Complex"};

	return (names[flag->strategy]);
}

static const char	*complexity(int strategy)
{
	if (strategy == SIMPLE)
		return ("O(n^2)");
	if (strategy == MEDIUM)
		return ("O(n\xe2\x88\x9a" "n)");
	return ("O(n log n)");
}

static void	print_counts(t_ctx *context, int from, int to)
{
	ft_putstr_fd("[bench]", 2);
	while (from < to)
	{
		ft_putstr_fd(" ", 2);
		ft_putstr_fd((char *)op_name(from), 2);
		ft_putstr_fd(": ", 2);
		ft_putnbr_fd(context->count[from], 2);
		from++;
	}
	ft_putchar_fd('\n', 2);
}

static void	print_percent(double disorder)
{
	int	num;

	num = (int)(disorder * 100 * 100 + 0.5);
	ft_putnbr_fd(num / 100, 2);
	ft_putchar_fd('.', 2);
	if (num % 100 < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(num % 100, 2);
	ft_putchar_fd('%', 2);
}

void	print_bench(t_ctx *context, t_flags *flag, double disorder)
{
	ft_putstr_fd("[bench] disorder: ", 2);
	print_percent(disorder);
	ft_putstr_fd("\n[bench] strategy: ", 2);
	ft_putstr_fd((char *)strategy_name(flag), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd((char *)complexity(context->used), 2);
	ft_putstr_fd("\n[bench] total_ops: ", 2);
	ft_putnbr_fd(context->ops_len, 2);
	ft_putchar_fd('\n', 2);
	print_counts(context, SA, PB + 1);
	print_counts(context, RA, RRR + 1);
}

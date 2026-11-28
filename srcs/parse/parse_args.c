/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:44:02 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/18 15:39:06 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	to_int(char *str, int *out)
{
	long	n;
	int		sign;

	sign = 1;
	n = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (!*str)
		return (0);
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (0);
		n = n * 10 + (*str++ - '0');
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
	}
	*out = (int)(n * sign);
	return (1);
}

static int	has_duplicate(t_stack *stack, int value)
{
	while (stack)
	{
		if (stack->value == value)
			return (1);
		stack = stack->next;
	}
	return (0);
}

static int	add_number(t_stack **stack, t_stack **last, char *str)
{
	t_stack	*node;
	int		value;

	if (!to_int(str, &value) || has_duplicate(*stack, value))
		return (0);
	node = stack_new(value);
	if (!node)
		return (0);
	if (!*stack)
		*stack = node;
	else
		(*last)->next = node;
	*last = node;
	return (1);
}

static int	add_tokens(t_stack **stack, t_stack **last, char **tokens)
{
	int	j;

	if (!tokens || !tokens[0])
		return (0);
	j = 0;
	while (tokens[j])
	{
		if (!add_number(stack, last, tokens[j]))
			return (0);
		j++;
	}
	return (1);
}

int	parse_args(int ac, char **av, t_stack **stack)
{
	t_stack	*last;
	char	**tokens;
	int		i;

	i = 1;
	last = NULL;
	while (i < ac)
	{
		if (!(av[i][0] == '-' && av[i][1] == '-'))
		{
			tokens = ft_split(av[i], ' ');
			if (!add_tokens(stack, &last, tokens))
			{
				free_split(tokens);
				stack_clear(stack);
				return (0);
			}
			free_split(tokens);
		}
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:11:50 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/17 17:26:22 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_stack **a, char **arr)
{
	free_stack(a);
	free_split(arr);
	write(2, "Error\n", 6);
	exit(1);
}

int	to_int(char *s, int *out)
{
	int sign = 1;
	long result = 0;
	int i = 0;
	if (s[i] == '-' || s[i] == '+'){
		if (s[i] == '-')
			sign = -1;
		i++;}
	while (ft_isdigit(s[i])){
		result = (result * 10) + (s[i] - '0');
		if (((result * sign > INT_MAX) || (result * sign) < INT_MIN))
			return (0);
		i++;}
	*out = (int)(result * sign);
	return (1);
}

int is_valid_number(char *s)
{
	int	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!ft_isdigit(s[i]))
		return (0);
	while (ft_isdigit(s[i]))
		i++;
	if (s[i])
		return (0);
	return (1);
}

int		has_duplicate(t_stack *a, int n)
{
	while (a)
	{
		if (a->value == n)
			return (1);
		a = a->next;
	}
	return (0);
}

t_stack	*parse_args(int ac, char **av)
{
	t_stack	*a;
	char	**arr;
	int		i;
	int		j;
	int		n;

	i = 1;
	a = NULL;
	while (i < ac)
	{
		if (av[i][0] == '-' && av[i][1] == '-')
		{
			i++;
			continue;
		}
		arr = ft_split(av[i], ' ');
		if (!arr || !arr[0])
			error_exit(&a, arr);
		j = 0;
		while (arr[j])
		{
			if (!is_valid_number(arr[j]))
				error_exit(&a, arr);
			if (!to_int(arr[j], &n))
				error_exit(&a, arr);
			if (has_duplicate(a, n))
				error_exit(&a, arr);
			if (!add_bottom(&a, n))
				error_exit(&a, arr);
			j++;
		}
		free_split(arr);
		i++;
	}
	return (a);
}

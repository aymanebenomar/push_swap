/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 15:39:25 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/17 16:48:08 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *str)
{
	if (str[0] == '-' && str[1] == '-')
		return (1);
	return (0);
}

static int	set_flag(char *str, t_flags *f)
{
	if (ft_strncmp(str, "--bench", 8) == 0)
		f->bench = 1;
	else if (ft_strncmp(str, "--simple", 9) == 0)
		f->strategy = SIMPLE;
	else if (ft_strncmp(str, "--medium", 9) == 0)
		f->strategy = MEDIUM;
	else if (ft_strncmp(str, "--adaptive", 11) == 0)
		f->strategy = ADAPTIVE;
	else if (ft_strncmp(str, "--complex", 10) == 0)
		f->strategy = COMPLEX;
	else
		return (0);
	return (1);
}

int	parse_flags(int ac, char **av, t_flags *f)
{
	int	i;

	f->strategy = ADAPTIVE;
	f->bench = 0;
	i = 1;
	while (i < ac)
	{
		if (is_flag(av[i]) && !set_flag(av[i], f))
			return (-1);
		i++;
	}
	return (1);
}
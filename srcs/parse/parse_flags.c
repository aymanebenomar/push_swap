/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 17:59:13 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/18 15:39:23 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_flag(char *str)
{
	return (str[0] == '-' && str[1] == '-');
}

static int	set_flag(char *str, t_flags *flag)
{
	if (!ft_strncmp(str, "--bench", 8))
		flag->bench = 1;
	else if (!ft_strncmp(str, "--simple", 9))
		flag->strategy = SIMPLE;
	else if (!ft_strncmp(str, "--medium", 9))
		flag->strategy = MEDIUM;
	else if (!ft_strncmp(str, "--complex", 10))
		flag->strategy = COMPLEX;
	else if (!ft_strncmp(str, "--adaptive", 11))
		flag->strategy = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	parse_flags(int ac, char **av, t_flags *flag)
{
	int	i;

	flag->strategy = ADAPTIVE;
	flag->bench = 0;
	i = 1;
	while (i < ac)
	{
		if (is_flag(av[i]) && !set_flag(av[i], flag))
			return (-1);
		i++;
	}
	return (i);
}

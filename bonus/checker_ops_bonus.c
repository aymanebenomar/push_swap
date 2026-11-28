/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_ops_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 21:13:30 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/27 16:55:52 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	find_op(const char *line)
{
	int		i;
	size_t	len;

	i = 0;
	while (i < 11)
	{
		len = ft_strlen(op_name(i));
		if (!ft_strncmp(line, op_name(i), len)
			&& line[len] == '\n' && !line[len + 1])
			return (i);
		i++;
	}
	return (-1);
}

int	read_ops(t_ctx *context)
{
	char	*line;
	int		op;
	int		valid;

	valid = 1;
	line = get_next_line(0);
	while (line)
	{
		op = find_op(line);
		if (op < 0)
			valid = 0;
		else if (valid)
			run_op(context, op);
		free(line);
		line = get_next_line(0);
	}
	return (valid);
}

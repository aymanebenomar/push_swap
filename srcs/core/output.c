/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/18 16:06:20 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/25 15:09:59 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	count_ops(t_ctx *context)
{
	int	i;

	i = 0;
	while (i < 11)
		context->count[i++] = 0;
	i = 0;
	while (i < context->ops_len)
	{
		context->count[context->ops[i]]++;
		i++;
	}
}

static void	fill_output(char *buf, t_ctx *context)
{
	const char	*name;
	size_t		len;
	int			i;

	i = 0;
	while (i < context->ops_len)
	{
		name = op_name(context->ops[i++]);
		len = ft_strlen(name);
		ft_memcpy(buf, name, len);
		buf[len] = '\n';
		buf += len + 1;
	}
}

static char	*build_output(t_ctx *context, size_t *len)
{
	char	*buf;
	int		i;

	*len = 0;
	i = 0;
	while (i < context->ops_len)
		*len += ft_strlen(op_name(context->ops[i++])) + 1;
	buf = malloc(*len + 1);
	if (buf)
		fill_output(buf, context);
	return (buf);
}

int	flush_ops(t_ctx *context)
{
	char	*buf;
	size_t	len;
	int		ret;

	if (context->fail)
		return (0);
	count_ops(context);
	buf = build_output(context, &len);
	if (!buf)
		return (0);
	ret = write(1, buf, len);
	free(buf);
	return (ret >= 0);
}

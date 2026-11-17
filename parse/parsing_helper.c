/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenomar <abenomar@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 14:11:47 by abenomar          #+#    #+#             */
/*   Updated: 2026/11/17 14:24:35 by abenomar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

int		add_bottom(t_stack **a, int n)
{
	t_stack *ca;
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return (0);
	new->index = 0;
	new->value = n;
	new->next = NULL;
	if (!*a){
		*a = new;
		return (1);}
	ca = *a;
	while (ca->next)
		ca = ca->next;
	ca->next = new;
	return (1);
}

void	free_stack(t_stack **a)
{
	t_stack	*save;
	
	if (!a)
		return ;
	while (*a)
	{
		save = (*a)->next;
		free(*a);
		*a = save;
	}
}

void	free_split(char **arr)
{
	int i = 0;

	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	error_exit(t_stack **a, char **arr)
{
	free_stack(a);
	free_split(arr);
	write(2, "Error\n", 6);
}
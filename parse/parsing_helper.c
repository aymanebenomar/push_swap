
#include "push_swap.h"

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
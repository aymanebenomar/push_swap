
#include "push_swap.h"

int main(int ac, char **av)
{
	t_flags f;
	t_stack *a;
	t_stack *tmp;

	if (ac < 2)
		return 0;
	if (parse_flags(ac, av, &f) == -1)
	{
		write (2, "Error\n", 6);
		return (1);
	}
	a = parse_args(ac, av);
	tmp = a;
	while (tmp)
	{
		printf("%d\n", tmp->value);
		tmp = tmp->next;
	}
	printf("bench -> %d  strategy -> %d", f.bench, f.strategy);
	free_stack(&a);
	return (0);
}
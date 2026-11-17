
#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*tmp;
	t_flags	f;

	if (ac < 2)
		return (0);
	if (parse_flags(ac, av, &f) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	a = parse_args(ac, av);
	tmp = a;
	while (tmp)
	{
		printf("%d ", tmp->value);
		tmp = tmp->next;
	}
	printf("\nstrategy=%d bench=%d\n", f.strategy, f.bench);
	free_stack(&a);
	return (0);
}
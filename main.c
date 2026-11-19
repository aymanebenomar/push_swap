/* int main(int ac, char **av)
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
} */

#include "push_swap.h"

void	print_stack(char *name, t_stack *s)
{
	printf("%s: ", name);
	while (s)
	{
		printf("value %d | rank %d\n", s->value, s->index);
		s = s->next;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_ctx	ctx;

	if (ac < 2)
		return (0);
	ctx.b = NULL;
	ft_bzero(ctx.counts, sizeof(ctx.counts));
	if (parse_flags(ac, av, &ctx.flags) == -1)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	ctx.a = parse_args(ac, av);
	exec_op(&ctx, PB);
	exec_op(&ctx, PB);
	exec_op(&ctx, SB);
	exec_op(&ctx, RR);
	exec_op(&ctx, PA);
	exec_op(&ctx, PA);

	assign_index(ctx.a);
	assign_index(ctx.b);

	print_stack("a", ctx.a);
	print_stack("b", ctx.b);
	printf("pb count: %d\n", ctx.counts[PB]);
	printf("pa count: %d\n", ctx.counts[PA]);
	free_stack(&ctx.a);
	free_stack(&ctx.b);
	return (0);
}
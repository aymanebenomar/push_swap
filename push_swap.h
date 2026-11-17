
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
}	t_stack;

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

typedef struct s_flags
{
	t_strategy	strategy;   // which algorithm to use
	int			bench;      // 1 if --bench was given, else 0
	int			chosen;     // 1 once a strategy flag was seen
}	t_flags;

// parsing 
int		to_int(char *s, int *out);
int 	is_valid_number(char *s);
int		has_duplicate(t_stack *a, int n);
int		add_bottom(t_stack **a, int n);
void	free_stack(t_stack **a);
void	free_split(char **arr);
void	error_exit(t_stack **a, char **arr);
int		parse_flag(char *arg, t_flags *f);
t_stack	*parse_args(int ac, char **av, t_flags *f);

#endif
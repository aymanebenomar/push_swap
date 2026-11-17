
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *next;
}	t_stack;



// parsing 

int		to_int(char *s, int *out);
int 	is_valid_number(char *s);
int 	ft_isdigit(char c);
int		has_duplicate(t_stack *a, int n);
int		add_bottom(t_stack **a, int n);
void	free_stack(t_stack **a);
void	free_split(char **arr);
void	error_exit(t_stack **a, char **arr);
t_stack	*parse_args(int ac, char **av);

#endif
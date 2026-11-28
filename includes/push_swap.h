/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sfaraji <sfaraji@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 15:48:37 by sfaraji           #+#    #+#             */
/*   Updated: 2026/11/26 18:20:51 by sfaraji          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

# define OP_END -1

/*--------| Stack Struct |--------*/

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/*-------| Strategy Enum |-------*/

typedef enum e_strategy
{
	ADAPTIVE,
	SIMPLE,
	MEDIUM,
	COMPLEX
}	t_strategy;

/*---------| Strategy |---------*/

typedef struct s_flags
{
	int	strategy;
	int	bench;
}	t_flags;

/*------| Operation Struct |------*/

typedef enum e_op
{
	SA,
	SB,
	SS,
	PA,
	PB,
	RA,
	RB,
	RR,
	RRA,
	RRB,
	RRR
}	t_op;

/*------| Program Context |------*/

typedef struct s_ctx
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	int				count[11];
	int				used;
	unsigned char	*ops;
	int				ops_len;
	int				ops_cap;
	int				fail;
}	t_ctx;

/*-----| Operation Function |-----*/

void		op_swap(t_stack **stack);
void		op_push(t_stack **from, t_stack **to);
void		op_rotate(t_stack **stack);
void		op_rev_rotate(t_stack **stack);
void		exec_op(t_ctx *context, t_op op);
void		run_op(t_ctx *context, t_op op);
const char	*op_name(t_op op);

/*----------| Function |----------*/

int			parse_args(int ac, char **av, t_stack **stack);
int			parse_flags(int ac, char **av, t_flags *flag);
void		free_split(char **tokens);
t_stack		*stack_new(int value);
void		stack_clear(t_stack **stack);
double		compute_disorder(t_stack *stack_a);
void		engine_run(t_ctx *context, t_flags *flag, double disorder);

/*----------| Stack Check |----------*/

int			stack_size(t_stack *stack);
int			is_sorted(t_stack *stack);
int			ft_isqrt(int n);
void		assign_rank(t_stack *stack);

/*----------| Sort Algorithm |----------*/

void		sort_simple(t_ctx *context);
void		sort_complex(t_ctx *context);
void		sort_medium(t_ctx *context);
void		sort_adaptive(t_ctx *context);
void		sort_tiny(t_ctx *context);
int			min_pos(t_stack *stack_a);
int			pick_strategy(double disorder);

/*----------| Rotation helpers |----------*/

void		rotate_stack(t_ctx *context, int pos, int size, t_op fwd);
int			succ_pos(t_stack *stack, int index);

/*----------| Output |----------*/

int			flush_ops(t_ctx *context);

/*----------| Stack Bench |----------*/

void		print_bench(t_ctx *context, t_flags *flag, double disorder);

#endif
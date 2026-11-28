NAME		= push_swap
BONUS		= checker
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Iincludes -Ilibft
LIBFT		= libft/libft.a
HEADERS		= includes/push_swap.h includes/checker_bonus.h

SRCS		= srcs/main.c \
			  srcs/bench/bench.c \
			  srcs/core/disorder.c \
			  srcs/core/engine.c \
			  srcs/core/ops_basic.c \
			  srcs/core/ops_exec.c \
			  srcs/core/output.c \
			  srcs/core/rank.c \
			  srcs/parse/parse_args.c \
			  srcs/parse/parse_flags.c \
			  srcs/strategies/adaptive.c \
			  srcs/strategies/complex.c \
			  srcs/strategies/medium.c \
			  srcs/strategies/rotate.c \
			  srcs/strategies/simple.c \
			  srcs/strategies/tiny_sort.c \
			  srcs/utils/m_utils.c \
			  srcs/utils/s_utils.c

BONUS_SRCS	= bonus/checker_bonus.c \
			  bonus/checker_ops_bonus.c \
			  srcs/core/ops_basic.c \
			  srcs/core/ops_exec.c \
			  srcs/parse/parse_args.c \
			  srcs/utils/m_utils.c \
			  srcs/utils/s_utils.c

OBJS		= $(SRCS:.c=.o)
BONUS_OBJS	= $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBFT) -o $(BONUS)

$(LIBFT):
	make -C libft

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME) $(BONUS)
	make -C libft fclean

re: fclean all

.SECONDARY: $(OBJS) $(BONUS_OBJS)

.PHONY: all bonus clean fclean re
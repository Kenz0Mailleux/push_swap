NAME = push_swap
CHECK = checker

SRCS =  push_operation.c \
		push_swap.c \
		swap_operation.c \
		rotate_first_operation.c \
		rotate_last_operation.c \
		utils.c \
		parse_input.c \
		sort_small_stack.c \
		init_stack.c \
		check_valid.c \
		
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g -Iincludes

RM = rm -rf

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re
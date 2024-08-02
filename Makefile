NAME = push_swap
CHECK = checker

SRCS =  algo.c \
		free_lst.c \
		init_stack.c \
		parse.c \
		push_swap.c \
		operation_push.c \
		operation_swap.c \
		operation_rotate_first.c \
		operation_rotate_last.c \
		sort.c \
		utils.c \
		
OBJS = ${SRCS:.c=.o}

CC = cc
CFLAGS = -Wall -Wextra -Werror

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

CHECKER =checker

NAME =	push_swap

CC =	clang

CFLAGS = -Wall -Werror -Wextra
CFLAGS += -fsanitize=address

INCLUDE = -I ./includes/ -I ./LIBFT_DIR/

LIBFT_DIR = Libft/

SRCS =	srcs/push_swap.c


OBJS =	${SRCS:.c=.o}

.c.o:
		@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o ${<:.c=.o}

all:	$(NAME)

$(NAME):$(OBJS)
		@$(MAKE) -C ./libft/ >/dev/null
		@$(CC) $(OBJS) $(INCLUDE) $(CFLAGS) ./libft/libft.a -o $(NAME)

$(CHECKER):$(OBJS)
		@$(MAKE) -C ./libft/ >/dev/null
		@$(CC) $(OBJS) $(INCLUDE) $(CFLAGS) ./libft/libft.c -o $(CHECKER)

clean:
		@rm -rf $(OBJS)
		@$(MAKE) clean -C ./libft/ >/dev/null

fclean:
		@rm -rf $(OBJS)
		@$(MAKE) fclean -C ./libft/ >/dev/null
		@rm -rf $(NAME)

re:		fclean all

.PHONY:	all clean fclean re

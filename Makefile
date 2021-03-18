
CHECKER =		checker

PUSH =			push_swap

CC =			clang

#CFLAGS = 		-Wall -Werror -Wextra
#CFLAGS +=		-fsanitize=address

INCL =	 		-I ./includes/ -I ./LIBFT_DIR/

LIBFT_DIR = 	Libft/

SRCS =			srcs/utils/check_arg.c \
				srcs/utils/init_all.c \
				srcs/utils/operation.c \
				srcs/utils/stack.c \
				srcs/utils/push.c \
				srcs/utils/swap.c \
				srcs/utils/rotate.c \
				srcs/utils/reverse_rotate.c

SRCS_CHECKER =	srcs/checker/main.c \
				srcs/checker/instruction.c

SRCS_PUSH =		srcs/push_swap/main.c

OBJS =			${SRCS:.c=.o}

O_CHECK =		${SRCS_CHECKER:.c=.o}

O_PUSH =		${SRCS_PUSH:.c=.o}

.c.o:
		@$(CC) $(CFLAGS) $(INC) -c $< -o ${<:.c=.o}

all:	$(PUSH) $(CHECKER)

$(PUSH):$(OBJS) $(O_PUSH)
		@$(MAKE) -C ./libft/ >/dev/null
		@$(CC) $(OBJS) $(O_PUSH) $(INC) $(CFLAGS) ./libft/libft.a -o $(PUSH)

$(CHECKER):$(OBJS) $(O_CHECK)
		@$(MAKE) -C ./libft/ >/dev/null
		@$(CC) $(OBJS) $(O_CHECK) $(INC) $(CFLAGS) ./libft/libft.a -o $(CHECKER)

clean:
		@rm -rf $(OBJS)
		@rm -rf $(OBJS_CHECKER)
		@rm -rf $(OBJS_PUSH)
		@$(MAKE) clean -C ./libft/ >/dev/null

fclean:
		@rm -rf $(OBJS)
		@rm -rf $(O_CHECK)
		@rm -rf $(O_PUSH)
		@$(MAKE) fclean -C ./libft/ >/dev/null
		@rm -rf $(PUSH)
		@rm -rf $(CHECKER)

re:		fclean all

.PHONY:	all clean fclean re

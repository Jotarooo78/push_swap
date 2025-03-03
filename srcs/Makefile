NAME = push_swap

CC = cc

SRCS = main.c check_and_fill_stack.c list_utils.c p_instructions.c rr_instructions.c rrr_instructions.c s_instructions.c init_stack.c sort_utils.c sort_stack.c ft_split.c ft_printf_function.c ft_printf.c

INCLUDES = push_swap.h

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wall -g3

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

.c.o :
		$(CC) $(CFLAGS) -c -I $(INCLUDES) $< -o $@

clean :
		rm -rf $(OBJ)

fclean : clean
		rm -rf $(NAME)

re :
		make fclean all

.PHONY: clean fclean all re
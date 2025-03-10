NAME = push_swap

CC = cc

SRCS = srcs/main.c srcs/check_and_fill_stack.c srcs/list_utils.c srcs/p_instructions.c srcs/rr_instructions.c srcs/rrr_instructions.c srcs/s_instructions.c srcs/setup_stack_a.c srcs/setup_stack_b.c srcs/sort_utils.c srcs/sort_stack.c srcs/free_functions.c srcs/ft_split.c srcs/ft_printf_function.c srcs/ft_printf.c

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
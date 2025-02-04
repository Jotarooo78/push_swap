#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_stack
{
    int value;
    int cost;
    struct s_stack *next;
    
} t_stack;

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

// list functions

t_stack	*ft_lstlast(t_stack *lst);
int ft_lstsize(t_stack *lst);
int add_node(t_stack **list, int n);
// void	ft_lstdelone(t_stack *lst, void (*del)(int *));
// void	ft_lstclear(t_stack **lst, void (*del)(int *));
void fill_stack(t_stack **stack_a, int ac, char **av);

// instruction functions

void	swap(t_stack **stack);
int swap_a(t_stack **stack_a);
int swap_b(t_stack **stack_b);
int swap_ss(t_stack **stack_a, t_stack **stack_b);
void push(t_stack **stack_send, t_stack **stack_receive);
int push_a(t_stack **stack_b, t_stack **stack_a);
int push_b(t_stack **stack_a, t_stack **stack_b);
void  rotate(t_stack **stack);
int   rotate_a(t_stack **stack_a);
int    rotate_b(t_stack **stack_b);
int    rotate_rr(t_stack **stack_a, t_stack **stack_b);
void  rev_rotate(t_stack **stack);
int   rev_rotate_a(t_stack **stack_a);
int    rev_rotate_b(t_stack **stack_b);
int    rev_rotate_rr(t_stack **stack_a, t_stack **stack_b);


// printf functions

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr_base(long n, char *base, int baselen);
int	check_arg(int ac, char **av);
int	ft_strlen(const char *str);
int	ft_printf(const char *str, ...);
int	ft_unsigned_putnbr_base(unsigned long n, char *base, int baselen);

//parcing functions

long	ft_atol(char *nbr);
int	check_arg(int ac, char **av);
int	only_valid_characters(char c);
int	ft_has_dup(int ac, char **av);
int	only_decimal_and_sign(int c);
int	correct_imput(int ac, char **av);

// sort functions

int   stack_sorted(t_stack **stack_a);
t_stack   *find_highest(t_stack **stack);
t_stack  *find_lowest(t_stack **stack);
void  small_sort(t_stack **stack);
void  sort_stack(t_stack **stack_a, t_stack **stack_b);

#endif
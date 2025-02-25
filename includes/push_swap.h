#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct s_stack
{
    int value;
    int index;
    int cost;
    int median_up;
    int cheap;

    struct s_stack *next;
    struct s_stack *target_node;
    
}   t_stack;

// list functions

t_stack	*ft_lstlast(t_stack *lst);
int ft_lstsize(t_stack *lst);
int add_node(t_stack **list, int n);

// printf functions

int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_putnbr_base(long n, char *base, int baselen);
int	check_arg(int ac, char **av);
int	ft_strlen(const char *str);
int	ft_printf(const char *str, ...);
int	ft_unsigned_putnbr_base(unsigned long n, char *base, int baselen);

// instruction functions

void	swap(t_stack **stack);
int swap_a(t_stack **a);
int swap_b(t_stack **b);
int swap_ss(t_stack **a, t_stack **b);
void push(t_stack **stack_send, t_stack **stack_receive);
int push_a(t_stack **b, t_stack **a);
int push_b(t_stack **a, t_stack **b);
void  rotate(t_stack **stack);
int   rotate_a(t_stack **a);
int    rotate_b(t_stack **b);
int    rotate_rr(t_stack **a, t_stack **b);
void  rev_rotate(t_stack **stack);
int   rev_rotate_a(t_stack **a);
int    rev_rotate_b(t_stack **b);
int    rev_rotate_rr(t_stack **a, t_stack **b);


//parcing functions

long	ft_atol(char *nbr);
int	only_valid_characters(char c);
int duplicate_error(t_stack *a, int n);
int	correct_imput(char **av);
void fill_stack_a(t_stack **a, char **av);

// sort functions

int   stack_sorted(t_stack **stack_a);
t_stack   *find_highest(t_stack **stack);
t_stack  *find_lowest(t_stack **stack);
void   node_pos(t_stack *stack);
void  small_sort(t_stack **stack);
void  sort_stack(t_stack **stack_a, t_stack **stack_b);
t_stack  *define_target(t_stack *node, t_stack **stack);

#endif
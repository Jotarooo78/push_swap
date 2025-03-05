#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				cost;
	int				median;
	bool				cheap;

	struct s_stack	*next;
	struct s_stack	*target_node;

}					t_stack;

// utils list functions

t_stack				*ft_lstlast(t_stack *lst);
int					ft_lstsize(t_stack *lst);
void					add_node(t_stack **list, int nb);

// printf functions

int					ft_putchar(char c);
int					ft_putstr(const char *str);
int					ft_putnbr_base(long n, char *base, int baselen);
int					check_argument(void *ptr);
int					ft_strlen(const char *str);
int					ft_unsigned_putnbr_base(unsigned long n, char *base,
						int baselen);
int					ft_printf(const char *str, ...);
void					print_stack(t_stack **a, t_stack **b);

// instruction functions

void				swap(t_stack **stack);
int					swap_a(t_stack **a);
int					swap_b(t_stack **b);
int					swap_ss(t_stack **a, t_stack **b);
void				push(t_stack **stack_send, t_stack **stack_receive);
int					push_a(t_stack **b, t_stack **a);
int					push_b(t_stack **a, t_stack **b);
void				rotate(t_stack **stack);
int					rotate_a(t_stack **a);
int					rotate_b(t_stack **b);
int					rotate_rr(t_stack **a, t_stack **b);
void				double_rotate(t_stack **a, t_stack **b, t_stack *cheapest_node);
void				rev_rotate(t_stack **stack);
int					rev_rotate_a(t_stack **a);
int					rev_rotate_b(t_stack **b);
int					rev_rotate_rr(t_stack **a, t_stack **b);
void				double_rev_rotate(t_stack **a, t_stack **b, t_stack *cheapest_node);

// parsing functions

long				ft_atol(char *nbr);
bool					only_valid_characters(char c);
bool					duplicate_error(t_stack *a, int n);
bool					correct_input(char *av);
bool					fill_stack_a(t_stack **a, char **av);
char				**ft_split(char const *s, char c);

// sort utils

t_stack				*get_cheapest_node(t_stack **a);
t_stack				*find_highest(t_stack *stack);
t_stack				*find_lowest(t_stack *stack);
void	top_node_a_setup(t_stack **a, t_stack *top_node);
void	top_node_b_setup(t_stack **b, t_stack *top_node);

// sort functions

void				free_stack(t_stack *stack);
bool				stack_sorted(t_stack **stack_a);
void				small_sort(t_stack **stack);
void				init_stack_a(t_stack *a, t_stack *b);
void  			init_stack_b(t_stack *a, t_stack *b);
void				sort_stack(t_stack **stack_a, t_stack **stack_b);
void				get_index(t_stack *stack);
void				define_target_b(t_stack *a, t_stack *b);
void				define_target_a(t_stack *a, t_stack *b);
void				define_cost(t_stack *a, t_stack *b);
void				define_cheapest(t_stack *a);

#endif
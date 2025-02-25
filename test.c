#include "../includes/push_swap.h"

void    print_stack(t_stack *stack)
{
    while (stack)
    {
        printf("%d ", stack->value);
         stack = stack->next;
    }
    printf("NULL\n");
}
int main()
{
	t_stack	*stack_a;
	t_stack	*stack_b;

    stack_a = NULL;
    stack_b = NULL;
    
    add_node(&stack_a, 53);
    add_node(&stack_a, 7);
    add_node(&stack_a, 1);
    add_node(&stack_b, 10);
    add_node(&stack_b, 5);
    add_node(&stack_b, 14);

    push_a(&stack_a, &stack_b);
    push_a(&stack_a, &stack_b);

    printf("a stack\n");
    print_stack(stack_a);
    printf("b stack\n");
    print_stack(stack_b);
    printf("\n");

    t_stack *target = target_node(stack_a, &stack_b);
    t_stack *highest = find_highest(&stack_b);

    printf("target : %d\n", target->value);
    printf("highest : %d\n", highest->value);

    print_stack(stack_a);
    print_stack(stack_b);
    return (0);
}
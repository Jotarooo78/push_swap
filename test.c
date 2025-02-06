#include "includes/push_swap.h"

t_stack  *find_lowest(t_stack **stack)
{
   t_stack *current;
   t_stack *low_value;
   int   min;

   min = INT_MAX;
   current = *stack;
   low_value = *stack;
   while (current)
   {
      if (current->value < min)
      {
         low_value = current;
         min = low_value->value;
      }
      current = current->next;
   }
   return (low_value);
}

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
    add_node(&stack_a, 2);
    add_node(&stack_a, 3);
    add_node(&stack_b, 10);
    add_node(&stack_b, 3);
    add_node(&stack_b, 14);
    t_stack *va = find_lowest(&stack_a);
    t_stack *vb = find_lowest(&stack_b);

    printf("%d\n", va->value);
    printf("%d\n", vb->value);


    print_stack(stack_a);
    print_stack(stack_b);
    return (0);
}
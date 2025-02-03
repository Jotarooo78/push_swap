/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/03 15:27:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    t_stack *value;

    stack_a = NULL;
    stack_b = NULL;
    
    add_node(&stack_a, 3);
    add_node(&stack_a, 2);
    add_node(&stack_a, 1);
    add_node(&stack_b, 5);
    add_node(&stack_b, 6);
    add_node(&stack_b, 7);

    print_stack(stack_a);
    value = find_highest(&stack_a);
    printf("%d\n", value->value);
    small_sort(&stack_a);
    print_stack(stack_a);


    if (correct_imput(ac - 1, av + 1) == 0)
        return (ft_printf("Error\n"));
    fill_list(&stack_a, ac, av);
    if (ft_lstsize(*stack_a) < 4)
        small_sort(&stack_a);
    sort_list(&stack, &stack_b);
    return (0);
}
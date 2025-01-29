/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/29 23:07:55 by marvin           ###   ########.fr       */
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

    stack_a = NULL;
    stack_b = NULL;
    
    add_node(&stack_a, 1);
    add_node(&stack_a, 2);
    add_node(&stack_a, 3);
    add_node(&stack_a, 4);
    add_node(&stack_b, 5);
    add_node(&stack_b, 6);
    add_node(&stack_b, 7);
    add_node(&stack_b, 8);

    print_stack(stack_a);
    print_stack(stack_b);
    
    rev_rotate_rr(&stack_a, &stack_b);
    
    print_stack(stack_a);
    print_stack(stack_b);
    return (0);

    // if (correct_imput(ac - 1, av + 1) == 0)
    //     return (ft_printf("Error\n"));
    // fill_list(&stack_a, ac, av);
}
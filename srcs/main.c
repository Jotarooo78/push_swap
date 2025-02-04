/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/04 15:27:35 by marvin           ###   ########.fr       */
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
int main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

    stack_a = NULL;
    stack_b = NULL;
    ac -= 1;
    av += 1;
    if (correct_imput(ac, av) == 0)
        return (ft_printf("Error\n"));
    fill_stack(&stack_a, ac, av);
    if (stack_sorted(&stack_a) == 0)
    {
        if (ft_lstsize(stack_a) == 2)
            swap_a(&stack_a);
        else if (ft_lstsize(stack_a) == 3)
            small_sort(&stack_a);
        else
            sort_stack(&stack_a, &stack_b);
    }
    print_stack(stack_a);
    (void)stack_b;
    return (0);
}
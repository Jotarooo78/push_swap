/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:00:22 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/29 11:53:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    swap(t_stack **stack)
{
    t_stack *head;
    t_stack *tmp;
    int swap;

    head = *stack;
    tmp = head->next;
    swap = head->value;
    head->value = tmp->value;
    tmp->value = swap;
}

int    swap_a(t_stack **stack_a)
{
    if (ft_lstsize(*stack_a) < 2)
        return (0) ;
    else
    {
        swap(stack_a);
        write(1, "sa\n", 3);   
    }
    return (1);
}

int    swap_b(t_stack **stack_b)
{
    if (ft_lstsize(*stack_b) < 2)
        return (0) ;
    else
    {
        swap(stack_b);
        write(1, "sb\n", 3);   
    }
    return (1);
}

int    swap_ss(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
        return (0) ;
    else
    {
        swap_a(stack_a);
        swap_b(stack_b);
        write(1, "ss\n", 3);
    }
    return (1);
}

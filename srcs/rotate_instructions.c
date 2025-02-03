/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 20:27:12 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 20:27:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void  rotate(t_stack **stack)
{
    t_stack *head;
    t_stack *current;
    int swap;

    head = *stack;
    current = head->next;
    while (head->next)
    {
        swap = head->value;
        head->value = current->value;
        current->value = swap;
        head = head->next;
        if (current->next)
            current = current->next;
    }
}
int   rotate_a(t_stack **stack_a)
{
    if (ft_lstsize(*stack_a) < 2)
        return (0) ;
    else
    {
        rotate(stack_a);
        write(1, "ra\n", 3);
    }
    return (1);
}

int    rotate_b(t_stack **stack_b)
{
    if (ft_lstsize(*stack_b) < 2)
        return (0) ;
    else
    {
        rotate(stack_b);
        write(1, "rb\n", 3);
    }
    return (1);
}

int    rotate_rr(t_stack **stack_a, t_stack **stack_b)
{
    if (ft_lstsize(*stack_a) < 2 || ft_lstsize(*stack_b) < 2)
        return (0) ;
    else
    {
        rotate_a(stack_a);
        rotate_b(stack_b);
        write(1, "rr\n", 3);
    }
    return (1);
}

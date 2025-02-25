/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 11:00:22 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/24 13:18:20 by marvin           ###   ########.fr       */
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

int    swap_a(t_stack **a)
{
    if (ft_lstsize(*a) < 2)
        return (0) ;
    else
    {
        swap(a);
        write(1, "sa\n", 3);   
    }
    return (1);
}

int    swap_b(t_stack **b)
{
    if (ft_lstsize(*b) < 2)
        return (0) ;
    else
    {
        swap(b);
        write(1, "sb\n", 3);   
    }
    return (1);
}

int    swap_ss(t_stack **a, t_stack **b)
{
    if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
        return (0) ;
    else
    {
        swap(a);
        swap(b);
        write(1, "ss\n", 3);
    }
    return (1);
}

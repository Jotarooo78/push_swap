/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_instructions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 14:38:15 by marvin            #+#    #+#             */
/*   Updated: 2025/01/27 14:38:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void    push(t_stack **stack_src, t_stack **stack_dest)
{
    t_stack *tmp;

    tmp = (*stack_src)->next; // pointeur sur le 2e noeud et sauvegarde la liste
    (*stack_src)->next = *stack_dest; // relie le 1 er noeud sur la liste dest
    *stack_dest = *stack_src; // mise a jour de la tete de liste de dest
    *stack_src = tmp; // mise a jour de la liste src
}

int push_a(t_stack **b, t_stack **a)
{
    if (ft_lstsize(*b) < 2)
        return (0);
    else
    {
        push(b, a);
        write(1, "pa\n", 3);
    }
    return (1);
}

int push_b(t_stack **a, t_stack **b)
{
    if (ft_lstsize(*a) < 2)
        return (0);
    else
    {
        push(a, b);
        write(1, "pb\n", 3);
    }
    return (1);
}

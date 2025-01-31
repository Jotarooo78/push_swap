/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:23:18 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/30 10:11:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void fill_list(t_stack **stack, int ac, char **av)
{
    int i;
    t_stack *stack;

    i = 1;
    while (i < ac)
    {
        add_node(&stack, atoi(av[i]));
        if (i == 1)
            *stack = stack;
        stack = stack->next;
        i++;
    }
    return (stack);
}
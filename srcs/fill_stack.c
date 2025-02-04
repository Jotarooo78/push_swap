/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:23:18 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/04 11:26:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void fill_stack(t_stack **stack, int ac, char **av)
{
    int i;

    i = 1;
    while (i != ac + 1)
    {
        add_node(stack, atoi(av[i]));
        *stack = (*stack)->next;
        i++;
    }
}
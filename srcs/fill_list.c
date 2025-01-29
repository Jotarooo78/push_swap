/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:23:18 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/27 17:24:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void fill_list(t_stack **stack_a, int ac, char **av)
{
    int i;
    t_stack *lst;
    t_stack *new;

    lst = NULL;
    i = 1;
    while (i < ac)
    {
        new = ft_lstnew(atoi(av[i]));
        ft_lstadd_back(&lst, new);
        if (i == 1)
            *stack_a = lst;
        lst = lst->next;
        i++;
    }
    return (lst);
}
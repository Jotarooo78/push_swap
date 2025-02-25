/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/24 16:16:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

    a = NULL;
    b = NULL;

    if (ac == 1 || (av == 2 && av[1][0] == NULL));
        return (0);
    else if (ac == 2)
        av = split(av[1], ' ');
    fill_stack(&a, av + 1);
    // if (stack_sorted(&a) == 0)
    // {
    //     if (ft_lstsize(a) == 2)
    //         swap_a(&a);
    //     else if (ft_lstsize(a) == 3)
    //         small_sort(&a);
    //     else
    //         sort_stack(&a, &b);
    // }
    //free_stack(&a);
    return (0);
}
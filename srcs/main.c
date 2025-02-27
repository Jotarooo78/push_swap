/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/26 16:13:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int   stack_sorted(t_stack **a) 
{
   t_stack  *current;

   current = *a;
   while (current->next)
   {
      if (current->value > current->next->value)
         return (0);
      current = current->next;
   }
   return (1);
}

void  init_stack(t_stack *a, t_stack *b)
{
   get_index(a);
   get_index(b);
   define_target(a, b);
   define_cost(a, b);
   define_cheapest(a);
}

int main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

    a = NULL;
    b = NULL;

    if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
        return (0);
    else if (ac == 2)
        av = ft_split(av[1], ' ');
    fill_stack_a(&a, av + 1);
    init_stack(a, b);
    if (stack_sorted(&a) == 0)
    {
        if (ft_lstsize(a) == 2)
            swap_a(&a);
        else if (ft_lstsize(a) == 3)
            small_sort(&a);
      //   else
      //       sort_stack(&a, &b);
    }
    while (a)
    {
        ft_printf("%d ", a->value);
         a = a->next;
    }
    ft_printf("NULL\n");
   return (0);
}
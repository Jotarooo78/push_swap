/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 10:08:49 by marvin            #+#    #+#             */
/*   Updated: 2025/01/30 10:08:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void  find_highest(t_stack **stack_a)
{
   if ((*stack)->value < (*stack->next)->value)
      return (printf("yes\n"));
   return (printf("no\n"));
}

void  small_sort(t_stack **stack_a)
{
   if (find_highest(*stack) == 1)
      rotate_a(&stack_a);
   else if (find_highest(stack->next) == 1)
      rotate_a(&stack_a);
}

void  sort_list(t_stack **stack_a, t_stack **stack_b)
{
   if (ft_lstsize(*stack_a) < 4)
   {
      small_sort(*stack_a);
   }
}
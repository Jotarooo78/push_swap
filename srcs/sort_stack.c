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

int   stack_sorted(t_stack **stack_a) 
{
   t_stack  *current;

   current = *stack_a;
   while (current->next)
   {
      if (current->value > current->next->value)
         return (0);
      current = current->next;
   }
   return (1);
}

t_stack  *find_lowest(t_stack **stack)
{
   t_stack *current;
   t_stack *low_value;
   int min;

   min = INT_MAX;
   current = *stack;
   low_value = *stack;
   while (current)
   {
      if (current->value < min)
      {
         low_value = current;
         min = low_value->value;
      }
      current = current->next;
   }
   return (low_value);
}

t_stack   *find_highest(t_stack **stack)
{
   t_stack *current;
   t_stack *big_value;
   int max;

   max = INT_MIN;
   current = *stack;
   big_value = *stack;
   while (current)
   {
      if (current->value > max)
      {
         big_value = current;
         max = big_value->value;
      }
      current = current->next;
   }
   return (big_value);
}
void  small_sort(t_stack **stack)
{
   t_stack *highest;

   highest = find_highest(stack);
   if ((*stack)->value == highest->value)
      rotate_a(stack);
   else if ((*stack)->next->value == highest->value)
      rotate_a(stack);
   if ((*stack)->value > (*stack)->next->value)
      swap_a(stack);
}

void  sort_stack(t_stack **stack_a, t_stack **stack_b)
{
   push_a(&stack_a, &stack_b);
   push_a(&stack_a, &stack_b);
   while (*stack_a != find_lowest(stack_a) && *stack_a != find_highest(stack_a))
   {
      push_a(stack_a, stack_b);
      *stack_a = (*stack_a)->next;
   }
   if (ft_lstsize(*stack_a) < 4)
      small_sort(stack_a);
}
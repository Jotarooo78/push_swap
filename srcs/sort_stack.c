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

t_stack  *find_lowest(t_stack **stack)
{
   t_stack *current;
   t_stack *low_value;
   int   min;

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
   int   max;

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

t_stack  *target_node(t_stack *node, t_stack **stack)
{
   t_stack *current;
   t_stack  *target;
   int min;

   min = INT_MIN;
   current = *stack;
   while (current)
   {
      if (node->value > current->value && current->value > min)
      {
         target = current;
         min = target->value;
      }
      else
      {
         target = find_highest(stack);
      }
      current = current->next;
   }
   target->index = node_pos(stack, target);
   return (target);
}

int   node_pos(t_stack **stack, t_stack *target)
{
   t_stack *current;
   int   index;

   index = 0;
   current = *stack;
   while (target->value != current->value)
   {
      current = current->next;
      index++;
   }
   return (index);
}

t_stack  *calcul_cost(t_stack **a, t_stack **b, int index)
{
   t_stack *current_a;
   t_stack *current_b;
   int   tmp;

   current_a = *a;
   current_b = *b;
   while (current_a)
   {
      
   }
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

// void  sort_stack(t_stack **a, t_stack **b)
// {
//    if (ft_lstsize(*a) > 3)
//    {
//       push_a(b, a);
//       push_a(b, a);
//    }
//    while (ft_lstsize(*a) != 3)
//    {
//       target_node(a, *b);
//       push_a(b, a);
//    }
//    small_sort(a);
// }
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
   int   min;

   min = INT_MAX;
   current = *stack;
   low_value = *stack;
   while (current)

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

//fonction qui trouve le intmax le intmin 
//et l'index du intmax et du intmin

//si le top de a est plus petit que le plus petit element de b
//en dessous du plus petit element de b

//si le top de a est plus grand que le plus grand element de b
// au dessus du plus grand element de b
// if (node > stack_a->intmax)
//    return (stack_a->indexmax)
// else if (node > stack_a>intmin)
//    return(stack_a->indexmin+1)


int   target_node(t_stack *node, t_stack **stack_a, t_stack **stack_b)
{
   int   index;

   index = 0;
   if (ft_lstlast(stack_b)->value > node > (*stack_b)->value)
   {
      index++;
      return (index);
   }
   while (stack_b)
   {
      if ((*stack_b)->value > node > (*stack_b)->next->value)
         return (index);
      stack_b = (*stack_b)->next;
      index++;
   }
   return (index);
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
   if (ft_lstsize(stack_a) > 3)
   {
      push_a(&stack_a, &stack_b);
      push_a(&stack_a, &stack_b);
   }
   while (ft_lstsize(stack_a) != 3)
   {
      
      *stack_a = (*stack_a)->next;
      push_a(stack_a, stack_b);
   }
   small_sort(stack_a);
}
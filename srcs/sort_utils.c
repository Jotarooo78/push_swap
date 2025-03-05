/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:16:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 12:16:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack  *find_lowest(t_stack *stack)
{
   t_stack *current;
   t_stack *low_value = NULL;
   int   min;

   min = INT_MAX;
   current = stack;
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

t_stack	*find_highest(t_stack *stack)
{
	t_stack *current;
	t_stack *big_value = NULL;
	int max;

	max = INT_MIN;
	current = stack;
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

void	top_node_a_setup(t_stack **a, t_stack *top_node)
{
	while (*a != top_node)
	{
		if (top_node->median == 0)
			rotate_a(a);
		else if (top_node->median == 1)
			rev_rotate_a(a);
	}
}

void	top_node_b_setup(t_stack **b, t_stack *top_node)
{
	while (*b != top_node)
	{
		if (top_node->median == 0)
			rotate_b(b);
		else if (top_node->median == 1)
			rev_rotate_b(b);
	}
}

t_stack	*get_cheapest_node(t_stack **a)
{
	t_stack *current;

	current = *a;
	while (current->cheap != true)
	{
		current = current->next;
	}
	return (current);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/03/03 12:16:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 12:16:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_lowest(t_stack *stack)
{
	t_stack	*low_value;
	int		min;

	low_value = NULL;
	if (stack == NULL)
		return (NULL);
	min = INT_MAX;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			low_value = stack;
		}
		stack = stack->next;
	}
	return (low_value);
}

t_stack	*find_highest(t_stack *stack)
{
	t_stack	*big_value;
	int		max;

	big_value = NULL;
	if (stack == NULL)
		return (NULL);
	max = INT_MIN;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			big_value = stack;
		}
		stack = stack->next;
	}
	return (big_value);
}

void	top_node_setup(t_stack **stack, t_stack *top_node, char c)
{
	while (*stack != top_node)
	{
		if (c == 'a')
		{
			if (top_node->median == 0)
				rotate_a(stack);
			else
				rev_rotate_a(stack);
		}
		else if (c == 'b')
		{
			if (top_node->median == 0)
				rotate_b(stack);
			else
				rev_rotate_b(stack);
		}
	}
}

t_stack	*get_cheapest_node(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current->cheap != true)
	{
		current = current->next;
	}
	return (current);
}

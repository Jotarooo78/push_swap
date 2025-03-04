/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 11:51:23 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 11:51:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	define_cheapest(t_stack *a)
{
	int cheap_value;
	t_stack *cheap_node;

	cheap_value = INT_MAX;
	while (a)
	{
		if (a->cost < cheap_value)
		{
			cheap_value = a->cost;
			cheap_node = a;
		}
		a = a->next;
	}
	cheap_node->cheap = true;
}

void	define_cost(t_stack *a, t_stack *b)
{
	int size_a;
	int size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	while (a)
	{
		a->cost = 0;
		if (a->median == 0)
		{
			a->cost = a->index;
		}
		if (a->median == 1)
		{
			a->cost = size_a - a->index;
		}
		else
		{
			a->cost += (size_b - a->target_node->index);
		}
		a = a->next;
	}
}

void	define_target(t_stack *a, t_stack *b)
{
	t_stack *current_b;
	t_stack *target;
	int closest_min;

	while (a)
	{
		target = NULL;
		closest_min = INT_MIN;
		current_b = b;
		while (current_b)
		{
			if (a->value > current_b->value && current_b->value > closest_min)
			{
				closest_min = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (closest_min == INT_MIN)
		{
			a->target_node = find_highest(b);
		}
		else
		{
			a->target_node = target;
		}
		a = a->next;
	}
}

void	get_index(t_stack *stack)
{
	int i;
	int median;

	i = 0;
	median = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
		{
			stack->median = 0;
		}
		else
		{
			stack->median = 1;
		}
		stack = stack->next;
		i++;
	}
}

void	init_stack_a(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	define_target(a, b);
	define_cost(a, b);
	define_cheapest(a);
}
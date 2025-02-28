/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/30 10:08:49 by marvin            #+#    #+#             */
/*   Updated: 2025/01/30 10:08:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


// void  find_lowest(t_stack *stack)
// {
//    t_stack *current;
//    t_stack *low_value;
//    int   min;

//    min = INT_MAX;
//    current = *stack;
//    low_value = *stack;
//    while (current)
//    {
//       if (current->value < min)
//       {
//          low_value = current;
//          min = low_value->value;
//       }
//       current = current->next;
//    }
// }

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

void	small_sort(t_stack **stack)
{
	t_stack *highest;

	highest = find_highest(*stack);
	if ((*stack)->value == highest->value)
	{
		rotate_a(stack);
	}
	else if ((*stack)->next->value == highest->value)
	{
		rotate_a(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		swap_a(stack);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/03/05 17:09:15 by marvin            #+#    #+#             */
/*   Updated: 2025/03/05 17:09:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


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

void	setup_min_top(t_stack **a)
{
	t_stack *min;
	t_stack *top_node;

	min = find_lowest(*a);
	top_node = *a;
	while (top_node != min)
	{
		if (min->median == 0)
		{
			rotate_a(a);
		}
		else if (min->median == 1)
		{
			rev_rotate_a(a);
		}
		top_node = *a;
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	t_stack *top_node;
	t_stack *target;

	top_node = *a;
	target = (*b)->target_node;
	while (top_node->value != target->value)
	{
		if (target->median == 0)
			rotate_a(a);
		else if (target->median == 1)
			rev_rotate_a(a);
		top_node = *a;
	}
	push_b(b, a);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest_node(a);
	if (cheapest_node->median == 0 && cheapest_node->target_node->median == 0)
		double_rotate(a, b, cheapest_node);
	else if (cheapest_node->median == 1
		&& cheapest_node->target_node->median == 1)
		double_rev_rotate(a, b, cheapest_node);
	top_node_a_setup(a, cheapest_node);
	// print_stack(a, b);
	// printf("cheapest_node->value = %d\n", cheapest_node->value);
	top_node_b_setup(b, cheapest_node->target_node);
	push_a(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3)
		push_a(a, b);
	if (ft_lstsize(*a) > 3)
		push_a(a, b);
	while (ft_lstsize(*a) > 3)
	{
		init_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	small_sort(a);
	while (*b)
	{
		init_stack_b(*a, *b);
		move_b_to_a(a, b);
	}
	get_index(*a);
	setup_min_top(a);
}

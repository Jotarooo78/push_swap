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

void	top_node_a_setup(t_stack **a, t_stack *top_node)
{
	while (*a != top_node)
	{
		if ((*a)->median == 0)
			rotate_a(a);
		else if ((*a)->median == 1)
			rev_rotate_a(a);
	}
}

void	top_node_b_setup(t_stack **b, t_stack *top_node)
{
	while (*b != top_node)
	{
		if ((*b)->median == 0)
			rotate_b(b);
		else if ((*b)->median == 1)
			rev_rotate_b(b);
	}
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack *cheapest_node;

	cheapest_node = get_cheapest_node(a);
	if (cheapest_node->median == 0 && cheapest_node->target_node->median == 0)
		double_rotate(a, b, cheapest_node);
	else if (cheapest_node->median == 1 && cheapest_node->target_node->median == 1)
		double_rev_rotate(a, b, cheapest_node);
	top_node_a_setup(a, cheapest_node);
	top_node_b_setup(b, cheapest_node->target_node);
	push_a(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3 && stack_sorted(a) == false)
		push_a(a, b);
	if (ft_lstsize(*a) > 3 && stack_sorted(a) == false)
		push_a(a, b);
	while (ft_lstsize(*a) > 3 && stack_sorted(a) == false)
	{ 
		init_stack_a(*a, *b);
		move_a_to_b(a, b);
	}
	small_sort(a);
	// while (*b)
	// {
	// 	init_stack_b(*a, *b);
	// 	move_b_to_a(a, b);
	// }
}

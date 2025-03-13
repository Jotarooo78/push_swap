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
	t_stack	*highest;

	highest = find_highest(*stack);
	if (*stack == highest)
	{
		rotate_a(stack);
	}
	else if ((*stack)->next == highest)
	{
		rev_rotate_a(stack);
	}
	if ((*stack)->value > (*stack)->next->value)
	{
		swap_a(stack);
	}
}

void	setup_min_top(t_stack **a)
{
	while ((*a)->value > find_lowest(*a)->value)
	{
		if (find_lowest(*a)->median == 0)
			rotate_a(a);
		else
			rev_rotate_a(a);
	}
}

void	move_b_to_a(t_stack **a, t_stack **b)
{
	top_node_setup(a, (*b)->target_node, 'a');
	push_a(b, a);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(a);
	if (cheapest_node->median == 0 && cheapest_node->target_node->median == 0)
		double_rotate(a, b, cheapest_node);
	else if (cheapest_node->median == 1
		&& cheapest_node->target_node->median == 1)
		double_rev_rotate(a, b, cheapest_node);
	top_node_setup(a, cheapest_node, 'a');
	top_node_setup(b, cheapest_node->target_node, 'b');
	push_b(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3)
		push_b(a, b);
	if (ft_lstsize(*a) > 3)
		push_b(a, b);
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

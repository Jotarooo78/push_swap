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

void	prep_to_push(t_stack **a, t_stack **b)
{
	t_stack *current;

	current = *a;
	while (current->cheap != true)
	{
		if (current->median == 0)
			rotate_a(a);
		else if (current->median == 1)
			rev_rotate_a(a);
		current = current->next;
	}
	push_a(a, b);
}

void	move_a_to_b(t_stack **a, t_stack **b)
{
	prep_to_push_a(a, b);
}

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3)
		push_a(a, b);
	if (ft_lstsize(*a) > 3)
		push_a(a, b);
	init_stack(*a, *b);
	move_a_to_b(a, b);
}

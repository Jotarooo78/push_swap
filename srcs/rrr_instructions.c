/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_instructions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/01/28 20:33:09 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 20:33:09 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	rev_rotate(t_stack **stack)
{
	t_stack *before_last_node;
	t_stack *last_node;

	last_node = *stack;
	before_last_node = *stack;
	while (before_last_node->next->next)
		before_last_node = before_last_node->next;
	while (last_node->next)
		last_node = last_node->next;
	last_node->next = *stack;
	*stack = last_node;
	before_last_node->next = NULL;
}
int	rev_rotate_a(t_stack **a)
{
	if (ft_lstsize(*a) < 2)
		return (0);
	else
	{
		rev_rotate(a);
		write(1, "rra\n", 4);
	}
	return (1);
}

int	rev_rotate_b(t_stack **b)
{
	if (ft_lstsize(*b) < 2)
		return (0);
	else
	{
		rev_rotate(b);
		write(1, "rrb\n", 4);
	}
	return (1);
}

int	rev_rotate_rr(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return (0);
	else
	{
		rev_rotate(a);
		rev_rotate(b);
		write(1, "rrr\n", 4);
	}
	return (1);
}

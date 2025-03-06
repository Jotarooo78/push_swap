/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/01/28 20:27:12 by marvin            #+#    #+#             */
/*   Updated: 2025/01/28 20:27:12 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	rotate(t_stack **stack)
{
	t_stack *head;
	t_stack *stock;

	head = *stack;
	stock = ft_lstlast(*stack);
	*stack = head->next;
	head->next = NULL;
	stock->next = head;
}
int	rotate_a(t_stack **a)
{
	if (ft_lstsize(*a) < 2)
		return (0);
	else
	{
		rotate(a);
		write(1, "ra\n", 3);
	}
	return (1);
}

int	rotate_b(t_stack **b)
{
	if (ft_lstsize(*b) < 2)
		return (0);
	else
	{
		rotate(b);
		write(1, "rb\n", 3);
	}
	return (1);
}

int	rotate_rr(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) < 2 || ft_lstsize(*b) < 2)
		return (0);
	else
	{
		rotate(a);
		rotate(b);
		write(1, "rr\n", 3);
	}
	return (1);
}
void	double_rotate(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while (*a != cheapest_node && *b != cheapest_node->target_node)
	{
		rotate_rr(a, b);
	}
	get_index(*a);
	get_index(*b);
}
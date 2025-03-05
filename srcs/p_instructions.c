/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:09:26 by marvin            #+#    #+#             */
/*   Updated: 2025/03/05 17:09:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack *tmp;

	tmp = (*stack_src)->next;        
	(*stack_src)->next = *stack_dest;
	*stack_dest = *stack_src;        
	*stack_src = tmp;
}

int	push_b(t_stack **b, t_stack **a)
{
	if (ft_lstsize(*b) < 1)
		return (0);
	else
	{
		push(b, a);
		write(1, "pb\n", 3);
	}
	return (1);
}

int	push_a(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) < 1)
		return (0);
	else
	{
		push(a, b);
		write(1, "pa\n", 3);
	}
	return (1);
}

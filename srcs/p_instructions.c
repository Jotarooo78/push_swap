/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_instructions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 17:09:26 by marvin            #+#    #+#             */
/*   Updated: 2025/03/13 15:31:30 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push(t_stack **stack_src, t_stack **stack_dest)
{
	t_stack	*tmp;

	if (!stack_src)
		return ;
	tmp = *stack_src;
	*stack_src = tmp->next;
	if (!stack_dest)
	{
		tmp->next = NULL;
		*stack_dest = tmp;
	}
	else
	{
		tmp->next = *stack_dest;
		*stack_dest = tmp;
	}
}

int	push_a(t_stack **b, t_stack **a)
{
	if (ft_lstsize(*b) < 1)
		return (0);
	else
	{
		push(b, a);
		write(1, "pa\n", 3);
	}
	return (1);
}

int	push_b(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) < 1)
		return (0);
	else
	{
		push(a, b);
		write(1, "pb\n", 3);
	}
	return (1);
}

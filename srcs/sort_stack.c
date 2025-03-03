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

void	sort_stack(t_stack **a, t_stack **b)
{
	if (ft_lstsize(*a) > 3)
		push_a(a, b);
	if (ft_lstsize(*a) > 3)
		push_a(a, b);
	init_stack(*a, *b);
}

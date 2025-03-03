/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:16:18 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 12:16:18 by marvin           ###   ########.fr       */
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
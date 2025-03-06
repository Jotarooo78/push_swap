/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_stack_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/03/05 15:19:45 by marvin            #+#    #+#             */
/*   Updated: 2025/03/05 15:19:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"


void	define_target_a(t_stack *a, t_stack *b)
{
	t_stack *current_a;
	t_stack *target;
	int closest_max;

	while (b)
	{
		target = NULL;
		closest_max = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (b->value < current_a->value && current_a->value < closest_max)
			{
				closest_max = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (closest_max == INT_MAX)
			b->target_node = find_lowest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	init_stack_b(t_stack *a, t_stack *b)
{
	get_index(a);
	get_index(b);
	define_target_a(a, b);
}
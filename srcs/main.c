/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/03/03 12:01:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void print_stack(t_stack **a, t_stack **b)
{
    ft_printf("a stack : \n");
    t_stack *tmp_a = *a;
    while (tmp_a)
    {
        ft_printf("value : %d\n", tmp_a->value);
        ft_printf("index : %d\n", tmp_a->index);
        ft_printf("cost : %d\n", tmp_a->cost);
        ft_printf("median : %d\n", tmp_a->median);
        ft_printf("cheap : %d\n", tmp_a->cheap);
        if (tmp_a->target_node)
            ft_printf("target_node : %d\n", tmp_a->target_node->value);
        else
            ft_printf("target_node : NULL\n");
        ft_printf("\n");
        tmp_a = tmp_a->next;
    }
    ft_printf("b stack : \n");
    t_stack *tmp_b = *b;
    while (tmp_b)
    {
        ft_printf("value : %d\n", tmp_b->value);
        ft_printf("index : %d\n", tmp_b->index);
        ft_printf("cost : %d\n", tmp_b->cost);
        ft_printf("median : %d\n", tmp_b->median);
        ft_printf("cheap : %d\n", tmp_b->cheap);
        if (tmp_b->target_node)
            ft_printf("target_node : %d\n", tmp_b->target_node->value);
        else
            ft_printf("target_node : NULL\n");
        ft_printf("\n");
        tmp_b = tmp_b->next;
    }
    ft_printf("NULL\n");
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	free_array(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

bool	stack_sorted(t_stack **a)
{
	t_stack	*current;
	int		tmp;

	current = *a;
	tmp = current->value;
	current = current->next;
	while (current)
	{
		if (tmp > current->value)
			return (false);
		tmp = current->value;
		current = current->next;
	}
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**tmp;

	tmp = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && av[1][0] == '\0'))
		return (0);
	else if (ac == 2)
		tmp = ft_split(av[1], ' ');
	if (fill_stack_a(&a, tmp) == false)
		free_stack(a);
	if (stack_sorted(&a) == false)
	{
		if (ft_lstsize(a) == 2)
			swap_a(&a);
		else if (ft_lstsize(a) == 3)
			small_sort(&a);
		else
			sort_stack(&a, &b);
	}
	print_stack(&a, &b);
	free_array(tmp);
	free_stack(a);
	free_stack(b);
}

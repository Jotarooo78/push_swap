/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/03/07 14:59:22 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack **a, t_stack **b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	ft_printf("\na stack : \n\n");
	tmp_a = *a;
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
	ft_printf("\nb stack : \n\n");
	tmp_b = *b;
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

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		ft_printf("Freeing node with value: %d\n", tmp->value);
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

void	all_sort_functions(t_stack **a, t_stack **b)
{
	if (stack_sorted(a) == false)
	{
		if (ft_lstsize(*a) == 2)
			swap_a(a);
		else if (ft_lstsize(*a) == 3)
			small_sort(a);
		else
			sort_stack(a, b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**tmp;
	int		i;

	i = 0;
	a = NULL;
	b = NULL;
	tmp = NULL;
	if (ac == 2)
	{
		tmp = ft_split(av[i], ' ');
		fill_stack_a(&a, tmp);
	}
	while (++i < ac - 1)
	{
		if (fill_stack_a(&a, tmp) == false)
			return (free_array(tmp), free_stack(a), free_stack(b), write(1,
					"Error\n", 6), 0);
	}
	all_sort_functions(&a, &b);
	// print_stack(&a, &b);
	return (free_stack(a), free_stack(b), free_array(tmp), 0);
}

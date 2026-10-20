/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 10:00:53 by armosnie          #+#    #+#             */
/*   Updated: 2025/03/19 11:37:38 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_variables(t_stack **a, t_stack **b, char ***tmp, int *i)
{
	*a = NULL;
	*b = NULL;
	*tmp = NULL;
	*i = 0;
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

bool	one_argument_handle(char **av, t_stack **a, t_stack **b, char **tmp)
{
	tmp = ft_split(av[1], ' ');
	if (fill_stack_a(a, tmp) == false)
	{
		free_array(tmp);
		return (free_stack(*a), free_stack(*b), write(1, "Error\n", 6), false);
	}
	free_array(tmp);
	return (true);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	**tmp;
	int		i;

	init_variables(&a, &b, &tmp, &i);
	if (ac < 2 || (ac == 2 && av[1][0] == '\0'))
		return (0);
	else if (ac == 2)
	{
		if (one_argument_handle(av, &a, &b, tmp) == false)
			return (0);
	}
	else
	{
		while (++i < ac)
		{
			tmp = ft_split(av[i], ' ');
			if (fill_stack_a(&a, tmp) == false)
				return (free_array(tmp), free_stack(a), free_stack(b), write(1,
						"Error\n", 6), 0);
			free_array(tmp);
		}
	}
	return (all_sort_functions(&a, &b), free_stack(a), free_stack(b), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:23:18 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/28 16:25:41 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	only_valid_characters(char c)
{
	while ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (true);
	return (false);
}

long	ft_atol(char *nbr)
{
	int		i;
	long	res;
	int		neg;

	i = 0;
	res = 0;
	neg = 1;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == 32)
		i++;
	if (nbr[i] == '-' || nbr[i] == '+')
	{
		if (nbr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nbr[i] >= '0' && nbr[i] <= '9')
	{
		res = (res * 10) + nbr[i] - '0';
		i++;
	}
	return (res * neg);
}

bool	duplicate_error(t_stack *a, int n)
{
	t_stack *tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->value == n)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

bool	correct_input(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (only_valid_characters(av[i]) == false)
			return (false);
		i++;
	}
	return (true);
}

bool	fill_stack_a(t_stack **a, char **tmp)
{
	int i;
	int n;

	i = 0;
	while (tmp[i])
	{
		if (correct_input(tmp[i]) == false)
			return (false);
		n = ft_atol(tmp[i]);
		if (n > INT_MAX || n < INT_MIN)
			return (false);
		if (duplicate_error(*a, n) == false)
			return (false);
		add_node(a, n);
		i++;
	}
	return (true);
}
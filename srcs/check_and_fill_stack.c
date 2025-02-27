/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_and_fill_stack.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:23:18 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/26 16:31:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	only_valid_characters(char c)
{
	while ((c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
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

int duplicate_error(t_stack *a, int n)
{
    while (a)
    {
        if (a->value == n)
            return (1);
        a = a->next;
    }
    return (0);
}

int correct_imput(char **av)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (av[i])
    {
        while (av[i][j])
        {
            if (only_valid_characters(av[i][j]) == 1)
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}

void fill_stack_a(t_stack **a, char **av)
{
    int i;
    int n;

    i = 0;
    while (av[i])
    {
        // if (correct_imput(*av[i]) == 1)
            // free_stack(a);
        n = ft_atol(av[i]);
        if (n > INT_MAX || n < INT_MIN)
            // free_error(a);
        if (duplicate_error(*a, n) == 1)
            // free_error(a);
        add_node(a, n);
        i++;
    }
}
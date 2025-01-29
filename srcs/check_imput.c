/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:54:29 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/27 14:57:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	correct_imput(int ac, char **av)
{
	int i;
	int j;
	int	tmp;
	
	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (only_decimal_and_sign(av[i][j]) == 0)
				return (0);
			j++;
		}
		tmp = ft_atol(av[i]);
		if (ft_has_dup(ac, tmp) == 1 || tmp == 2147483647 || tmp == -2147483647)
			return (0);
		i++;
	}
	return (1);
}
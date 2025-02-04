/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_imput.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:54:29 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/04 15:43:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	correct_imput(int ac, char **av)
{
	int i;
	int j;
	int tmp;
	
	i = 0;
	while (i < ac)
	{
		j = 1;
		while (av[i][j])
		{
			if (only_valid_characters(av[i][j]) == 0)
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
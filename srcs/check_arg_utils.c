/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:43:55 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/04 15:40:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	only_valid_characters(char c)
{
	while ((c >= 0 && c <= 9) || (c >= '0' && c <= '9') || c == '-' || c == '+')
		return (1);
	return (0);
}

int	is_alpha(char c)
{
	while (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

long	ft_has_dup(int ac, long nbr)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	while (i < ac)
	{
		j = i + 1;
		while ()
			return (1);
		i++;
	}
	return (0);
}

long	ft_atol(char *nbr)
{
	long	*nb;
	int		i;
	int		res;
	int		neg;

	nb = (char *)nbr;
	i = 0;
	res = 0;
	neg = 1;
	while ((nb[i] >= 9 && nb[i] <= 13) || nb[i] == 32)
		i++;
	if (nb[i] == '-' || nb[i] == '+')
	{
		if (nb[i] == '-')
			neg *= -1;
		i++;
	}
	while (nb[i] >= '0' && nb[i] <= '9')
	{
		res = (res * 10) + nb[i] - '0';
		i++;
	}
	return (res * neg);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:03:49 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/26 16:29:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	size_t	i;

	i = 0;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void add_node(t_stack **list, int nb) 
{
  t_stack *node;
  t_stack *current;

  node = malloc(sizeof(t_stack));
  if (node == NULL)
   	return ;
  node->value = nb;
  node->next = NULL;
  if (*list == NULL)
   	*list = node;
  else 
  {
   	current = *list;
   	while (current->next)
      	current = current->next;
   	current->next = node;
  }
}
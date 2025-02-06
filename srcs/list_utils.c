/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:03:49 by armosnie          #+#    #+#             */
/*   Updated: 2025/02/06 15:27:59 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// void	ft_lstdelone(t_stack *lst, void (*del)(int *))
// {
// 	if (lst == NULL || del == NULL)
// 		return ;
// 	(*del)(lst->value);
// 	free(lst);
// }

// void	ft_lstclear(t_stack **lst, void (*del)(int *))
// {
// 	t_stack	*tmp;

// 	tmp = NULL;
// 	if (*lst == NULL || lst == NULL || del == NULL)
// 		return ;
// 	while (lst && *lst)
// 	{
// 		tmp = (*lst)->next;
// 		ft_lstdelone(*lst, *del);
// 		(*lst) = tmp;
// 	}
// }

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



int add_node(t_stack **list, int nb) 
{
  t_stack *node;
  t_stack *current;

  node = malloc(sizeof(t_stack));
  if (node == NULL)
   	return (0);
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
  return (1);
}
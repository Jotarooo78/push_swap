/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 11:03:49 by armosnie          #+#    #+#             */
/*   Updated: 2025/01/29 22:48:21 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// t_stack	*ft_lstnew(int value)
// {
// 	t_stack	*new;

// 	new = malloc(sizeof(t_stack));
// 	if (new == NULL)
// 		return (NULL);
// 	new->value = value;
// 	new->next = NULL;
// 	return (new);
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

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

// void	ft_lstadd_back(t_stack **lst, t_stack *new_node)
// {
// 	t_stack	*last_lst;

// 	if (lst == NULL || new_node == NULL)
// 		return ;
// 	if (*lst)
// 	{
// 		last_lst = ft_lstlast(*lst);
// 		last_lst->next = new_node;
// 	}
// 	else
// 		*lst = new_node;
// }

// void	ft_lstadd_front(t_stack **lst, t_stack *new_node)
// {
// 	if (*lst)
// 	{
// 		new_node->next = *lst
// 		*lst = new_node;
// 	}
// }

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
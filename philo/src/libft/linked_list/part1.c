/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:49:47 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/01 02:41:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*allocated_memory;

	allocated_memory = malloc(sizeof(t_list));
	if (allocated_memory == NULL)
		return (NULL);
	allocated_memory->content = content;
	allocated_memory->next = NULL;
	return (allocated_memory);
}

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (*lst != NULL)
		new->next = *lst;
	*lst = new;
}

int	ft_lstsize(t_list *lst)
{
	if (lst == NULL)
		return (0);
	if (lst->next != NULL)
		return (1 + ft_lstsize(lst->next));
	return (1);
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	if (lst->next != NULL)
		return (ft_lstlast(lst->next));
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ft_lstlast(*lst)->next = new;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:49:49 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/05 22:53:47 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*

*/
//! Segmentation Fault
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}

static void	free_list_recursive(t_list *lst, void (*del)(void *))
{
	if (lst == NULL)
		return ;
	if (lst->next != NULL)
		free_list_recursive(lst->next, del);
	ft_lstdelone(lst, del);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	free_list_recursive(*lst, del);
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst == NULL)
		return ;
	if (lst->next != NULL)
		ft_lstiter(lst->next, f);
	if (lst != NULL)
		f(lst->content);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_element;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	else
	{
		content = f(lst->content);
		new_list_element = ft_lstnew(content);
		if (new_list_element == NULL)
		{
			del(content);
			return (NULL);
		}
		if (lst->next != NULL)
		{
			new_list_element->next = ft_lstmap(lst->next, f, del);
			if (new_list_element->next == NULL)
			{
				ft_lstdelone(new_list_element, del);
				return (NULL);
			}
		}
		return (new_list_element);
	}
}

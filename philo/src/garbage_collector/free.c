/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:19:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/06 18:32:04 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	gc_free(t_philo *philo, void *pointer)
{
	t_list	*current;
	t_list	*previous;

	current = philo->allocs;
	previous = NULL;
	while (current->content)
	{
		if (current->content == pointer)
		{
			if (previous)
				previous->next = current->next;
			else
				philo->allocs = current->next;
			ft_lstdelone(current, free);
			break ;
		}
		if (!current->next)
			break ;
		previous = current;
		current = current->next;
	}
}

void	gc_free_all(t_philo *philo)
{
	ft_lstclear(&philo->allocs, free);
}

void	gc_exit(t_philo *philo, int exit_status)
{
	gc_free_all(philo);
	exit(exit_status);
}

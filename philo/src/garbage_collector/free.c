/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:19:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 16:45:45 by rreimann         ###   ########.fr       */
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

void	destroy_mutexes(t_philo *philo)
{
	size_t	index;
	int		err;

	index = 0;
	while (index < philo->number_of_philosophers)
	{
		err = pthread_mutex_destroy(&philo->fork_mutexes[index]);
		if (err != 0)
			gc_exit(philo, EXIT_FAILURE);
		index++;
	}
	err = pthread_mutex_destroy(&philo->print_mutex);
	if (err != 0)
		gc_exit(philo, EXIT_FAILURE);
}

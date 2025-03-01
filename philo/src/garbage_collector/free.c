/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 03:19:26 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/01 04:16:06 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	gc_free(t_philo *philo, void *pointer)
{
	t_list	*current;

	current = philo->allocs;
	while (current->content)
	{
		if (current->content == pointer)
		{
			ft_lstdelone(current, free);
		}
		if (!current->next)
			return ;
		current = current->next;
	}
}

void	gc_exit(t_philo *philo, int exit_status)
{
	ft_lstclear(&philo->allocs, free);
	gc_free_all(philo);
	exit(exit_status);
}

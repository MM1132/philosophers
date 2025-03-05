/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/01 02:35:32 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/02 19:00:25 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	exit_msg(t_philo *philo, char *msg, int exit_status)
{
	printf("%s", msg);
	gc_exit(philo, exit_status);
}

void	*gc_malloc(t_philo *philo, size_t size)
{
	void	*allocated_memory;
	t_list	*new_element;

	allocated_memory = malloc(size);
	if (!allocated_memory)
		exit_msg(philo, "Malloc failed\n", EXIT_FAILURE);
	new_element = ft_lstnew(allocated_memory);
	if (!new_element)
	{
		free(allocated_memory);
		exit_msg(philo, "Malloc failed\n", EXIT_FAILURE);
	}
	if (philo->allocs == NULL)
		philo->allocs = new_element;
	else
		ft_lstadd_front(&(philo->allocs), new_element);
	return (allocated_memory);
}

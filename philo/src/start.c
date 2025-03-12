/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 13:24:32 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 16:43:23 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static pthread_t	start_death_thread(t_philo *philo)
{
	pthread_t			death_thread;

	pthread_create(&death_thread, NULL, death_checking_loop, (void *) philo);
	return (death_thread);
}

static void	start_philo_threads(t_philo *philo)
{
	size_t				index;
	t_philo_loop_props	*philo_loop_props;

	index = 0;
	while (index < philo->number_of_philosophers)
	{
		philo_loop_props = gc_malloc(philo, sizeof(t_philo_loop_props));
		philo_loop_props->philo = philo;
		philo_loop_props->philosopher = &philo->philos[index];
		pthread_create(&philo->philos[index].thread, NULL, \
			philosopher_loop, (void *)philo_loop_props);
		index++;
	}
}

void	start(t_philo *philo)
{
	size_t		index;
	pthread_t	death_thread;

	death_thread = start_death_thread(philo);
	start_philo_threads(philo);
	pthread_join(death_thread, NULL);
	index = 0;
	while (index < philo->number_of_philosophers)
	{
		pthread_join(philo->philos[index].thread, NULL);
		printf("Joined philosopher %zu\n", index);
		index++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:40:16 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 15:40:57 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_t	start_time_thread(t_philo *philo)
{
	pthread_t			time_thread;

	pthread_create(&time_thread, NULL, time_counter, (void *) philo);
	return (time_thread);
}

void	start_philo_threads(t_philo *philo)
{
	size_t				index;
	t_philo_loop_props	*main_loop_props;
	size_t				other_index;
	t_philosopher		philospher;

	index = 0;
	while (index < philo->number_of_philosophers)
	{
		main_loop_props = gc_malloc(philo, sizeof(t_philo_loop_props));
		main_loop_props->philo = philo;
		other_index = index + 1;
		if (other_index > philo->number_of_philosophers - 1)
			other_index = 0;
		philospher.left_fork = &philo->fork_mutexes[index];
		philospher.right_fork = &philo->fork_mutexes[other_index];
		if (index % 2 == 0)
		{
			philospher.left_fork = &philo->fork_mutexes[other_index];
			philospher.right_fork = &philo->fork_mutexes[index];
		}
		philospher.number = index + 1;
		main_loop_props->philosopher = philospher;
		pthread_create(&philo->philosophers[index], NULL, \
			philosopher_loop, (void *)main_loop_props);
		index++;
	}
}

void	start(t_philo *philo)
{
	size_t		index;
	pthread_t	time_thread;

	time_thread = start_time_thread(philo);
	start_philo_threads(philo);
	pthread_join(time_thread, NULL);
	index = 0;
	while (index < philo->number_of_philosophers)
	{
		pthread_join(philo->philosophers[index], NULL);
		printf("Joined philosopher %zu\n", index);
		index++;
	}
}

int	main(int argc, char **argv)
{
	t_philo				philo;

	philo = init_philo(argc, argv);
	// print_philo_data(&philo);
	start(&philo);

	gc_free_all(&philo);
	return (0);
}

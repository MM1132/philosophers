/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:40:16 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 02:30:28 by rreimann         ###   ########.fr       */
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

	// printf("Original: %zu\n", philo->start_time_ms);
	gc_malloc(philo, sizeof(int));
	// printf("After gc_malloc: %zu\n", philo->start_time_ms);
	index = 0;
	while (index < philo->number_of_philosophers)
	{
		main_loop_props = gc_malloc(philo, sizeof(t_philo_loop_props));
		main_loop_props->philosopher = index;
		main_loop_props->philo = philo;
		// printf("Another start ms: %zu\n", main_loop_props->philo->start_time_ms);
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
	print_philo_data(&philo);
	start(&philo);

	gc_free_all(&philo);
	return (0);
}

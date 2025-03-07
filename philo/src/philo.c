/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:18:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 02:11:38 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// It needs the number of the philosopher
// But it also needs the data of the entire t_philo struct
void	*philosopher_loop(void *p)
{
	t_philo_loop_props	*props;
	size_t				index;
	// t_philo_state		state;
	// size_t				left;
	// size_t				right;

	props = (t_philo_loop_props *)p;

	// Wait until the official start time
	// so that all the philosophers start at the same exact time
	while (get_time_in_ms() < props->philo->start_time_ms)
		usleep(100);

	// printf("HERE: start_time_ms: %zu\n", props->philo->start_time_ms);
	index = props->philosopher + 1;
	// left = props->philosopher - 1;
	// if (props->philosopher == 1)
	// 	left = props->philo->number_of_philosophers;
	// right = props->philosopher + 1;
	// if (props->philosopher == props->philo->number_of_philosophers)
	// 	right = 1;
	// pthread_mutex_lock(&(props->philo->fork_mutexes[props->philosopher]));

	// state = PHILO_EATING;
	// Sleep as many seconds as is the number of the philosopher
	printf("%zu: Philospher %zu sleeping for %zu milliseconds\n", get_time_from_start(props->philo), index, 1000 * index);
	ft_usleep(1000 * index);

	printf("%zu: Philosopher %zu finished\n", get_time_from_start(props->philo), index);
	return (NULL);
}

// 94787192360240
// 1741298389889

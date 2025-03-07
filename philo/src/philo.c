/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:18:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 02:34:52 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*
	timestamp_in_ms X has taken a fork
	timestamp_in_ms X is eating
	timestamp_in_ms X is sleeping
	timestamp_in_ms X is thinking
	timestamp_in_ms X died
*/
static void	print_philo_state(size_t philo_index, t_philo_state state)
{
	
}

// It needs the number of the philosopher
// But it also needs the data of the entire t_philo struct
void	*philosopher_loop(void *p)
{
	t_philo_loop_props	*props;
	size_t				index;
	t_philo_state		state;

	props = (t_philo_loop_props *)p;

	// Wait until the official start time
	// so that all the philosophers start at the same exact time
	while (get_time_in_ms() < props->philo->start_time_ms)
		usleep(100);
	index = props->philosopher + 1;
	state = PHILO_EATING;
	
	// printf("%zu: Philospher %zu sleeping for %zu milliseconds\n", get_time_from_start(props->philo), index, 1000 * index);
	// ft_usleep(1000 * index);

	// printf("%zu: Philosopher %zu finished\n", get_time_from_start(props->philo), index);
	return (NULL);
}


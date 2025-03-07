/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:18:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 15:45:57 by rreimann         ###   ########.fr       */
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
// static void	print_philo_state(size_t philo_index, t_philo_state state)
// {
	
// }

// It needs the number of the philosopher
// But it also needs the data of the entire t_philo struct
void	*philosopher_loop(void *p)
{
	t_philo_loop_props	*props;

	// Conversion of the void poiter to the structure
	props = (t_philo_loop_props *)p;

	// Wait until the official start time
	sleep_until_time(props->philo->start_time_ms);
	// printf(": started philosopher %zu\n", props->philosopher.number);

	props->philosopher.last_meal_time = get_time_in_ms();
	printf("%zu %zu is thinking\n", \
		get_time_from_start(props->philo), props->philosopher.number);

	while (true)
	{
		// First, the philosopher tries to pick up the two forks
		pthread_mutex_lock(props->philosopher.left_fork);
		printf("%zu %zu has taken a fork\n", \
			get_time_from_start(props->philo), props->philosopher.number);
		pthread_mutex_lock(props->philosopher.right_fork);
		printf("%zu %zu has taken a fork\n", \
			get_time_from_start(props->philo), props->philosopher.number);
		
		//? Then, the philosopher will be eating
		printf("%zu %zu is eating\n", \
		get_time_from_start(props->philo), props->philosopher.number);
		ft_usleep(props->philo->time_to_eat);
		
		pthread_mutex_unlock(props->philosopher.left_fork);
		pthread_mutex_unlock(props->philosopher.right_fork);
		
		//? Then, the philosopher will be sleeping
		printf("%zu %zu is sleeping\n", \
			get_time_from_start(props->philo), props->philosopher.number);
		ft_usleep(props->philo->time_to_sleep);
		
		//? And then finally, the philosopher will be thinking
		printf("%zu %zu is thinking\n", \
			get_time_from_start(props->philo), props->philosopher.number);
		}
		
	printf("%zu %zu died\n", \
		get_time_from_start(props->philo), props->philosopher.number);
	return (NULL);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:18:05 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/11 19:22:58 by rreimann         ###   ########.fr       */
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

static void	eating(t_philo_loop_props	*props)
{
	// First, the philosopher tries to pick up the two forks
	pthread_mutex_lock(props->philosopher.right_fork);
	mutex_print(props->philo, &props->philosopher, PHILO_PICKED_FORK);
	
	pthread_mutex_lock(props->philosopher.left_fork);
	mutex_print(props->philo, &props->philosopher, PHILO_PICKED_FORK);

	//? Then, the philosopher will be eating
	mutex_print(props->philo, &props->philosopher, PHILO_EATING);
	props->philosopher.last_meal_time = get_time_in_ms();
	ft_usleep(props->philo->time_to_eat);
	
	pthread_mutex_unlock(props->philosopher.right_fork);
	pthread_mutex_unlock(props->philosopher.left_fork);
}

static void	sleeping(t_philo_loop_props	*props)
{
	mutex_print(props->philo, &props->philosopher, PHILO_SLEEPING);
	ft_usleep(props->philo->time_to_sleep);
}

static void	think(t_philo_loop_props	*props)
{
	mutex_print(props->philo, &props->philosopher, PHILO_THINKING);
	if (props->philosopher.number % 2)
		ft_usleep(props->philo->time_to_eat / 10);
}

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

	while (true)
	{
		eating(props);
		sleeping(props);
		think(props);
	}
		
	mutex_print(props->philo, &props->philosopher, PHILO_DIED);
	return (NULL);
}


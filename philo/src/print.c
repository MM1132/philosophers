/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:18:31 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 17:24:12 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_data(t_philo *philo)
{
	printf("PHILO DATA:\n");
	printf("number_of_philosophers: %zu\n", philo->number_of_philosophers);
	printf("time_to_die: %zu\n", philo->time_to_die);
	printf("time_to_eat: %zu\n", philo->time_to_eat);
	printf("time_to_sleep: %zu\n", philo->time_to_sleep);
	printf("the long one: %zu\n",
		philo->number_of_times_each_philosopher_must_eat);
	printf("start_time_ms: %zu\n", philo->start_time_ms);
}

void	mutex_print(t_philo *philo, t_philosopher *philosopher, \
		t_philo_state philo_state)
{
	size_t	elapsed_time;

	pthread_mutex_lock(&philo->print_mutex);
	if (philo->stop_threads == false)
	{
		elapsed_time = get_time_from_start(philo);
		if (philo_state == PHILO_PICKED_FORK)
			printf("%zu %zu has taken a fork\n", elapsed_time, \
				philosopher->number);
		else if (philo_state == PHILO_EATING)
			printf("%zu %zu is eating\n", elapsed_time, philosopher->number);
		else if (philo_state == PHILO_SLEEPING)
			printf("%zu %zu is sleeping\n", elapsed_time, philosopher->number);
		else if (philo_state == PHILO_THINKING)
			printf("%zu %zu is thinking\n", elapsed_time, philosopher->number);
		else if (philo_state == PHILO_DIED)
		{
			printf("%zu %zu died\n", elapsed_time, philosopher->number);
			philo->stop_threads = true;
		}
	}
	pthread_mutex_unlock(&philo->print_mutex);
}

// Exists the program as a FAILURE with a message
void	err_exit(char *err_msg)
{
	printf("%s", err_msg);
	exit(EXIT_FAILURE);
}

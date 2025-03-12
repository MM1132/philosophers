/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:25:14 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 16:34:45 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	has_each_philo_eaten_enough(t_philo *philo)
{
	size_t	index;
	size_t	counter;

	counter = 0;
	index = 0;
	while (index < philo->number_of_philosophers)
	{
		if (philo->philos[index].times_eaten >= \
			philo->number_of_times_each_philosopher_must_eat)
			counter++;
		index++;
	}
	return (counter == philo->number_of_philosophers);
}

void	*death_checking_loop(void *props)
{
	t_philo	*philo;
	int		err;
	size_t	index;

	philo = (t_philo *)props;
	index = 0;
	while (true)
	{
		err = usleep(100);
		if (err != 0)
			return (NULL);
		if (get_time_from_ms(philo->philos[index].last_meal_time) > philo->\
			time_to_die)
			return (mutex_print(philo, &philo->philos[index], PHILO_DIED), \
				NULL);
		if (++index >= philo->number_of_philosophers)
		{
			if (philo->number_of_times_each_philosopher_must_eat != -1 && \
				has_each_philo_eaten_enough(philo))
				return (philo->stop_threads = true, NULL);
			index = 0;
		}
	}
	return (NULL);
}

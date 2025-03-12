/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_checker.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/12 14:25:14 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 14:45:43 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (get_time_from_ms(philo->philos[index].last_meal_time) > \
			philo->time_to_die)
		{
			mutex_print(philo, &philo->philos[index], PHILO_DIED);
		}
		index++;
		if (index >= philo->number_of_philosophers)
			index = 0;
	}
	return (NULL);
}

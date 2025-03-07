/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:48:28 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 02:07:20 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time_from_start(t_philo *philo)
{
	return (get_time_in_ms() - philo->start_time_ms);
}

size_t	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

// Increment the time of philo by a millisecond after every ms
void	*time_counter(void *props)
{
	t_philo	*philo;
	int		err;

	philo = (t_philo *)props;
	while (true)
	{
		err = usleep(1000);
		if (err != 0)
			return (NULL);
		if (philo->elapsed_time_ms >= 10000)
			break ;
	}
	return (NULL);
}

void	ft_usleep(size_t sleep_time)
{
    size_t	start_time;
	
	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < sleep_time)
		usleep(100);
}

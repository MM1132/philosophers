/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 19:48:28 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 16:57:26 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	get_time_from_ms(size_t	time_ms)
{
	return (get_time_in_ms() - time_ms);
}

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

void	ft_usleep(size_t sleep_time)
{
	size_t	start_time;

	start_time = get_time_in_ms();
	while ((get_time_in_ms() - start_time) < sleep_time)
		usleep(100);
}

void	sleep_until_time(size_t	target_time)
{
	while (get_time_in_ms() < target_time)
		usleep(100);
}

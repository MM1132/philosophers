/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:18:31 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/06 23:02:31 by rreimann         ###   ########.fr       */
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

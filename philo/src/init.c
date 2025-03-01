/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:44:19 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/01 04:17:12 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Get all the arguments and init the global struct for `philo`
t_philo	init_philo(int argc, char **argv)
{
	t_philo	philo;

	// In this case, we are reading the first 4 arguments
	if (argc == 5 || argc == 6)
	{
		philo.number_of_philosophers = ft_atoi(argv[1]);
		philo.time_to_die = ft_atoi(argv[2]);
		philo.time_to_eat = ft_atoi(argv[3]);
		philo.time_to_sleep = ft_atoi(argv[4]);
	}
	// In this case, we are also reading the 5th argument
	if (argc == 6)
	{
		philo.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:44:19 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/07 02:09:30 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Exists the program as a FAILURE with a message
static void	err_exit(char *err_msg)
{
	printf("%s", err_msg);
	exit(EXIT_FAILURE);
}

// Checks if there is the correct number of arguments
// And if all of the arguments can be converted into numbers
static void	check_args(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		err_exit("ERROR: Only enter either 4 or 5 arguments\n");
	if (!(ft_isposdigit_str(argv[1]) && ft_isposdigit_str(argv[2])
			&& ft_isposdigit_str(argv[3]) && ft_isposdigit_str(argv[4])) || (argc == 6
			&& !ft_isposdigit_str(argv[5])))
		err_exit("ERROR: Arguments can only be positive numbers\n");
}

static void	philo_pthread_init(t_philo *philo)
{
	size_t	index;
	int		err;

	philo->philosophers = gc_malloc(philo, \
		sizeof(pthread_t) * philo->number_of_philosophers);
	philo->fork_mutexes = gc_malloc(philo, \
		sizeof(pthread_mutex_t) * philo->number_of_philosophers);
	index = 0;
	while (index < philo->number_of_philosophers)
	{
		err = pthread_mutex_init(&philo->fork_mutexes[index], NULL);
		if (err != 0)
			gc_exit(philo, EXIT_FAILURE);
		index++;
	}
}

// Get all the arguments and init the global struct for `philo`
//? I think here we rather have to allocate memory for it
//? And then probably return a pointer or a NULL
t_philo	init_philo(int argc, char **argv)
{
	t_philo	philo;

	check_args(argc, argv);
	if (argc == 5 || argc == 6)
	{
		philo.number_of_philosophers = ft_atoi(argv[1]);
		philo.time_to_die = ft_atoi(argv[2]);
		philo.time_to_eat = ft_atoi(argv[3]);
		philo.time_to_sleep = ft_atoi(argv[4]);
	}
	philo.number_of_times_each_philosopher_must_eat = 0;
	if (argc == 6)
		philo.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	philo.allocs = NULL;
	philo_pthread_init(&philo);
	philo.elapsed_time_ms = 0;
	printf("Initializing start_time_ms: %zu\n", get_time_in_ms());
	// We are adding the +5 ms to the start time so that all
	// the philospher threads have equal time to start
	philo.start_time_ms = get_time_in_ms() + 5;
	return (philo);
}

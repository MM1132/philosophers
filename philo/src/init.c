/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 22:44:19 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/12 16:57:45 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	swap_int(int *n1, int *n2)
{
	int	save;

	save = *n1;
	*n1 = *n2;
	*n2 = save;
}

static void	init_philosophers(t_philo *philo)
{
	size_t	index;
	int		left_index;
	int		right_index;

	index = 0;
	while (index < philo->number_of_philosophers)
	{
		philo->philos[index].number = index + 1;
		philo->philos[index].index = index;
		philo->philos[index].last_meal_time = get_time_in_ms();
		philo->philos[index].times_eaten = 0;
		left_index = index - 1;
		if (left_index < 0)
			left_index = philo->number_of_philosophers - 1;
		right_index = index;
		if (index % 2)
			swap_int(&left_index, &right_index);
		philo->philos[index].left_fork = &philo->fork_mutexes[left_index];
		philo->philos[index].right_fork = &philo->fork_mutexes[right_index];
		index++;
	}
}

static void	philo_pthread_init(t_philo *philo)
{
	size_t	index;
	int		err;

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
	err = pthread_mutex_init(&philo->print_mutex, NULL);
	if (err != 0)
		gc_exit(philo, EXIT_FAILURE);
	philo->philos = gc_malloc(philo, \
		sizeof(t_philosopher) * philo->number_of_philosophers);
	init_philosophers(philo);
}

// Checks if there is the correct number of arguments
// And if all of the arguments can be converted into numbers
static void	check_args(int argc, char **argv)
{
	if (!(argc == 5 || argc == 6))
		err_exit("ERROR: Only enter either 4 or 5 arguments\n");
	if (!(ft_isposdigit_str(argv[1]) && ft_isposdigit_str(argv[2])
			&& ft_isposdigit_str(argv[3]) && ft_isposdigit_str(argv[4])) || \
			(argc == 6 && !ft_isposdigit_str(argv[5])))
		err_exit("ERROR: Arguments can only be positive numbers\n");
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
	philo.number_of_times_each_philosopher_must_eat = -1;
	if (argc == 6)
		philo.number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	philo.allocs = NULL;
	philo_pthread_init(&philo);
	philo.elapsed_time_ms = 0;
	philo.start_time_ms = get_time_in_ms() + 5;
	philo.stop_threads = false;
	return (philo);
}

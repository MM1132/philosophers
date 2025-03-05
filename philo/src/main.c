/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 21:40:16 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/05 22:53:01 by rreimann         ###   ########.fr       */
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
}

int	main(int argc, char **argv)
{
	t_philo	philo;
	int		*forks;

	philo = init_philo(argc, argv);
	print_philo_data(&philo);
	forks = gc_malloc(&philo, sizeof(int) * philo.number_of_philosophers);
	*forks = 5;
	printf("Forks: %d\n", *forks);

	printf("From list: \n");
	printf("%d\n", *((int *)philo.allocs->content));

	printf("Freeing forks now...\n");
	gc_free(&philo, forks);

	return (0);
}

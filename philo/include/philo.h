/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@student.42heilbronn.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:24:15 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/11 17:35:11 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdbool.h>
# include <unistd.h>

// {: LIFBT TYPES

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// }: LIBFT TYPES

typedef enum e_philo_state
{
	PHILO_PICKED_FORK,
	PHILO_EATING,
	PHILO_SLEEPING,
	PHILO_THINKING,
	PHILO_DIED,
}	t_philo_state;

typedef struct s_philo
{
	size_t			number_of_philosophers;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			number_of_times_each_philosopher_must_eat;
	size_t			start_time_ms;
	size_t			elapsed_time_ms;
	t_list			*allocs;
	pthread_mutex_t	*fork_mutexes;
	pthread_mutex_t	print_mutex;
	pthread_t		*philosophers;
}					t_philo;

typedef struct s_philosopher
{
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	size_t			number;
	size_t			last_meal_time;
}					t_philosopher;

typedef struct s_philo_loop_props
{
	t_philo			*philo;
	t_philosopher	philosopher;
}					t_philo_loop_props;

void	mutex_print(t_philo *philo, t_philosopher *philosopher, \
	t_philo_state philo_state);
void	sleep_until_time(size_t	target_time);
void	ft_usleep(size_t sleep_time);
size_t	get_time_from_start(t_philo *philo);
void	*time_counter(void *props);
void	*philosopher_loop(void *p);
void	print_philo_data(t_philo *philo);
size_t	get_time_in_ms(void);
t_philo	init_philo(int argc, char **argv);

// GARBAGE COLLECTOR

// Allocate memory and put it into the linked list of the garbage collector
// If malloc fails, free all already allocated memory and exit with an error
void	*gc_malloc(t_philo *philo, size_t size);
// Loop through all the allocations and find the matching one
// Free it and delete the node from the list of allocations
void	gc_free(t_philo *philo, void *pointer);
// Free everything that has ever been allocated by the garbage collector
void	gc_free_all(t_philo *philo);
// Free everything and exit out of the program
void	gc_exit(t_philo *philo, int exit_status);

// LIBFT FUNCTIONS
int		ft_isspace(char c);
int		ft_isdigit(int c);
int		ft_isposdigit_str(char *str);
long	ft_atoi(const char *str);
// Linked Lists
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 02:24:15 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/02 17:37:31 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <stdlib.h>

// {: LIFBT TYPES

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// }: LIBFT TYPES

typedef enum e_philo_state
{
	EATING,
	SLEEPING,
	THINKING,
}					t_philo_state;

typedef struct s_philosopher
{
	t_philo_state	state;
}					t_philosopher;

typedef struct s_philo
{
	size_t	number_of_philosophers;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_times_each_philosopher_must_eat;
	t_list	*allocs;
	short	*forks;
}			t_philo;

t_philo	init_philo(int argc, char **argv);

// GARBAGE COLLECTOR

// Allocate memory and put it into the linked list of the garbage collector
// If malloc fails, free all already allocated memory and exit with an error
void	*gc_malloc(t_philo *philo, size_t size);
// Loop through all the allocations and find the matching one
// Free it and delete the node from the list of allocations
void	gc_free(t_philo *philo, void *pointer);
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

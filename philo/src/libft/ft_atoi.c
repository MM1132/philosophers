/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 23:47:08 by rreimann          #+#    #+#             */
/*   Updated: 2025/02/28 23:47:29 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atoi(const char *str)
{
	long	output;
	long	multiplier;

	while (ft_isspace(*str))
		str++;
	multiplier = 1;
	if (*str == '-')
	{
		multiplier = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	output = 0;
	while (ft_isdigit(*str))
	{
		output *= 10;
		output += *str - 48;
		str++;
	}
	return (output * multiplier);
}

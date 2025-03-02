/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rreimann <rreimann@42heilbronn.de>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 12:31:35 by rreimann          #+#    #+#             */
/*   Updated: 2025/03/02 17:36:22 by rreimann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isposdigit_str(char *str)
{
	int	index;

	index = 0;
	while (str[index] != 0)
	{
		if (ft_isdigit((int)(str[index])) || \
			str[index] == '+')
		{
			index++;
			continue ;
		}
		return (0);
	}
	return (1);
}

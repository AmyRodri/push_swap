/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 11:54:50 by kamys             #+#    #+#             */
/*   Updated: 2025/09/11 12:00:29 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	sing;
	long	res;

	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	sing = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sing = -1;
		str++;
	}
	res = 0;
	while (ft_isdigit(*str))
		res = (res * 10) + (*str++ - '0');
	return (res * sing);
}

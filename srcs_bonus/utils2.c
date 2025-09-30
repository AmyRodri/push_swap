/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:08:23 by kamys             #+#    #+#             */
/*   Updated: 2025/09/29 23:30:44 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_abs(int x)
{
	if (x < 0)
		return (-x);
	return (x);
}

int	val(t_list *stack)
{
	return (*((int *)stack->content));
}

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

void	find_min(t_list *stack_a, int *best_pos)
{
	int		pos;
	int		best_val;
	t_list	*tmp;

	tmp = stack_a;
	best_val = 2147483647;
	pos = 0;
	while (tmp)
	{
		if (val(tmp) < best_val)
		{
			best_val = val(tmp);
			*best_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
}

int	check_list(t_list *stack_a)
{
	while (stack_a && stack_a->next)
	{
		if (val(stack_a) > val(stack_a->next))
			return (1);
		stack_a = stack_a->next;
	}
	return (0);
}

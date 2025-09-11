/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:19:04 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/11 12:52:00 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_number(const char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		i = 1;
	else
		i = 0;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i++]))
			return (0);
	}
	return (1);
}

int	repeat_numbers(int i, long val_i, char **nums)
{
	long	val_j;
	int		j;

	j = i + 1;
	while (nums[j])
	{
		val_j = ft_atol(nums[j]);
		if (val_j == val_i)
			return (1);
		j++;
	}
	return (0);
}

int	check_one_arg(char *arg)
{
	char	**nums;
	int		i;
	long	val_i;

	nums = ft_split(arg, ' ');
	i = 0;
	while (nums[i])
	{
		if (!valid_number(nums[i]))
			return (1);
		val_i = ft_atol(nums[i]);
		if ((val_i > 2147483647 || val_i < -2147483648))
			return (1);
		if (repeat_numbers(i, val_i, nums))
			return (1);
		i++;
	}
	return (0);
}

// int	check_multi_args(char **args)
// {
// 	int	i;

// }

int	check_args(int num, char **args)
{
	if (num < 2)
		return (0);
	if (num == 2)
		return (!check_one_arg(args[1]));
	// if (num > 2)
	// 	return (!check_multi_args(args));
	return (0);
}

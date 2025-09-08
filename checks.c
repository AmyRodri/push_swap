/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 12:19:04 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/08 12:23:28 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


// ver se é apenas digito 9 - 0. ver se tem número repedido
// e ir de INT_MIN até INT_MAX

int	check_one_arg(char *arg)
{
	int		i;
	int		j;

	i = 0;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]) && arg[i] != ' ')
			return (1);
		j = i + 1;
		while (arg[j])
		{
			if (arg[j] == arg[i])
				return (1);
			j++;
		}
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

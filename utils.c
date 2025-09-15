/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:45:23 by kamys             #+#    #+#             */
/*   Updated: 2025/09/15 18:12:50 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_splited(char **splited)
{
	int	i;

	i = 0;
	while (splited[i])
		free(splited[i++]);
	free(splited);
}

int	*free_array(int *array)
{
	free(array);
	return (NULL);
}

int	write_erro(char *str)
{
	while (*str)
		write(2, str++, 1);
	return (1);
}

void	cleanup_stacks(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_b, free);
	ft_lstclear(stack_a, free);
	write(1, "\n", 1);
}

int	init_stack_a(int ac, char **args, t_list **stack_a)
{
	int	*array;

	if (ac < 2)
		return (1);
	array = parse_args(ac, args);
	if (!array)
		return (1);
	*stack_a = start_list(ac, args, array);
	if (!*stack_a)
	{
		free(array);
		return (0);
	}
	free(array);
	return (1);
}

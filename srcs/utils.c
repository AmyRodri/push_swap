/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 16:45:23 by kamys             #+#    #+#             */
/*   Updated: 2025/09/23 18:13:40 by amyrodri         ###   ########.fr       */
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
}

int	init_stack_a(int ac, char **args, t_list **stack_a)
{
	int	*array;

	if (ac < 2)
		return (0);
	array = parse_args(ac, args);
	if (!array)
		return (0);
	*stack_a = start_list(ac, args, array);
	free(array);
	if (!*stack_a)
		return (0);
	return (1);
}

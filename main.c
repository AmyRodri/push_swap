/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:46:03 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/12 13:25:18 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **args)
{
	int		*array;
	t_list	*stack_a;

	if (ac < 2)
		return (write_erro("Error\n"));
	array = parse_args(ac, args);
	if (!array)
		return (write_erro("Error\n"));
	stack_a = start_list(ac, args, array);
	if (!stack_a)
	{
		free(array);
		return (write_erro("Error\n"));
	}
	print_lst(stack_a);
	ft_lstclear(&stack_a, free);
	free(array);
	write(1, "\n", 1);
	return (0);
}

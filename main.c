/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:46:03 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:55 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **args)
{
	int		*array;
	t_list	*stack_a;
	t_list	*stack_b;

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
	stack_b = NULL;
	print_lst(stack_a);
	ft_sa(&stack_a);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_rr(&stack_a, &stack_b);
	ft_rrr(&stack_a, &stack_b);
	print_lst(stack_a);
	print_lst(stack_b);
	ft_lstclear(&stack_a, free);
	free(array);
	write(1, "\n", 1);
	return (0);
}

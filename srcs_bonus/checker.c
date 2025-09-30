/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:46:03 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 01:43:36 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int ac, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;
	char	**moves;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(ac, args, &stack_a))
		return (write_erro("Error\n"));
	if (!cath_the_moves(&moves))
		return (write_erro("Error\n"));
	// make_moves(moves, stack_a, stack_b);
	// if (!check_list(stack_a) && !check_list_b(stack_b))
	// 	return (write_erro("KO"));
	cleanup_stacks(&stack_a, &stack_b);
	ft_putstr("\nOK\n");
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:46:03 by amyrodri          #+#    #+#             */
/*   Updated: 2025/10/02 16:21:10 by amyrodri         ###   ########.fr       */
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
	if (ac < 2)
		return (0);
	if (!init_stack_a(ac, args, &stack_a))
		return (write_erro("Error\n"));
	if (!check_list(stack_a))
		return (0);
	if (!cath_the_moves(&moves))
		return (write_erro("Error\n"));
	make_moves(moves, &stack_a, &stack_b);
	if (moves)
		free_splited(moves);
	if (!check_list(stack_a) && !stack_b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	cleanup_stacks(&stack_a, &stack_b);
	return (0);
}

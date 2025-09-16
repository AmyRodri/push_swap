/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:46:03 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/16 13:16:23 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **args)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (!init_stack_a(ac, args, &stack_a))
		return (write_erro("Error\n"));
	print_lst(stack_a);
	write(1, "\n", 1);
	sort_stack(&stack_a);
	write(1, "\n", 1);
	print_lst(stack_a);
	cleanup_stacks(&stack_a, &stack_b);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:28:39 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/16 13:56:34 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three(t_list **stack_a)
{
	int	first;
	int	segund;
	int	three;

	first = *((int *)(*stack_a)->content);
	segund = *((int *)(*stack_a)->next->content);
	three = *((int *)(*stack_a)->next->next->content);
	if ((first > segund) && (first > three))
		ft_ra(stack_a);
	else if ((segund > first) && (segund > three))
		ft_rra(stack_a);
	first = *((int *)(*stack_a)->content);
	segund = *((int *)(*stack_a)->next->content);
	if (first > segund)
		ft_sa(stack_a);
}

void	sort_stack(t_list **stack_a)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size <= 3)
		sort_three(stack_a);
	// else if (size <= 5)
	// 	sort_five(stack_a, stack_b);
	// else
	// 	big_sort(stack_a, stack_b);
}

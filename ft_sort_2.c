/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:30:42 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/16 16:35:41 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	while (ft_lstsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
	sort_three(stack_a);
}

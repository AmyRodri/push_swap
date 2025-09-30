/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 13:08:49 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 02:57:21 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!*stack_a)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	ft_lstadd_front(stack_b, head);
	ft_putstr("pb\n");
}

void	ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!*stack_b)
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	ft_lstadd_front(stack_a, head);
	ft_putstr("pa\n");
}

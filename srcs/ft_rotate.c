/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:33:17 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 02:57:40 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_ra(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	(void)stack_b;
	if (!*stack_a)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	head->next = NULL;
	ft_lstadd_back(stack_a, head);
	ft_putstr("ra\n");
}

void	ft_rb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	(void)stack_a;
	if (!*stack_b)
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	head->next = NULL;
	ft_lstadd_back(stack_b, head);
	ft_putstr("rb\n");
}

void	ft_rr(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

	if (!*stack_b)
		return ;
	head = *stack_b;
	*stack_b = (*stack_b)->next;
	head->next = NULL;
	ft_lstadd_back(stack_b, head);
	if (!*stack_a)
		return ;
	head = *stack_a;
	*stack_a = (*stack_a)->next;
	head->next = NULL;
	ft_lstadd_back(stack_a, head);
	ft_putstr("rr\n");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:53:45 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 15:35:23 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_rra(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*end;

	(void)stack_b;
	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	while (head->next->next)
		head = head->next;
	end = head->next;
	head->next = NULL;
	ft_lstadd_front(stack_a, end);
}

void	ft_rrb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*end;

	(void)stack_a;
	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = *stack_b;
	while (head->next->next)
		head = head->next;
	end = head->next;
	head->next = NULL;
	ft_lstadd_front(stack_b, end);
}

void	ft_rrr(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;
	t_list	*end;

	if (!*stack_b || !(*stack_b)->next)
		return ;
	head = *stack_b;
	while (head->next->next)
		head = head->next;
	end = head->next;
	head->next = NULL;
	ft_lstadd_front(stack_b, end);
	if (!*stack_a || !(*stack_a)->next)
		return ;
	head = *stack_a;
	while (head->next->next)
		head = head->next;
	end = head->next;
	head->next = NULL;
	ft_lstadd_front(stack_a, end);
}

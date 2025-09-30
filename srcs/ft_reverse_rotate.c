/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 14:53:45 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 02:57:29 by kamys            ###   ########.fr       */
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
	ft_putstr("rra\n");
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
	ft_putstr("rrb\n");
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
	ft_putstr("rrr\n");
}

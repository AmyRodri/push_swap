/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:28:08 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 02:57:51 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	ft_sa(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*segund;

	(void)stack_b;
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	segund = first->next;
	first->next = segund->next;
	segund->next = first;
	*stack_a = segund;
	ft_putstr("sa\n");
}

void	ft_sb(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*segund;

	(void)stack_a;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	segund = first->next;
	first->next = segund->next;
	segund->next = first;
	*stack_b = segund;
	ft_putstr("sb\n");
}

void	ft_ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*first;
	t_list	*segund;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	segund = first->next;
	first->next = segund->next;
	segund->next = first;
	*stack_a = segund;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	segund = first->next;
	first->next = segund->next;
	segund->next = first;
	*stack_b = segund;
	ft_putstr("ss\n");
}

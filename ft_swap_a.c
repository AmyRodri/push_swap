/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/15 12:28:08 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/15 12:55:47 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_sa(t_list *stack_a)
{
	t_list	*first;
	t_list	*segund;

	if (!stack_a || !stack_a->next)
		return (stack_a);
	first = stack_a;
	segund = stack_a->next;
	first->next = segund->next;
	segund->next = first;
	return (segund);
}

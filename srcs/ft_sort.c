/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:28:39 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 03:04:51 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_list **stack_a, t_list **stack_b)
{
	int	first;
	int	segund;
	int	three;

	first = val(*stack_a);
	segund = val((*stack_a)->next);
	three = val((*stack_a)->next->next);
	if ((first > segund) && (segund < three) && (first < three))
		ft_sa(stack_a, stack_b);
	else if ((first > segund) && (segund > three))
	{
		ft_sa(stack_a, stack_b);
		ft_rra(stack_a, stack_b);
	}
	else if ((first > segund) && (segund < three) && (first > three))
		ft_ra(stack_a, stack_b);
	else if ((first < segund) && (segund > three) && (first < three))
	{
		ft_sa(stack_a, stack_b);
		ft_ra(stack_a, stack_b);
	}
	else if ((first < segund) && (segund > three) && (first > three))
		ft_rra(stack_a, stack_b);
}

static void	sort_two(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2 && val(*stack_a) < val((*stack_a)->next))
		ft_sb(stack_a, stack_b);
}

static void	select_two_minus(t_list *stack, int *min1, int *min2)
{
	int	value;

	*min1 = 2147483647;
	*min2 = 2147483647;
	while (stack)
	{
		value = val(stack);
		if (value < *min1)
		{
			*min2 = *min1;
			*min1 = value;
		}
		else if (value < *min2)
			*min2 = value;
		stack = stack->next;
	}
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	int	top;
	int	min1;
	int	min2;

	select_two_minus(*stack_a, &min1, &min2);
	while (ft_lstsize(*stack_a) > 3)
	{
		top = val(*stack_a);
		if (top == min1 || top == min2)
			ft_pb(stack_a, stack_b);
		else
			ft_ra(stack_a, stack_b);
	}
	sort_two(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!check_list(*stack_a))
		return ;
	size = ft_lstsize(*stack_a);
	if (size == 2 && val(*stack_a) > val((*stack_a)->next))
		ft_sa(stack_a, stack_b);
	else if (size == 3)
		sort_three(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b);
}

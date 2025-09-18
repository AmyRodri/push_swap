/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:30:42 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/18 11:58:58 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_cheapest(t_cost *costs, int size_b)
{
	int		i;
	int		min_cost;
	int		min_index;

	if (size_b == 0)
		return (-1);
	min_cost = costs[0].total_cost;
	min_index = 0;
	i = 1;
	while (i < size_b)
	{
		if (costs[i].total_cost < min_cost)
		{
			min_cost = costs[i].total_cost;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

static void	min_to_top(t_list **stack_a)
{
	int		min;
	t_list	*tmp;

	min = 2147483647;
	tmp = *stack_a;
	while (tmp)
	{
		if (min > val(tmp))
			min = val(tmp);
		tmp = tmp->next;
	}
	while (val(*stack_a) != min)
	{
		if (min < (ft_lstsize(*stack_a) / 2))
			ft_ra(stack_a);
		else
			ft_rra(stack_a);
	}
}

static void	move_to_a(t_list **stack_a, t_list **stack_b, t_cost c)
{
	while (c.cost_a > 0 && c.cost_b > 0)
	{
		ft_rr(stack_a, stack_b);
		c.cost_a--;
		c.cost_b--;
	}
	while (c.cost_a < 0 && c.cost_b < 0)
	{
		ft_rrr(stack_a, stack_b);
		c.cost_a++;
		c.cost_b++;
	}
	while (c.cost_a > 0)
	{
		ft_ra(stack_a);
		c.cost_a--;
	}
	while (c.cost_a < 0)
	{
		ft_rra(stack_a);
		c.cost_a++;
	}
	while (c.cost_b > 0)
	{
		ft_rb(stack_b);
		c.cost_b--;
	}
	while (c.cost_b < 0)
	{
		ft_rrb(stack_b);
		c.cost_b++;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*cheapest;
	t_cost	*costs;
	t_cost	c;
	int		index;
	int		i;

	while (ft_lstsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		costs = calc_cost(stack_a, stack_b);
		index = get_cheapest(costs, ft_lstsize(*stack_b));
		cheapest = *stack_b;
		i = -1;
		while (++i < index)
			cheapest = cheapest->next;
		c = costs[index];
		move_to_a(stack_a, stack_b, c);
		ft_pa(stack_b, stack_a);
		free(costs);
	}
	min_to_top(stack_a);
}

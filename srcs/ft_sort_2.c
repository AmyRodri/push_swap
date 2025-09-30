/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 16:30:42 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 03:07:42 by kamys            ###   ########.fr       */
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

static void	min_to_top(t_list **stack_a, t_list **stack_b)
{
	int	min_pos;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	find_min(*stack_a, &min_pos);
	if (min_pos <= (size_a / 2))
		while (min_pos-- > 0)
			ft_ra(stack_a, stack_b);
	else
		while (min_pos++ < size_a)
			ft_rra(stack_a, stack_b);
}

static void	move_to_a_up(t_list **stack_a, t_list **stack_b, t_cost c)
{
	while (c.cost_a > 0 && c.cost_b > 0)
	{
		ft_rr(stack_a, stack_b);
		c.cost_a--;
		c.cost_b--;
	}
	while (c.cost_a > 0)
	{
		ft_ra(stack_a, stack_b);
		c.cost_a--;
	}
	while (c.cost_b > 0)
	{
		ft_rb(stack_a, stack_b);
		c.cost_b--;
	}
}

static void	move_to_a_down(t_list **stack_a, t_list **stack_b, t_cost c)
{
	while (c.cost_a < 0 && c.cost_b < 0)
	{
		ft_rrr(stack_a, stack_b);
		c.cost_a++;
		c.cost_b++;
	}
	while (c.cost_a < 0)
	{
		ft_rra(stack_a, stack_b);
		c.cost_a++;
	}
	while (c.cost_b < 0)
	{
		ft_rrb(stack_a ,stack_b);
		c.cost_b++;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_cost	*costs;
	t_cost	c;
	int		index;

	while (ft_lstsize(*stack_a) > 3)
		ft_pb(stack_a, stack_b);
	sort_three(stack_a, stack_b);
	while (*stack_b)
	{
		costs = calc_cost(stack_a, stack_b);
		if (!costs)
			return ;
		index = get_cheapest(costs, ft_lstsize(*stack_b));
		c = costs[index];
		move_to_a_up(stack_a, stack_b, c);
		move_to_a_down(stack_a, stack_b, c);
		ft_pa(stack_a, stack_b);
		free(costs);
	}
	min_to_top(stack_a, stack_b);
}

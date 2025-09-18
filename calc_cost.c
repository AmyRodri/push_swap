/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:20:13 by kamys             #+#    #+#             */
/*   Updated: 2025/09/18 11:27:44 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_pos(int value, t_list *stack_a)
{
	int		pos;
	int		best_pos;
	int		best_val;
	t_list	*tmp;

	tmp = stack_a;
	best_pos = 0;
	best_val = 2147483647;
	pos = 0;
	while (tmp)
	{
		if (val(tmp) > value && val(tmp) < best_val)
		{
			best_val = val(tmp);
			best_pos = pos;
		}
		tmp = tmp->next;
		pos++;
	}
	if (best_val == 2147483647)
	{
		pos = 0;
		best_val = 2147483647;
		tmp = stack_a;
		while (tmp)
		{
			if (val(tmp) < best_val)
			{
				best_val = val(tmp);
				best_pos = pos;
			}
			tmp = tmp->next;
			pos++;
		}
	}
	return (best_pos);
}

t_cost	*calc_cost(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		target_pos;
	int		size_a;
	int		size_b;
	t_list	*stack_tmp;
	t_cost	*costs;

	size_a = ft_lstsize(*stack_a);
	size_b = ft_lstsize(*stack_b);
	costs = malloc(sizeof(t_cost) * size_b);
	if (!costs)
		return (NULL);
	stack_tmp = *stack_b;
	i = 0;
	while (stack_tmp)
	{
		costs[i].value = val(stack_tmp);
		if (i <= (size_b / 2))
			costs[i].cost_b = i;
		else
			costs[i].cost_b = -(size_b - i);
		target_pos = get_target_pos(costs[i].value, *stack_a);
		if (target_pos < (size_a / 2))
			costs[i].cost_a = target_pos;
		else
			costs[i].cost_a = -(size_a - target_pos);
		if ((costs[i].cost_a >= 0 && costs[i].cost_b >= 0)
			|| (costs[i].cost_a < 0 && costs[i].cost_b < 0))
		{
			if (ft_abs(costs[i].cost_a) > ft_abs(costs[i].cost_b))
				costs[i].total_cost = ft_abs(costs[i].cost_a);
			else
				costs[i].total_cost = ft_abs(costs[i].cost_b);
		}
		else
			costs[i].total_cost = ft_abs(costs[i].cost_a)
				+ ft_abs(costs[i].cost_b);
		stack_tmp = stack_tmp->next;
		i++;
	}
	return (costs);
}

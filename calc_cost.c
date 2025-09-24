/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 15:20:13 by kamys             #+#    #+#             */
/*   Updated: 2025/09/24 14:46:14 by amyrodri         ###   ########.fr       */
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
		find_min(stack_a, &best_pos);
	return (best_pos);
}

static void	cost_b(t_cost *costs, int i, int size_b)
{
	if (i <= (size_b / 2))
		costs[i].cost_b = i;
	else
		costs[i].cost_b = -(size_b - i);
}

static void	cost_a(t_cost *costs, int i, t_list **stack_a, t_list **stack_tmp)
{
	int	target_pos;
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	costs[i].value = val(*stack_tmp);
	target_pos = get_target_pos(costs[i].value, *stack_a);
	if (target_pos <= (size_a / 2))
		costs[i].cost_a = target_pos;
	else
		costs[i].cost_a = -(size_a - target_pos);
}

static void	cost_total(t_cost *costs, int i)
{
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
}

t_cost	*calc_cost(t_list **stack_a, t_list **stack_b)
{
	int		i;
	int		size_b;
	t_list	*stack_tmp;
	t_cost	*costs;

	size_b = ft_lstsize(*stack_b);
	costs = malloc(sizeof(t_cost) * size_b);
	if (!costs)
		return (NULL);
	stack_tmp = *stack_b;
	i = 0;
	while (stack_tmp)
	{
		cost_b(costs, i, size_b);
		cost_a(costs, i, stack_a, &stack_tmp);
		cost_total(costs, i);
		stack_tmp = stack_tmp->next;
		i++;
	}
	return (costs);
}

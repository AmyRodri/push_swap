/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 14:45:35 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/24 14:47:04 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_min(t_list *stack_a, int *best_pos)
{
	int		pos;
	int		best_val;
	t_list	*tmp;

	tmp = stack_a;
	best_val = 2147483647;
	pos = 0;
	while (tmp)
	{
		if (val(tmp) < best_val)
		{
			best_val = val(tmp);
			*best_pos = pos;
		}
		pos++;
		tmp = tmp->next;
	}
}

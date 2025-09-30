/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 01:59:01 by kamys             #+#    #+#             */
/*   Updated: 2025/09/30 15:28:11 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include <string.h>

static void	init_table(t_move table[])
{
	table[0] = (t_move){"sa", ft_sa};
	table[1] = (t_move){"sb", ft_sb};
	table[2] = (t_move){"ss", ft_ss};
	table[3] = (t_move){"pa", ft_pa};
	table[4] = (t_move){"pb", ft_pb};
	table[5] = (t_move){"ra", ft_ra};
	table[6] = (t_move){"rb", ft_rb};
	table[7] = (t_move){"rr", ft_rr};
	table[8] = (t_move){"rra", ft_rra};
	table[9] = (t_move){"rrb", ft_rrb};
	table[10] = (t_move){"rrr", ft_rrr};
	table[11] = (t_move){NULL, NULL};
}

void	make_moves(char **moves, t_list **stack_a, t_list **stack_b)
{
	t_move	table[12];
	int		i;
	int		j;

	init_table(table);
	i = 0;
	while (moves[i])
	{
		j = 0;
		while (table[j].name)
		{
			if (strcmp(moves[i], table[j].name) == 0)
			{
				table[j].func(stack_a, stack_b);
				break ;
			}
			j++;
		}
		i++;
	}
}

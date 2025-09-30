/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 01:59:01 by kamys             #+#    #+#             */
/*   Updated: 2025/09/30 02:42:56 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	t_move	m_table[12];
	int		i;
	int		j;

	init_table(m_table);
	i = 0;
	while (moves[i])
	{
		j = 0;
		while (m_table[j].name)
		{
			if (ft_strncmp(moves[i], m_table[j].name, ft_strlen(moves[i])) == 0)
			{
				m_table[j].func(stack_a, stack_b);
				break ;
			}
			j++;
		}
		i++;
	}
}

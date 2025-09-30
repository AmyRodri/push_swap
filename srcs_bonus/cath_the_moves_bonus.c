/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cath_the_moves_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/29 23:45:10 by kamys             #+#    #+#             */
/*   Updated: 2025/09/30 15:35:54 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	is_valid_move(char *move)
{
	if (move[ft_strlen(move) - 1] == '\n')
		move[ft_strlen(move) - 1] = '\0';
	if (ft_strncmp(move, "sa", ft_strlen(move)) == 0
		|| ft_strncmp(move, "sb", ft_strlen(move)) == 0
		|| ft_strncmp(move, "ss", ft_strlen(move)) == 0
		|| ft_strncmp(move, "pa", ft_strlen(move)) == 0
		|| ft_strncmp(move, "pb", ft_strlen(move)) == 0
		|| ft_strncmp(move, "ra", ft_strlen(move)) == 0
		|| ft_strncmp(move, "rb", ft_strlen(move)) == 0
		|| ft_strncmp(move, "rr", ft_strlen(move)) == 0
		|| ft_strncmp(move, "rra", ft_strlen(move)) == 0
		|| ft_strncmp(move, "rrb", ft_strlen(move)) == 0
		|| ft_strncmp(move, "rrr", ft_strlen(move)) == 0)
		return (1);
	return (0);
}

static void	line_moves(char *line, char **tmp)
{
	char	*new_tmp;

	if (!tmp)
		new_tmp = ft_strdup(line);
	else
		new_tmp = ft_strjoin(*tmp, line);
	free(*tmp);
	free(line);
	*tmp = new_tmp;
	new_tmp = ft_strjoin(*tmp, " ");
	free(*tmp);
	*tmp = new_tmp;
}

int	cath_the_moves(char ***moves)
{
	char	*tmp;
	char	*line;

	tmp = NULL;
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (!line)
			break ;
		if (!is_valid_move(line))
		{
			free(line);
			free(tmp);
			return (0);
		}
		line_moves(line, &tmp);
	}
	if (!tmp)
		return (0);
	*moves = ft_split(tmp, ' ');
	free(tmp);
	return (1);
}

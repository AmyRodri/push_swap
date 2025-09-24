/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 14:06:24 by kamys             #+#    #+#             */
/*   Updated: 2025/09/12 13:28:13 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	has_duplicate(int val, int *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (array[i] == val)
			return (1);
		i++;
	}
	return (0);
}

static int	is_valid_numbers(char *str)
{
	long	val;
	int		i;

	if (!str || !*str)
		return (0);
	i = 0;
	if (*str == '-' || *str == '+')
		i = 1;
	if (!str[i])
		return (0);
	while (str[i])
		if (!ft_isdigit(str[i++]))
			return (0);
	val = ft_atol(str);
	if (val > 2147483647 || val < -2147483648)
		return (0);
	return (1);
}

int	count_args(int ac, char **args)
{
	char	**splited;
	int		count;
	int		i;
	int		j;

	i = 1;
	count = 0;
	while (i < ac)
	{
		splited = ft_split(args[i++], ' ');
		if (!splited)
			return (-1);
		j = 0;
		while (splited[j])
		{
			if (!is_valid_numbers(splited[j++]))
			{
				free_splited(splited);
				return (-1);
			}
			count++;
		}
		free_splited(splited);
	}
	return (count);
}

static int	*content_array(int *array, char **splited, int *k)
{
	long	val;
	int		j;

	j = 0;
	while (splited[j])
	{
		val = ft_atol(splited[j]);
		if (has_duplicate((int)val, array, *k))
		{
			free_splited(splited);
			return (free_array(array));
		}
		array[*k] = (int)val;
		(*k)++;
		j++;
	}
	free_splited(splited);
	return (array);
}

int	*parse_args(int ac, char **args)
{
	char	**splited;
	int		*array;
	int		count;
	int		i;
	int		k;

	count = count_args(ac, args);
	if (count == -1)
		return (NULL);
	array = malloc(sizeof(int) * count);
	if (!array)
		return (NULL);
	k = 0;
	i = 1;
	while (i < ac)
	{
		splited = ft_split(args[i], ' ');
		if (!splited)
			return (free_array(array));
		array = content_array(array, splited, &k);
		if (!array)
			return (NULL);
		i++;
	}
	return (array);
}

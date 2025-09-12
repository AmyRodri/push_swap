/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/11 18:21:13 by kamys             #+#    #+#             */
/*   Updated: 2025/09/12 15:29:07 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*new_node(int value)
{
	int		*val;
	t_list	*node;

	val = malloc(sizeof(int));
	if (!val)
		return (NULL);
	*val = value;
	node = ft_lstnew(val);
	if (!node)
		free (val);
	return (node);
}

static void	*free_lst_null(t_list *head, void *ret)
{
	ft_lstclear(&head, free);
	return (ret);
}

t_list	*start_list(int ac, char **args, int *array)
{
	int		i;
	int		size;
	t_list	*node;
	t_list	*head;
	t_list	*current;

	size = count_args(ac, args);
	if (size <= 0)
		return (NULL);
	head = new_node(array[0]);
	if (!head)
		return (NULL);
	current = head;
	i = 1;
	while (i < size)
	{
		node = new_node(array[i]);
		if (!node)
			return (free_lst_null(head, NULL));
		current->next = node;
		current = node;
		i++;
	}
	return (head);
}

void	print_lst(t_list *head)
{
	while (head)
	{
		ft_printf("%d -> ", *(int *)head->content);
		head = head->next;
	}
	ft_printf("NULL\n");
}

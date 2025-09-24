/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:47:24 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/24 14:46:55 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/srcs/includes/libft.h"
# include <unistd.h>

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	value;
}	t_cost;

// ft_atol.c
long	ft_atol(const char *str);

// parse.c
int		*parse_args(int ac, char **args);
int		count_args(int ac, char **args);

// utils.c
void	free_splited(char **splited);
void	cleanup_stacks(t_list **stack_a, t_list **stack_b);
int		init_stack_a(int ac, char **args, t_list **stack_a);
int		*free_array(int *array);
int		write_erro(char *str);

// utils2.c
int		ft_abs(int x);

// lst.c
t_list	*start_list(int ac, char **args, int *array);
void	print_lst(t_list *head);
int		val(t_list *stack);

// ft_swap.c
void	ft_sb(t_list **stack);
void	ft_sa(t_list **stack);
void	ft_ss(t_list **stack_a, t_list **stack_b);

// ft_push.c
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_b, t_list **stack_a);

// ft_rorate.c
void	ft_ra(t_list **stack_a);
void	ft_rb(t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);

// ft_reverse_rotate.c
void	ft_rra(t_list **stack_a);
void	ft_rrb(t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

// ft_sort.c
void	sort_stack(t_list **stack_a, t_list **stack_b);
void	sort_three(t_list **stack);

// ft_sort_2.c
void	big_sort(t_list **stack_a, t_list **stack_b);

// calc_cost.c
t_cost	*calc_cost(t_list **stack_a, t_list **stack_b);

// calc_utils.c
void	find_min(t_list *stack_a, int *best_pos);

// main.c
// main
#endif
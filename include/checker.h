/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:47:24 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/30 03:18:22 by kamys            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/srcs/includes/libft.h"
# include <unistd.h>

typedef struct s_cost
{
	int	cost_a;
	int	cost_b;
	int	total_cost;
	int	value;
}	t_cost;

typedef void	(*t_move_func)(t_list **, t_list **);

typedef struct s_move
{
	char		*name;
	t_move_func	func;
}	t_move;

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
long	ft_atol(const char *str);
void	find_min(t_list *stack_a, int *best_pos);
int		val(t_list *stack);
int		check_list(t_list *stack_a);

// lst.c
t_list	*start_list(int ac, char **args, int *array);

int		cath_the_moves(char ***moves);

void	make_moves(char **moves, t_list **stack_a, t_list **stack_b);

int	check_lists(t_list **stack_a, t_list **stack_b);

// ft_swap.c
void	ft_sb(t_list **stack_a, t_list **stack_b);
void	ft_sa(t_list **stack_a, t_list **stack_b);
void	ft_ss(t_list **stack_a, t_list **stack_b);

// ft_push.c
void	ft_pb(t_list **stack_a, t_list **stack_b);
void	ft_pa(t_list **stack_a, t_list **stack_b);

// ft_rorate.c
void	ft_ra(t_list **stack_a, t_list **stack_b);
void	ft_rb(t_list **stack_a, t_list **stack_b);
void	ft_rr(t_list **stack_a, t_list **stack_b);

// ft_reverse_rotate.c
void	ft_rra(t_list **stack_a, t_list **stack_b);
void	ft_rrb(t_list **stack_a, t_list **stack_b);
void	ft_rrr(t_list **stack_a, t_list **stack_b);

// main.c
// main
#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyrodri <amyrodri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:47:24 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/15 15:30:48 by amyrodri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/srcs/includes/libft.h"
# include <unistd.h>

// ft_atol.c
long	ft_atol(const char *str);

// parse.c
int		*parse_args(int ac, char **args);
int		count_args(int ac, char **args);

// utils.c
void	free_splited(char **splited);
int		*free_array(int *array);
int		write_erro(char *str);

// lst.c
t_list	*start_list(int ac, char **args, int *array);
void	print_lst(t_list *head);

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

// main.c
// main
#endif
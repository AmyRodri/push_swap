/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kamys <kamys@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 11:47:24 by amyrodri          #+#    #+#             */
/*   Updated: 2025/09/11 18:10:32 by kamys            ###   ########.fr       */
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

// utils.c
void	free_splited(char **splited);
int		*free_array(int *array);
int		write_erro(char *str);

// main.c
// main
#endif
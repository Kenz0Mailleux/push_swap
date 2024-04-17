/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:03 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/16 18:11:18 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_stack
{
	int	value;
	int	index;
	struct s_stack *previous;
	struct s_stack *next;
}			t_stack;

char	**parse_input(int argc, char **argv);
char	**parse_several_input(int argc, char **argv);
char	**parse_one_input(char *argv);
t_stack	*init_stack(char **nbr_list);



int	sa(t_stack *a);
int	sb(t_stack *b);
int	ss(t_stack *a, t_stack *b);

int	pa(t_stack *a, t_stack *b);

#endif
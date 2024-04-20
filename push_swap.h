/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:03 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/20 15:01:07 by kmailleu         ###   ########.fr       */
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
int		check_list(char **lst);
t_stack	*init_stack(char **nbr_list);

t_stack	*ft_get_last(t_stack *lst);
int		ft_stacksize(t_stack *lst);

int		sa(t_stack *a);
int		sb(t_stack *b);
int		ss(t_stack *a, t_stack *b);

int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **b, t_stack **a);

int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **a, t_stack **b);
#endif
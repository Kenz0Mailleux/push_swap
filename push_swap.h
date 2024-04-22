/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:03 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/21 12:16:46 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				has_index;
	struct s_stack	*previous;
	struct s_stack	*next;
}			t_stack;

char	**parse_input(int argc, char **argv);
char	**parse_several_input(int argc, char **argv);
char	**parse_one_input(char *argv);
int		check_list(char **lst);
t_stack	*init_stack(char **nbr_list);
void	free_lst(char **nbr_lst);

t_stack	*ft_get_last(t_stack *lst);
int		ft_stacksize(t_stack *lst);
int		ft_strcmp(char *s1, char *s2);
int		smallest_number(t_stack *stack_a);

int		sa(t_stack **a);
int		sb(t_stack **b);
int		ss(t_stack **a, t_stack **b);

int		pa(t_stack **a, t_stack **b);
int		pb(t_stack **b, t_stack **a);

int		ra(t_stack **stack);
int		rb(t_stack **stack);
int		rr(t_stack **a, t_stack **b);
int		rra(t_stack **stack);
int		rrb(t_stack **stack);
int		rrr(t_stack **a, t_stack **b);

void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_four_five(t_stack **stack_a, t_stack **stack_b);
int		get_rotate_direction(t_stack *first_node);
int		check_if_sorted(t_stack *stack_a);
void	sort_big_list(t_stack **stack_a, t_stack **stack_b);

#endif
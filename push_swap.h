/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:40:03 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/22 20:24:36 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define INT_MIN 0
# define INT_MAX 200
# define LONG_MAX 1000
# include <limits.h>
# include "libft/libft.h"

typedef struct s_push
{
	int	next;
	int	max;
	int	mid;
	int	flag;
}	t_push;

typedef struct s_swap
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		asize;
	int		bsize;
}		t_swap;

void	check_sort(t_swap	*tab);
int		check_sorted(t_list **stack1);
int		a_sorted(t_list **stack1, int count);
t_list	*find_min(t_list **stack);
t_list	*find_max(t_list **stack);
int		is_sort(t_swap	*tab);

t_list	*ft_init(char **agrv, int argc);
int		ft_check(t_list *list, int number, char *number_str);
void	free_all(int free_nb, char **nbr_lst);

void	pa(t_list **stack1, t_list **stack2);
void	pb(t_list **stack1, t_list **stack2);
void	ra(t_list **stack1);
void	rb(t_list **stack2);
void	rr(t_list **stack1, t_list **stack2);
void	sa(t_list **stack1);
void	sb(t_list **stack2);
void	ss(t_list **stack1, t_list **stack2);
void	rrb(t_list **stack2);
void	rra(t_list **stack1);

void	add_index(t_list *lst);
void	quick_sort(t_list **stack1, t_list **stack2, int count);
#endif
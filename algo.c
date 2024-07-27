/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:44:22 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/27 17:58:34 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction de tri initiale des éléments de stack_a vers stack_b
static void	init_sort(t_list **stack_a, t_list **stack_b, t_push *push, int count)
{
	int		idx;

	idx = 0;
	while (idx < count)
	{
		if ((*stack_a)->index <= push->mid)
			pb(stack_a, stack_b);
		else
		{
			if (ft_lstsize(*stack_b) > 1 && (*stack_b)->index < (push->mid / 2))
				rr(stack_a, stack_b);
			else
				ra(stack_a);
		}
		idx++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

// Trouve et déplace l'élément suivant à la bonne position
static void	find_next(t_list **stack_a, t_list **stack_b, t_push *push)
{
	while (1)
	{
		if (ft_lstsize((*stack_b)) > 0 && ((*stack_b)->index == push->next))
			pa(stack_a, stack_b);
		else if ((*stack_a)->index == push->next)
		{
			(*stack_a)->flag = -1;
			ra(stack_a);
			push->next++;
		}
		else if (ft_lstsize((*stack_b)) > 2 && ft_lstlast((*stack_b))->index == push->next)
			rrb(stack_b);
		else if ((*stack_a)->next->index == push->next)
			sa(stack_a);
		else if (ft_lstsize((*stack_a)) > 1 && ((*stack_a)->next->index == push->next)
			&& ((*stack_b)->next->index == push->next + 1))
			ss(stack_a, stack_b);
		else
			break ;
	}
}

// Trie les éléments de stack_b vers stack_a
static void	sort_a(t_list **stack_a, t_list **stack_b, t_push *push)
{
	int		size_b;
	int		count;

	count = 0;
	size_b = ft_lstsize(*stack_b);
	while (ft_lstsize(*stack_b) && count < size_b)
	{
		if ((*stack_b)->index == push->next)
			find_next(stack_a, stack_b, push);
		else if ((*stack_b)->index >= push->mid)
		{
			(*stack_b)->flag = push->flag;
			pa(stack_a, stack_b);
		}
		else if ((*stack_b)->index < push->mid)
			rb(stack_b);
		count++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

// Partitionne les éléments de stack_a vers stack_b et les trie en fonction des flags
static void	sort_b(t_list **stack_a, t_list **stack_b, t_push *push)
{
	int		curr_flag;

	curr_flag = (*stack_a)->flag;
	while ((*stack_a)->flag == curr_flag)
	{
		if ((*stack_a)->index != push->next)
			pb(stack_a, stack_b);
		find_next(stack_a, stack_b, push);
		(*stack_a) = *stack_a;
	}
	if (ft_lstsize(*stack_b))
		push->max = find_max(stack_b)->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

// Fonction principale de tri rapide des stacks
void	quick_sort(t_list **stack_a, t_list **stack_b, int count)
{
	t_push	push;

	push.next = find_min(stack_a)->index;
	push.max = find_max(stack_a)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	init_sort(stack_a, stack_b, &push, count);
	while (!a_sorted(stack_a, count))
	{
		if (ft_lstsize(*stack_b) == 0)
			sort_b(stack_a, stack_b, &push);
		else
			sort_a(stack_a, stack_b, &push);
	}
}

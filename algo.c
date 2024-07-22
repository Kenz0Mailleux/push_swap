/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 16:44:22 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/22 20:22:13 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Fonction de tri initiale des éléments de stack1 vers stack2
void	init_sort(t_list **stack1, t_list **stack2, t_push *push, int count)
{
	int		idx;
	t_list	*lst;

	idx = 0;
	while (idx < count)
	{
		lst = *stack1;
		if (lst->index <= push->mid)
			pb(stack1, stack2);
		else
		{
			if (ft_lstsize(*stack2) > 1 && (*stack2)->index < (push->mid / 2))
				rr(stack1, stack2);
			else
				ra(stack1);
		}
		idx++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

// Trouve et déplace l'élément suivant à la bonne position
void	find_next(t_list **stack1, t_list **stack2, t_push *push)
{
	t_list	*lst1;
	t_list	*lst2;

	while (1)
	{
		lst1 = *stack1;
		lst2 = *stack2;
		if (ft_lstsize(lst2) > 0 && (lst2->index == push->next))
			pa(stack1, stack2);
		else if (lst1->index == push->next)
		{
			lst1->flag = -1;
			ra(stack1);
			push->next++;
		}
		else if (ft_lstsize(lst2) > 2 && ft_lstlast(lst2)->index == push->next)
			rrb(stack2);
		else if (lst1->next->index == push->next)
			sa(stack1);
		else if (ft_lstsize(lst1) > 1 && (lst1->next->index == push->next)
			&& (lst2->next->index == push->next + 1))
			ss(stack1, stack2);
		else
			break ;
	}
}

// Trie les éléments de stack2 vers stack1
void	sort_a(t_list **stack1, t_list **stack2, t_push *push)
{
	int		size_b;
	int		count;
	t_list	*lst2;

	count = 0;
	size_b = ft_lstsize(*stack2);
	while (ft_lstsize(*stack2) && count < size_b)
	{
		lst2 = *stack2;
		if (lst2->index == push->next)
			find_next(stack1, stack2, push);
		else if (lst2->index >= push->mid)
		{
			lst2->flag = push->flag;
			pa(stack1, stack2);
		}
		else if (lst2->index < push->mid)
			rb(stack2);
		count++;
	}
	push->max = push->mid;
	push->mid = (push->max - push->next) / 2 + push->next;
	push->flag++;
}

// Partitionne les éléments de stack1 vers stack2 et les trie en fonction des flags
void	sort_b(t_list **stack1, t_list **stack2, t_push *push)
{
	int		curr_flag;
	t_list	*lst1;

	lst1 = *stack1;
	curr_flag = lst1->flag;
	while (lst1->flag == curr_flag)
	{
		if (lst1->index != push->next)
			pb(stack1, stack2);
		find_next(stack1, stack2, push);
		lst1 = *stack1;
	}
	if (ft_lstsize(*stack2))
		push->max = find_max(stack2)->index;
	push->mid = (push->max - push->next) / 2 + push->next;
}

// Fonction principale de tri rapide des stacks
void	quick_sort(t_list **stack1, t_list **stack2, int count)
{
	t_push	push;

	push.next = find_min(stack1)->index;
	push.max = find_max(stack1)->index;
	push.mid = push.max / 2 + push.next;
	push.flag = 0;
	init_sort(stack1, stack2, &push, count);
	while (!a_sorted(stack1, count))
	{
		if (ft_lstsize(*stack2) == 0)
			sort_b(stack1, stack2, &push);
		else
			sort_a(stack1, stack2, &push);
	}
}

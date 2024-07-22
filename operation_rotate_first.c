/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate_first.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:29:24 by kmailleu          #+#    #+#             */
/*   Updated: 2024/07/22 20:23:50 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate(t_list **first_node)
{
	t_list	*head;
	t_list	*last;

	if (!(*first_node) || !((*first_node)->next))
		return ;
	head = *first_node;
	*first_node = head->next;
	head->next = NULL;
	last = ft_lstlast(*first_node);
	last->next = head;
}

void	ra(t_list **stack1)
{
	rotate(stack1);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack2)
{
	rotate(stack2);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack1, t_list **stack2)
{
	rotate(stack1);
	rotate(stack2);
	write(1, "rr\n", 3);
}

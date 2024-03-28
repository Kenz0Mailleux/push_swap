/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:37:07 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/27 15:27:52 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *from_stack, t_stack *to_stack)
{
	t_stack	*new_head;
	//t_stack	*new_current;

	new_head = from_stack;
	from_stack = from_stack->next;
	// if (ft_lstsize(from_stack) < 1)
	// 	return (-1);
	new_head->next = to_stack;
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	return (1);
}
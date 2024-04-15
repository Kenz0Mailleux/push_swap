/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:37:07 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/15 17:05:44 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push(t_stack *from_stack, t_stack *to_stack)
{
	t_stack	*new_head;
	//t_stack	*new_current;

	new_head = malloc(sizeof(t_stack));
	new_head->next = to_stack;
	new_head->value = from_stack->value;
	from_stack = from_stack->next;
	// if (ft_lstsize(from_stack) < 1)
	// 	return (-1);
	return (1);
}

// int	push(t_stack *from_stack, t_stack *to_stack)
// {
// 	t_stack	*new_head;

// 	from_stack
// }


int	pa(t_stack *a, t_stack *b)
{
	push(a, b);
	return (1);
}
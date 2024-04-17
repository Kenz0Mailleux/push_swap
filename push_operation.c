/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:37:07 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/16 18:29:05 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	static push(t_stack *from_stack, t_stack *to_stack)
{
	t_stack	*newhead;
	int		tmp_value;

	newhead = from_stack;
	*from_stack = *from_stack->next;
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
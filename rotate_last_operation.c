/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_last_operation.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:13:27 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/17 18:12:12 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rev_rotate(t_stack **stack)
{
	t_stack *tmp_head;
	t_stack *last;
	t_stack	*before_last;

	tmp_head = *stack;
	if (ft_stacksize(stack) < 2)
		return (-1);
	last = ft_get_last(*stack);
	before_last = last->previous;
	last->next = tmp_head;
	before_last->next = NULL;
	*stack = last;
	return (1);
}


int	rra(t_stack **a)
{
	if (rev_rotate(a) == -1)
		return (-1);
	ft_putendl_fd("rra", 1);
	return (1);
}

int	rrb(t_stack **b)
{
	if (rev_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrb", 1);
	return (1);
}

int rrr(t_stack **a, t_stack **b)
{
	if (rev_rotate(a) == -1 && rev_rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rrr", 1);
	return (1);
}
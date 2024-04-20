/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_first_operation.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 16:29:24 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/17 18:12:43 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_stack **stack)
{
	t_stack *tmp_head;
	t_stack *last;

	if (ft_stacksize(&stack) < 2)
		return (-1);
	tmp_head = *stack;
	(*stack) = (*stack)->next;
	tmp_head->next = NULL;
	last = ft_get_last(*stack);
	last->next = tmp_head;
	return (1);
}


int	ra(t_stack **a)
{
	if (rotate(a) == -1)
		return (-1);
	ft_putendl_fd("ra", 1);
	return (1);
}

int	rb(t_stack **b)
{
	if (rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rb", 1);
	return (1);
}

int rr(t_stack **a, t_stack **b)
{
	if (rotate(a) == -1 && rotate(b) == -1)
		return (-1);
	ft_putendl_fd("rr", 1);
	return (1);
}
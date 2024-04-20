/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:37:07 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/17 18:10:47 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	static push(t_stack **from_stack, t_stack **to_stack)
{
	t_stack	*tmp_node;

	if (from_stack == NULL)
		return (-1);
	tmp_node = (*from_stack)->next;
	(*from_stack)->next = *to_stack;
	*to_stack = *from_stack;
	*from_stack = tmp_node;
	return (1);
}

int	pa(t_stack **a, t_stack **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (1);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:38:49 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/22 14:20:35 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
	return (1);
}

// int	swap(t_stack **first_node)
// {
// 	t_stack	*tmp;

// 	tmp = (*first_node)->next;
// 	if (*first_node == NULL || (*first_node)->next == NULL)
// 		return (-1);
// 	(*first_node)->next = (*first_node)->next->next;
// 	tmp->next = *first_node;
// 	*first_node = tmp;
// 	return (1);
// }

int	sa(t_stack **a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	sb(t_stack **b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	ss(t_stack **a, t_stack **b)
{
	if (swap(a) == -1 || swap(b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (1);
}

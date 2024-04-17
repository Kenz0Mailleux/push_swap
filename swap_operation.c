/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 16:38:49 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/16 18:12:00 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	int swap(t_stack *stack)
{
	t_stack	*head;
	t_stack	*next;
	int		tmp_val;

	// if (ft_lstsize(stack) < 2)
	// 	return (-1);
	head = stack;
	next = head->next;
	if (!head && !next)
		return (-1);
	tmp_val = head->value;
	head->value = next->value;
	next->value = tmp_val;
	return (1);
}

int	sa(t_stack *a)
{
	if (swap(a) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (1);
}


int	sb(t_stack *b)
{
	if (swap(b) == -1)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (1);
}

int	ss(t_stack *a, t_stack *b)
{
	if (swap(a) == -1 || swap(b) == -1)
		return (-1);
	ft_putendl_fd("ss", 1);
	return (1);
}



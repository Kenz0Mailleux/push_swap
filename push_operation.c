/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 14:37:07 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/22 14:19:58 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	push(t_stack **from_stack, t_stack **to_stack)
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

// int	push(t_stack **first_node_src, t_stack **first_node_dst)
// {
// 	t_stack	*tmp;
	
// 	if (*first_node_src == NULL)
// 		return (-1);
// 	tmp = *first_node_src;
// 	*first_node_src = (*first_node_src)->next;
// 	if (*first_node_dst == NULL)
// 	{	
// 		*first_node_dst = tmp;
// 		(*first_node_dst)->next = NULL;
// 	}
// 	else
// 	{
// 		tmp->next = *first_node_dst;
// 		*first_node_dst = tmp;
// 	}
// 	return (0);
// }

int	pa(t_stack **a, t_stack **b)
{
	if (push(b, a) == -1)
		return (-1);
	ft_putendl_fd("pa", 1);
	return (1);
}

int	pb(t_stack **a, t_stack **b)
{
	if (push(a, b) == -1)
		return (-1);
	ft_putendl_fd("pb", 1);
	return (1);
}

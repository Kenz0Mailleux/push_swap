/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:46:21 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/27 17:48:38 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_min(t_list **stack)
{
	t_list	*min;
	t_list	*current;

	min = *stack;
	current = *stack;
	while (current)
	{
		if (current->content < min->content)
			min = current;
		current = current->next;
	}
	return (min);
}

t_list	*find_max(t_list **stack)
{
	t_list	*max;
	t_list	*current;

	max = *stack;
	current = *stack;
	while (current)
	{
		if (current->content > max->content)
			max = current;
		current = current->next;
	}
	return (max);
}

int	check_sorted(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	while (current && current->next)
	{
		if (current->content > current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

int	a_sorted(t_list **stack_a, int count)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size != count)
		return (0);
	if (!check_sorted(stack_a))
		return (0);
	return (1);
}

int	is_sort(t_swap *tab)
{
	t_list	*current;

	current = tab->stack_a;
	while (current && current->next)
	{
		if (current->content < current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}

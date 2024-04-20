/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:08:03 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/21 01:10:29 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_get_last(t_stack *lst)
{
	while (lst != NULL && lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_stacksize(t_stack *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

int	check_if_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL && stack_a->value < stack_a->next->value)
		stack_a = stack_a->next;
	if (stack_a->next == NULL)
		return (1);
	else
		return (0);
}

int	smallest_number(t_stack *stack_a)
{
	int	smallest;

	smallest = stack_a->value;
	stack_a = stack_a->next;
	while (stack_a != NULL)
	{
		if (stack_a->value < smallest)
			smallest = stack_a->value;
		stack_a = stack_a->next;
	}
	return (smallest);
}

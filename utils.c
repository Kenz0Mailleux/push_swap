/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:08:03 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/21 11:31:10 by kenzo            ###   ########.fr       */
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
	if (ft_strlen(s1) != ft_strlen(s2))
		return (1);
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	check_if_sorted(t_stack *stack)
{
	while (stack->next != NULL && stack->value < stack->next->value)
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	return (0);
}

int	smallest_number(t_stack *stack)
{
	int	smallest;

	smallest = stack->value;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->value < smallest)
			smallest = stack->value;
		stack = stack->next;
	}
	return (smallest);
}

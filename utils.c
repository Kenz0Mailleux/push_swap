/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:08:03 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/20 14:47:10 by kmailleu         ###   ########.fr       */
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
	if (lst != NULL)
	{
		while (lst != NULL)
		{
			size++;
			lst = lst->next;
		}
	}
	return (size);
}

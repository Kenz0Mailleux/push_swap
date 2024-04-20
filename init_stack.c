/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:57:16 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/21 01:06:08 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(char **nbr_list)
{
	t_stack	*head;
	t_stack	*current;
	t_stack	*node;
	int		i;

	head = NULL;
	current = NULL;
	i = 0;
	while (nbr_list[i])
	{
		node = malloc(sizeof(t_stack));
		if (node == NULL)
			return (NULL);
		node->value = ft_atoi(nbr_list[i]);
		node->index = i;
		node->next = NULL;
		node->previous = NULL;
		if (head == NULL)
			head = node;
		else
		{
			current->next = node;
			node->previous = current;
		}
		current = node;
		i++;
	}
	return (head);
}

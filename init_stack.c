/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:34:24 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/22 20:23:33 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	min_value(t_list *lst)
{
	long int	min_value;
	t_list		*current;

	current = lst;
	min_value = LONG_MAX;
	while (current != NULL)
	{
		if (current->index == -1 && current->content < min_value)
			min_value = current->content;
		current = current->next;
	}
	return (min_value);
}

void	add_index(t_list *lst)
{
	int		len;
	int		min;
	int		i;
	t_list	*tmp;

	i = 0;
	len = ft_lstsize(lst);
	while (i < len)
	{
		min = min_value(lst);
		tmp = lst;
		while (tmp)
		{
			if (tmp->index == -1 && tmp->content == min)
				break ;
			tmp = tmp->next;
		}
		tmp->index = i;
		i++;
	}
}

t_list	*ft_init(char **agrv, int argc)
{
	t_list	*current_elem;
	t_list	*list_head;
	int		i;
	long	number;

	i = 1;
	if (argc == 2)
		i = 0;
	list_head = NULL;
	while (agrv[i])
	{
		number = ft_atoi(agrv[i]);
		if (number > INT_MAX || number < INT_MIN || \
			ft_check(list_head, number, agrv[i]) == 0)
			return (ft_putstr_fd("Error\n", 2), NULL);
		current_elem = ft_lstnew(number);
		ft_lstadd_back(&list_head, current_elem);
		current_elem->index = -1;
		i++;
	}
	return (list_head);
}

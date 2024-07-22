/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:41:08 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/22 19:41:31 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_number(char *number_str)
{
	int	i;

	i = 0;
	while (number_str[i])
	{
		if (!(((number_str[i] == '-' || number_str[i] == '+')
					&& ft_isdigit(number_str[i + 1])
					&& (i == 0 || !ft_isdigit(number_str[i - 1])))
				|| ft_isdigit(number_str[i])))
			return (0);
		i++;
	}
	return (1);
}

// Function to check if a number is unique in the list
static int	is_unique_number(t_list *list, int number)
{
	t_list	*current;

	current = list;
	while (current)
	{
		if (current->content == number)
			return (0);
		current = current->next;
	}
	return (1);
}

// Function to check both validity of the number string and uniqueness in the list
int	ft_check(t_list *list, int number, char *number_str)
{
	if (!is_valid_number(number_str))
		return (0);
	if (!is_unique_number(list, number))
		return (0);
	return (1);
}

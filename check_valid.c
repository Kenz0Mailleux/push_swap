/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 00:55:15 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/21 01:01:11 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_int(char *int_str)
{
	int	i;

	i = 0;
	if (int_str[0] == '-' || int_str[0] == '+')
		i++;
	while (!int_str[i])
	{
		if (!(int_str[i] >= '0' && int_str[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

int	check_double(char **lst)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (lst[i] != NULL)
	{
		j = 1;
		while (lst[i + j] != NULL)
		{
			if (!(ft_strcmp(lst[i], lst[i + j])))
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_list(char **lst)
{
	int	i;

	i = 0;
	if (!(check_double(lst)))
	{
		return (0);
	}
	while (lst[i] != NULL)
	{
		if (!check_int(lst[i]))
			return (0);
		i++;
	}
	return (1);
}

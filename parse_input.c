/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:06:18 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/20 17:12:15 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_is_digit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static int	check_sign(char *int_str)
{
	if (int_str[0] == '-' || int_str[0] == '+')
		return (1);
	return (0);
}

static int	check_int(char *int_str)
{
	int	i;

	printf("a\n");
	i = 0;
	if (check_sign(int_str))
		i++;
	while (int_str[i] != NULL)
	{
		if (!ft_is_digit(int_str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	check_list(char **lst)
{
	int	i;

	i = 0;
	while (lst[i] != NULL)
	{
		if (!check_int(lst[i]))
			return (0);
		i++;	
	}
	return (1);
	
		
}

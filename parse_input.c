/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:06:18 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/21 01:02:33 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**parse_one_input(char *argv)
{
	char	**str;

	str = ft_split(argv, ' ');
	if (str == NULL)
		return (NULL);
	return (str);
}

char	**parse_several_input(int argc, char **argv)
{
	char	**nbr_list;
	int		i;
	int		j;

	i = 1;
	j = 0;
	nbr_list = malloc(sizeof(char *) * (argc));
	if (nbr_list == NULL)
		return (NULL);
	while (i < argc)
		nbr_list[j++] = argv[i++];
	return (nbr_list);
}

char	**parse_input(int argc, char **argv)
{
	if (argc == 2)
		return (parse_one_input(argv[1]));
	else
		return (parse_several_input(argc, argv));
}

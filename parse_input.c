/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 18:06:18 by kmailleu          #+#    #+#             */
/*   Updated: 2024/04/22 18:39:39 by kenzo            ###   ########.fr       */
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

char	*ft_strcpy(char *src)
{
	int		i;
	int		n;
	char	*dest;

	n = ft_strlen(src);
	dest = malloc(sizeof(char) * (n + 1));
	if (!dest || !src)
		return (NULL);
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**parse_several_input(int argc, char **argv)
{
	char	**nbr_list;
	int		i;
	int		j;

	i = 1;
	j = 0;
	nbr_list = malloc(sizeof(char *) * (argc + 1));
	if (nbr_list == NULL)
		return (NULL);
	while (i < argc)
	{
		nbr_list[j] = ft_strcpy(argv[i++]);
		if (!nbr_list[j++])
		{
			free_lst(nbr_list);
			return (NULL);
		}
	}
	nbr_list[j] = NULL;
	return (nbr_list);
}

char	**parse_input(int argc, char **argv)
{
	if (argc == 2)
		return (parse_one_input(argv[1]));
	else
		return (parse_several_input(argc, argv));
}

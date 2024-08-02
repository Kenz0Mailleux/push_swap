/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:09:53 by kenzo             #+#    #+#             */
/*   Updated: 2024/08/02 16:43:32 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **agrv)
{
	t_swap	*tab;
	char	**nbr_lst;

	if (argc == 1)
		return (0);
	tab = malloc(sizeof(t_swap));
	if (!tab)
		return (-1);
	if (argc == 2)
	{
		nbr_lst = ft_split(agrv[1], ' ');
		if (nbr_lst[0] == 0 || nbr_lst[1] == 0)
			return (ft_putstr_fd("Error\n", 2), 0);
	}
	else
		nbr_lst = agrv;
	tab->stack_a = ft_init(nbr_lst, argc);
	if (tab->stack_a == NULL)
		return (-1);
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = 0;
	add_index(tab->stack_a);
	check_sort(tab);
	stack_free(tab->stack_a);
}

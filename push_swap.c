/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:09:53 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/27 17:57:11 by kenzo            ###   ########.fr       */
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
		nbr_lst = ft_split(agrv[1], ' ');
	else
		nbr_lst = agrv;
	tab->stack_a = ft_init(nbr_lst, argc);
	if (tab->stack_a == NULL)
		return (-1);
	tab->stack_b = NULL;
	tab->asize = ft_lstsize(tab->stack_a);
	tab->bsize = 0;
	add_index(tab->stack_a); //index qu'il a lorsque déjà trié
	check_sort(tab);
	//free_all(1, nbr_lst);
}

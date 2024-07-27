/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:39:43 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/27 17:58:15 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	stack_free(t_list *lst)
{
	t_list	*tmp_lst;

	if (lst == NULL)
		return ;
	while (lst)
	{
		tmp_lst = lst;
		lst = lst->next;
		free(tmp_lst);
	}
}

void	free_all(int free_nb, char **nbr_lst, t_swap *tab)
{
	int	i;

	i = 0;
	if (free_nb)
	{
		while (nbr_lst[i])
			free(nbr_lst[i++]);
		free(nbr_lst);
	}
	stack_free(tab->stack_a);
	stack_free(tab->stack_b);
	free(tab);
}

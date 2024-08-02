/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_lst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 19:39:43 by kenzo             #+#    #+#             */
/*   Updated: 2024/08/02 16:43:45 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_list *lst)
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

void	free_all(int free_nb, char **nbr_lst)
{
	int	i;

	i = 0;
	if (free_nb)
	{
		while (nbr_lst[i])
			free(nbr_lst[i++]);
		free(nbr_lst);
	}
}

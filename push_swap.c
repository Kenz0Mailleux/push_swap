/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:09:53 by kenzo             #+#    #+#             */
/*   Updated: 2024/03/27 14:42:59 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int *nbr_list)
{
	t_stack *head;
	t_stack *current;
	t_stack *node;
	int i;

	head = NULL;
	current = NULL;
	i = 0;
	while (nbr_list[i] != -1)
	{
		node = malloc(sizeof(t_stack));
		if (node == NULL)
			return NULL;
		node->value = nbr_list[i];
		node->index = i;
		node->next = NULL;
		node->previous = NULL;
		if (head == NULL)
			head = node;
		else
		{
			current->next = node;
			node->previous = current;
		}
		current = node;
		i++;
	}
	return (head);
}



int	*parse_one_input(int argc, char *argv)
{
	char	**str;
	int		*nbr_list;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_split(argv, ' ');
	if (str == NULL)
		return (NULL);
	while (str[i] != NULL)
		i++;
	nbr_list = malloc(sizeof(int) * (i + 1));
	// if (nbr_list == NULL);
	// 	return (NULL);
	i = 0;
	while (str[i] != NULL)
		nbr_list[j++] = ft_atoi(str[i++]);
	nbr_list[j] = -1;
	free(str);
	return (nbr_list);
}

int *parse_several_input(int argc, char **argv)
{
	int		*nbr_list;
	int		i;
	int		j;

	i = 1;
	j = 0;

	nbr_list = malloc(sizeof(int) * argc); //argc n'a pas besoin de +1
	// if (nbr_list == NULL);
	// 	return (NULL);
	while (i < argc)
		nbr_list[j++] = ft_atoi(argv[i++]);
	nbr_list[j] = -1;
	return (nbr_list);
	
}

int	check_input(int argc, char **argv)
{
	return (0);
}

int	*parse_input(int argc, char **argv)
{
	// if	(!check_input(argc, argv))
	// 	return (NULL);
	printf("nbr of input : %d \n", argc);
	if (argc == 2)
		return (parse_one_input(argc, argv[1]));
	else
		return (parse_several_input(argc, argv));
}



int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	int		*nbr_list;

	if (argc < 2)
		return (0);
	nbr_list = parse_input(argc, argv); //check and stock argv in a list
	if (nbr_list == NULL)
		return (0);
	a = init_stack(nbr_list);
	free(nbr_list);
	swap(a);
	int	i = 0;
	while (a != NULL)
	{
		printf("%d \n", a->value);
		a = a->next;
	}
}

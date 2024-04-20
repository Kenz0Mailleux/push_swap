/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmailleu <kmailleu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:09:53 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/17 18:28:11 by kmailleu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	str_len_ptr(char **nbr_list)
{
	int	i;

	i = 0;
	while(nbr_list[i])
		i++;
	return (i);
}


t_stack	*init_stack(char **nbr_list)
{
	t_stack *head;
	t_stack *current;
	t_stack *node;
	int i;

	head = NULL;
	current = NULL;
	i = str_len_ptr(nbr_list)-1;
	while (i > -1)
	{
		node = malloc(sizeof(t_stack));
		if (node == NULL)
			return NULL;
		node->value = ft_atoi(nbr_list[i]);
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
		i--;
	}
	return (head);
}



char	**parse_one_input(char *argv)
{
	char	**str;
	str = ft_split(argv, ' ');

	if (str == NULL)
		return (NULL);
	//tri splited
	return (str);
}

char	**parse_several_input(int argc, char **argv)
{
	char		**nbr_list;
	int		i;
	int		j;
	i = 1;
	j = 0;

	nbr_list = malloc(sizeof(char *) * (argc + 1)); //argc n'a pas besoin de +1
	if (nbr_list == NULL)
	 	return (NULL);
	while (i < argc)
		nbr_list[j++] = argv[i++];
	return (nbr_list);
	
}

// int	check_input(int argc, char **argv)
// {
// 	argc = 0;
// 	argv = NULL;
// 	return (0);
// }

char	**parse_input(int argc, char **argv)
{
	// if	(!check_input(argc, argv))
	// 	return (NULL);
	printf("nbr of input : %d \n", argc);
	if (argc == 2)
		return (parse_one_input(argv[1]));
	else
		return (parse_several_input(argc, argv));
}



int	main(int argc, char *argv[])
{
	t_stack *a;
	t_stack *b;
	char	**nbr_list;

	if (argc < 2)
	{
		printf("need at least one nbr");
		return (0);
	}
	nbr_list = parse_input(argc, argv); //check and stock argv in a list
	if (check_list(nbr_list))
	{
		printf("The input are not correct");
		return(0);
	}
	if (nbr_list == NULL)
		return (0);
	a = init_stack(nbr_list);
	b = malloc(sizeof(t_stack));
	b = NULL;
	printf("Stack A \n");
	while (a != NULL)
	{
		printf("%d \n", a->value);
		a = a->next;
	}
	printf("\nStack B \n");
	while (b != NULL)
	{
	printf("%d \n", b->value);
		b = b->next;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:09:53 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/21 01:03:35 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_check_if_sorted(*stack_a) == 1)
		return ;
	else if (ft_stacksize(*stack_a) == 1)
		return ;
	else if (ft_stacksize(*stack_a) == 2)
		sort_two(stack_a);
	else if (ft_stacksize(*stack_a) == 3)
		sort_three(stack_a);
	else if (ft_stacksize(*stack_a) <= 5)
		sort_four_five(stack_a, stack_b);
	else
		ft_sort_big_list(stack_a, stack_b);
}

void	ft_put_index(t_stack **first_node, int size)
{
	t_stack	*smallest_node;
	t_stack	*tmp;
	int		index;
	int		smallest;

	index = 0;
	tmp = *first_node;
	while (index < size)
	{
		smallest = 2147483647;
		tmp = *first_node;
		while (tmp != NULL)
		{
			if (tmp->value < smallest && tmp->has_index == 0)
			{
				smallest_node = tmp;
				smallest = tmp->value;
			}
			tmp = tmp->next;
		}
		smallest_node->index = index;
		smallest_node->has_index = 1;
		index++;
	}
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	char	**nbr_list;

	if (argc < 2)
	{
		printf("need at least one nbr");
		return (0);
	}
	nbr_list = parse_input(argc, argv);
	if (!check_list(nbr_list))
	{
		printf("The input are not correct");
		return (0);
	}
	if (nbr_list == NULL)
		return (0);
	a = init_stack(nbr_list);
	b = malloc(sizeof(t_stack));
	b = NULL;
	ft_put_index(&a, ft_stacksize(a));
	ft_sort(&a, &b);
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

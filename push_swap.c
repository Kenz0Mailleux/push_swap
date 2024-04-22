/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 15:09:53 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/22 18:51:19 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_free(t_stack *stack)
{
	t_stack *tmp_stack;
	
	if (stack == NULL)
		return ;
	while (stack)
	{
		tmp_stack = stack;
		stack = stack->next;
		free(tmp_stack);
	}
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (check_if_sorted(*stack_a) == 1)
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
		sort_big_list(stack_a, stack_b);
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

void	free_lst(char **nbr_lst)
{
	int	i;

	i = 0;
	while (nbr_lst[i])
	{
		free(nbr_lst[i]);
		i++;
	}
	free(nbr_lst);
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
	b = NULL;
	a = init_stack(nbr_list);
	if (a == 0)
	{
		free_lst(nbr_list);
		stack_free(a);
		stack_free(b);
		return (1);
	}	
	ft_put_index(&a, ft_stacksize(a));
	ft_sort(&a, &b);
	free_lst(nbr_list);
	stack_free(a);
	stack_free(b);
}

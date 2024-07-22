/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:44:51 by kenzo             #+#    #+#             */
/*   Updated: 2024/07/22 19:54:45 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	smallest_number(t_list *stack)
{
	int	smallest;

	smallest = stack->content;
	stack = stack->next;
	while (stack != NULL)
	{
		if (stack->content < smallest)
			smallest = stack->content;
		stack = stack->next;
	}
	return (smallest);
}

static int	check_if_sorted(t_list *stack)
{
	while (stack->next != NULL && stack->content < stack->next->content)
		stack = stack->next;
	if (stack->next == NULL)
		return (1);
	return (0);
}

static int	get_rotate_direction(t_list *stack)
{
	int	smallest;
	int	index;
	int	smallest_index;
	int	list_size;

	index = 0;
	smallest_index = 0;
	smallest = 2147483647;
	list_size = ft_lstsize(stack) / 2;
	while (stack)
	{
		if (stack->content < smallest)
		{
			smallest = stack->content;
			smallest_index = index;
		}
		stack = stack->next;
		index++;
	}
	if (smallest_index < list_size)
		return (1);
	else
		return (-1);
}

static void	sort_four_five(t_list **stack_a, t_list **stack_b)
{
	int	smallest;
	int	rotate_direction;

	while (ft_lstsize(*stack_a) > 3)
	{
		smallest = smallest_number(*stack_a);
		rotate_direction = get_rotate_direction(*stack_a);
		while ((*stack_a)->content != smallest)
		{
			if (rotate_direction == 1)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	while (!check_if_sorted(*stack_a))
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
		else
			rra(stack_a);
	}
	while (ft_lstsize(*stack_b) >= 1)
		pa(stack_a, stack_b);
}

void	check_sort(t_swap	*tab)
{
	int	len;

	len = ft_lstsize(tab->stack_a);
	if (check_sorted(&tab->stack_a))
		return ;
	if (len == 2)
	{
		if (tab->stack_a->content > tab->stack_a->next->content)
			sa(&tab->stack_a);
	}
	else if (len == 3)
	{
		while (!check_if_sorted(tab->stack_a))
		{
			if ((tab->stack_a)->content > (tab->stack_a)->next->content)
				sa(&(tab->stack_a));
			else
				rra(&(tab->stack_a));
		}
	}
	else if (len == 4 || len == 5)
		sort_four_five(&tab->stack_a, &tab->stack_b);
	else
		quick_sort(&tab->stack_a, &tab->stack_b, ft_lstsize(tab->stack_a));
}

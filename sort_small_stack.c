/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kenzo <kenzo@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 23:04:12 by kenzo             #+#    #+#             */
/*   Updated: 2024/04/21 11:32:41 by kenzo            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	sa(stack_a);
}

void	sort_three(t_stack **stack_a)
{
	while (!check_if_sorted(*stack_a))
	{
		if ((*stack_a)->value > (*stack_a)->next->value)
			sa(stack_a);
		else
			rra(stack_a);
	}
}

void	sort_four_five(t_stack **stack_a, t_stack **stack_b)
{
	int	smallest;
	int	rotate_direction;

	while (ft_stacksize(*stack_a) > 3)
	{
		smallest = smallest_number(*stack_a);
		rotate_direction = get_rotate_direction(*stack_a);
		while ((*stack_a)->value != smallest)
		{
			if (rotate_direction == 1)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (ft_stacksize(*stack_b) >= 1)
	{
		pa(stack_a, stack_b);
	}
}

int	get_rotate_direction(t_stack *stack)
{
	int	smallest;
	int	index;
	int	smallest_index;
	int	list_size;

	index = 0;
	smallest_index = 0;
	smallest = 2147483647;
	list_size = ft_stacksize(stack) / 2;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
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

void	sort_big_list(t_stack **stack_a, t_stack **stack_b)
{
	int	bit_pos;
	int	size;
	int	count;

	size = ft_stacksize(*stack_a);
	bit_pos = 1;
	while (check_if_sorted(*stack_a) == 0)
	{
		count = 0;
		while (*stack_a != NULL && count++ < size)
		{
			if (((*stack_a)->index & bit_pos) == 0)
			{
				pb(stack_a, stack_b);
			}
			else
				ra(stack_a);
		}
		while (*stack_b != NULL)
		{
			pa(stack_a, stack_b);
		}
		bit_pos *= 2;
	}
}

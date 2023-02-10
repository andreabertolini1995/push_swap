/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 17:33:54 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/21 18:29:38 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int	g;

void	sort_three(t_stack **stack_a)
{
	int	pos_min;
	int	pos_max;

	pos_min = find_position_in_list(*stack_a, ft_min_in_list(*stack_a));
	pos_max = find_position_in_list(*stack_a, ft_max_in_list(*stack_a));
	if ((pos_min == 1 && pos_max == 2) || (pos_min == 2 && pos_max == 0)
		|| (pos_min == 0 && pos_max == 1))
	{
		swap(stack_a);
		ft_printf("sa\n");
		g++;
		sort_three(stack_a);
	}
	else if (pos_min == 1 && pos_max == 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
		g++;
	}
	else if (pos_min == 2 && pos_max == 1)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
		g++;
	}
}

void	find_min_and_push(t_stack **stack_a, t_stack **stack_b, int pos_min)
{
	int	i;

	i = 0;
	if (pos_min > 0 && pos_min < 3)
		loop_and_rotate(stack_a, pos_min, "stack_a");
	else if (pos_min >= 3)
		loop_and_reverse_rotate(stack_a, pos_min, "stack_a");
	push(stack_a, stack_b);
	ft_printf("pb\n");
	g++;
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	i;

	i = 0;
	find_min_and_push(stack_a, stack_b,
		find_position_in_list(*stack_a, ft_min_in_list(*stack_a)));
	find_min_and_push(stack_a, stack_b,
		find_position_in_list(*stack_a, ft_min_in_list(*stack_a)));
	if ((*stack_b)->data < (*stack_b)->next->data)
	{
		swap(stack_b);
		ft_printf("sb\n");
		g++;
	}
	sort_three(stack_a);
	push_everything_back(stack_a, stack_b);
}

void	sort_two(t_stack **stack_a)
{
	if ((*stack_a)->data > (*stack_a)->next->data)
	{
		swap(stack_a);
		ft_printf("sa\n");
		g++;
	}
}

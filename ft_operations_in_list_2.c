/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 17:18:22 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/19 17:18:23 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

extern int	g;

int	find_position_in_list(t_stack *stack, int n)
{
	t_stack	*ptr;
	int		pos;

	pos = 0;
	ptr = stack;
	while (ptr->data != n)
	{
		pos++;
		ptr = ptr->next;
	}
	return (pos);
}

int	find_position_in_changed_list(t_stack *stack, int n)
{
	t_stack	*ptr;
	int		pos;

	ptr = stack;
	pos = 0;
	while (ptr != NULL)
	{
		while (ptr->data != n)
		{
			pos++;
			ptr = ptr->next;
		}
		if (ptr->changed == false)
		{
			return (pos);
		}
		else
		{
			pos++;
			ptr = ptr->next;
		}
	}
	return (pos);
}

void	replace_data_in_list(t_stack **stack, int pos, int n)
{
	t_stack	*ptr;
	int		i;

	i = 0;
	ptr = *stack;
	while (i < pos)
	{
		ptr = ptr->next;
		i++;
	}
	ptr->data = n;
	ptr->changed = true;
}

void	put_higher_on_top(t_stack **stack_b)
{
	int	rotations_stack_b;
	int	rev_rotations_stack_b;

	rotations_stack_b = find_position_in_list(*stack_b,
			ft_max_in_list(*stack_b));
	rev_rotations_stack_b = ft_stacksize(*stack_b)
		- find_position_in_list(*stack_b, ft_max_in_list(*stack_b));
	if (rotations_stack_b <= rev_rotations_stack_b)
		loop_and_rotate(stack_b, rotations_stack_b, "stack_b");
	else
		loop_and_reverse_rotate(stack_b, rev_rotations_stack_b, "stack_b");
}

void	push_everything_back(t_stack **stack_a, t_stack **stack_b)
{
	int	j;
	int	size_b;

	size_b = ft_stacksize(*stack_b);
	j = 0;
	while (j < size_b)
	{
		push(stack_b, stack_a);
		ft_printf("pa\n");
		g++;
		j++;
	}
}

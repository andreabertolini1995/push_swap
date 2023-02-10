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

int	ft_max_in_list(t_stack *stack)
{
	t_stack	*ptr;
	int		max;

	ptr = stack;
	max = ptr->data;
	while (ptr != NULL)
	{
		if (ptr->data > max)
			max = ptr->data;
		ptr = ptr->next;
	}
	return (max);
}

int	ft_min_in_list(t_stack *stack)
{
	t_stack	*ptr;
	int		min;

	ptr = stack;
	min = ptr->data;
	while (ptr != NULL)
	{
		if (ptr->data < min)
			min = ptr->data;
		ptr = ptr->next;
	}
	return (min);
}

int	ft_tmp_min_in_list(t_stack *stack, int n, int i)
{
	t_stack	*ptr;
	int		tmp_min;

	ptr = stack;
	while (ptr->data <= n)
		ptr = ptr->next;
	tmp_min = ptr->data;
	while (ptr != NULL)
	{
		if (ptr->data < tmp_min && ptr->data > n && (ptr->data < 1 || ptr->data > i-1))
			tmp_min = ptr->data;
		ptr = ptr->next;
	}
	return (tmp_min);
}

int	ft_in_range(int n, int min, int max)
{
	int	i;

	i = min;
	while (i <= max)
	{
		if (n == i)
			return (1);
		i++;
	}
	return (0);
}

int	find_number_to_push(t_stack *stack_a, int *arr, int malloc_size, int size)
{
	t_stack	*ptr;
	int		i;
	int		index;

	ptr = stack_a;
	if (arr[0] <= (size - arr[malloc_size - 1]))
	{
		index = arr[0];
		i = 0;
		while (i < index)
		{
			i++;
			ptr = ptr->next;
		}
	}
	else
	{
		index = size - arr[malloc_size - 1];
		i = 0;
		while (i < size - index)
		{
			i++;
			ptr = ptr->next;
		}
	}
	return (ptr->data);
}

int	ft_highest_lower(int n, t_stack *stack_b)
{
	t_stack	*ptr;
	int		highest_lower;

	highest_lower = 0;
	ptr = stack_b;
	while (ptr != NULL)
	{
		if (ptr->data < n && ptr->data > highest_lower)
			highest_lower = ptr->data;
		ptr = ptr->next;
	}
	return (highest_lower);
}

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

void	replace_data_in_list(t_stack **stack, int pos, int n)
{
	t_stack	*ptr;
	int		i;

	ft_printf("Pos: %d\n", pos);
	ft_printf("N: %d\n", n);
	i = 0;
	ptr = *stack;
	while (i < pos)
	{
		ptr = ptr->next;
		i++;
	}
	ptr->data = n;
}

void	put_higher_on_top(t_stack **stack_b)
{
	int	rotations_stack_b;
	int	rev_rotations_stack_b;
	int	j;

	rotations_stack_b = find_position_in_list(*stack_b, ft_max_in_list(*stack_b));
	rev_rotations_stack_b = ft_stacksize(*stack_b) - find_position_in_list(*stack_b, ft_max_in_list(*stack_b));
	j = 0;
	if (rotations_stack_b <= rev_rotations_stack_b)
	{
		while (j < rotations_stack_b)
		{
			rotate(stack_b);
			ft_printf("rb\n");
			g++;
			j++;
		}
	}
	else
	{
		while (j < rev_rotations_stack_b)
		{
			reverse_rotate(stack_b);
			ft_printf("rrb\n");
			g++;
			j++;
		}
	}
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

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

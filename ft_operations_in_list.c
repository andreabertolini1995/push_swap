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

int	ft_tmp_min_in_list(t_stack *stack, int n)
{
	t_stack	*ptr;
	int		tmp_min;

	ptr = stack;
	while (ptr->data <= n || ptr->changed == true)
		ptr = ptr->next;
	tmp_min = ptr->data;
	while (ptr != NULL)
	{
		if (ptr->data < tmp_min && ptr->data > n && ptr->changed == false)
			tmp_min = ptr->data;
		ptr = ptr->next;
	}
	return (tmp_min);
}

int	find_number_at_index(t_stack *stack_a, int index)
{
	int		i;

	i = 0;
	while (i < index)
	{
		i++;
		stack_a = stack_a->next;
	}
	return (stack_a->data);
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

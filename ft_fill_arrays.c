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

int	*fill_index_array(t_stack *stack_a, int chunk_threshold,
								int malloc_size)
{
	t_stack	*ptr;
	int		i;
	int		count;
	int		*arr;

	arr = (int *) malloc (sizeof(int) * malloc_size);
	if (arr == NULL)
		return (NULL);
	ptr = stack_a;
	i = 0;
	count = 0;
	while (ptr != NULL)
	{
		if (ptr->data <= chunk_threshold)
		{
			arr[i] = count;
			i++;
		}
		count++;
		ptr = ptr->next;
	}
	return (arr);
}

int	**fill_ops_array(t_stack **stack_a, t_stack **stack_b,
						int *arr, int malloc_size)
{
	int	**ops;
	int	i;
	int	number_to_push;
	int	highest_lower;
	int	min_num_operations;

	ops = (int **) malloc (sizeof(int *) * malloc_size);
	if (ops == NULL)
		return (NULL);
	i = 0;
	while (i < malloc_size)
	{
		number_to_push = find_number_at_index(*stack_a, arr[i]);
		highest_lower = ft_highest_lower(number_to_push, *stack_b);
		min_num_operations = calc_min_num_operations(stack_a,
				stack_b, number_to_push, highest_lower);
		ops[i] = (int *) malloc (sizeof(int) * 2);
		if (ops[i] == NULL)
			return (NULL);
		ops[i][0] = number_to_push;
		ops[i][1] = min_num_operations;
		i++;
	}
	return (ops);
}

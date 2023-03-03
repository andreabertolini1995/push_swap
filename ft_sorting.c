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

static void	rotate_or_reverse_rotate(t_stack **stack_a, t_stack **stack_b,
										int num_to_push, int highest_lower)
{
	int	rot_stack_a;
	int	rev_rot_stack_a;
	int	rot_stack_b;
	int	rev_rot_stack_b;

	rot_stack_a = calc_num_rotations_stack_a(stack_a,
			ft_stacksize(*stack_a), num_to_push);
	rev_rot_stack_a = calc_num_rev_rotations_stack_a(
			ft_stacksize(*stack_a), rot_stack_a);
	rot_stack_b = calc_num_rotations_stack_b(num_to_push,
			highest_lower, stack_b);
	rev_rot_stack_b = calc_num_rev_rotations_stack_b(num_to_push,
			highest_lower, stack_b);
	if (condition_1(rot_stack_a, rot_stack_b, rev_rot_stack_a, rev_rot_stack_b))
		only_rot(stack_a, stack_b, rot_stack_a, rot_stack_b);
	else if (condition_2(rot_stack_a, rot_stack_b,
			rev_rot_stack_a, rev_rot_stack_b))
		only_reverse_rot(stack_a, stack_b, rev_rot_stack_a, rev_rot_stack_b);
	else if (condition_3(rot_stack_a, rot_stack_b,
			rev_rot_stack_a, rev_rot_stack_b))
		rot_a_rev_rot_b(stack_a, stack_b, rot_stack_a, rev_rot_stack_b);
	else
		rot_b_rev_rot_a(stack_a, stack_b, rev_rot_stack_a, rot_stack_b);
	push(stack_a, stack_b);
	ft_printf("pb\n");
}

static int	find_number_to_push(int **ops, int min_num_ops)
{
	int	i;

	i = 0;
	while (ops[i][1] != min_num_ops)
		i++;
	return (ops[i][0]);
}

static void	free_arrays(int **ops, int *arr, int malloc_size)
{
	int	i;

	i = 0;
	while (i < malloc_size)
	{
		free(ops[i]);
		i++;
	}
	free(arr);
	free(ops);
}

static void	push_chunks(t_stack **stack_a, t_stack **stack_b,
							int malloc_size, int chunk_threshold)
{
	int	*arr;
	int	**ops;
	int	number_to_push;
	int	highest_lower;

	arr = fill_index_array(*stack_a, chunk_threshold, malloc_size);
	ops = fill_ops_array(stack_a, stack_b, arr, malloc_size);
	number_to_push = find_number_to_push(ops,
			ft_min_in_array(ops, malloc_size));
	highest_lower = ft_highest_lower(number_to_push, *stack_b);
	if (ft_stacksize(*stack_b) <= 1)
	{
		multiple_rotations(stack_a, arr, malloc_size, ft_stacksize(*stack_a));
		push(stack_a, stack_b);
		ft_printf("pb\n");
		if (ft_stacksize(*stack_b) == 2 && highest_lower == 0)
		{
			swap(stack_b);
			ft_printf("sb\n");
		}
	}
	else
		rotate_or_reverse_rotate(stack_a, stack_b,
			number_to_push, highest_lower);
	free_arrays(ops, arr, malloc_size);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b,
							int initial_size)
{
	int	malloc_size;

	while (ft_stacksize(*stack_a) > 0)
	{
		malloc_size = ft_stacksize(*stack_a);
		push_chunks(stack_a, stack_b, malloc_size, initial_size);
	}
	put_higher_on_top(stack_b);
	push_everything_back(stack_a, stack_b);
}

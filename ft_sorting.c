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

int	g;

static void	multiple_rotations(t_stack **stack_a, int *arr, int malloc_size, int size)
{
	int	i;

	if (arr[0] <= (size - arr[malloc_size - 1]))
	{
		i = 0;
		while (i < arr[0])
		{
			rotate(stack_a);
			ft_printf("ra\n");
			g++;
			i++;
		}
	}
	else
	{
		i = 0;
		while (i < (size - arr[malloc_size - 1]))
		{
			reverse_rotate(stack_a);
			ft_printf("rra\n");
			g++;
			i++;
		}
	}
}

static int	*fill_index_array(t_stack *stack_a, int chunk_threshold, int malloc_size)
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

static void	rotate_or_reverse_rotate(t_stack **stack_a, t_stack **stack_b, int number_to_push, int highest_lower)
{
	int	rotations_stack_a;
	int	rev_rotations_stack_a;
	int	rotations_stack_b;
	int	rev_rotations_stack_b;

	rotations_stack_a = calc_num_rotations_stack_a(stack_a, ft_stacksize(*stack_a), number_to_push);
	rev_rotations_stack_a = calc_num_rev_rotations_stack_a(ft_stacksize(*stack_a), rotations_stack_a);
	rotations_stack_b = calc_num_rotations_stack_b(number_to_push, highest_lower, stack_b);
	rev_rotations_stack_b = calc_num_rev_rotations_stack_b(number_to_push, highest_lower, stack_b);
	if (ft_max(rotations_stack_a, rotations_stack_b) <= ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		&& ft_max(rotations_stack_a, rotations_stack_b) <= rotations_stack_b + rev_rotations_stack_a
		&& ft_max(rotations_stack_a, rotations_stack_b) <= rotations_stack_a + rev_rotations_stack_b)
		only_rotations(stack_a, stack_b, rotations_stack_a, rotations_stack_b);
	else if (ft_max(rev_rotations_stack_a, rev_rotations_stack_b) <= ft_max(rotations_stack_a, rotations_stack_b)
		&& ft_max(rev_rotations_stack_a, rev_rotations_stack_b) <= rotations_stack_b + rev_rotations_stack_a
		&& ft_max(rev_rotations_stack_a, rev_rotations_stack_b) <= rotations_stack_a + rev_rotations_stack_b)
		only_reverse_rotations(stack_a, stack_b, rev_rotations_stack_a, rev_rotations_stack_b);
	else if (rotations_stack_a + rev_rotations_stack_b <= ft_max(rotations_stack_a, rotations_stack_b)
		&& rotations_stack_a + rev_rotations_stack_b <= ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		&& rotations_stack_a + rev_rotations_stack_b <= (rotations_stack_b + rev_rotations_stack_a))
		rotations_a_rev_rotations_b(stack_a, stack_b, rotations_stack_a, rev_rotations_stack_b);
	else
		rotations_b_rev_rotations_a(stack_a, stack_b, rev_rotations_stack_a, rotations_stack_b);
	push(stack_a, stack_b);
	ft_printf("pb\n");
	g++;
}

static void	push_chunks(t_stack **stack_a, t_stack **stack_b, int malloc_size, int chunk_threshold)
{
	int	number_to_push;
	int	highest_lower;
	int	*arr;

	arr = fill_index_array(*stack_a, chunk_threshold, malloc_size);
	number_to_push = find_number_to_push(*stack_a, arr, malloc_size, ft_stacksize(*stack_a));
	highest_lower = ft_highest_lower(number_to_push, *stack_b);
	if (ft_stacksize(*stack_b) <= 1)
	{
		multiple_rotations(stack_a, arr, malloc_size, ft_stacksize(*stack_a));
		push(stack_a, stack_b);
		ft_printf("pb\n");
		g++;
		if (ft_stacksize(*stack_b) == 2 && highest_lower == 0)
		{
			swap(stack_b);
			ft_printf("sb\n");
			g++;
		}
	}
	else
		rotate_or_reverse_rotate(stack_a, stack_b, number_to_push, highest_lower);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b, int initial_size, int chunk_size)
{
	int	num_chunks;
	int	chunk_threshold;
	int	malloc_size;

	g = 0;
	num_chunks = initial_size / chunk_size;
	chunk_threshold = chunk_size;
	while (num_chunks > 0)
	{
		while (ft_stacksize(*stack_a) > (initial_size - chunk_threshold))
		{
			malloc_size = ft_stacksize(*stack_a) - chunk_size * (num_chunks - 1);
			push_chunks(stack_a, stack_b, malloc_size, chunk_threshold);
		}
		num_chunks -= 1;
		chunk_threshold += chunk_size;
	}
	put_higher_on_top(stack_b);
	push_everything_back(stack_a, stack_b);
	ft_print_stack_stats(*stack_a, *stack_b);
	ft_print_list_data(*stack_a);
}

/*
Current status:
- the algorithm seems to work with 100 numbers from 1 to 100, most of the times the number of operations is below 700 but sometimes it exceeds (never above 800 in my tests)
- with a set of 100 random numbers it still does not work - there are some hardcoded values that need to be changed and make more dyamic
- try with different number of chunks - DONE, for 100 numbers 5 chunks seems to be the best
- also, it seems that the code does not complain if I insert a number of chunks not perfectly divisible by the size of the stack (not always true actually)
- the algorithm works for any size of the list (tried 500) - around 50 I found the best chunks size but would be nice to come up with a formula

Next steps:
- make the algorithm work for anytipe of set - TO CHECK, but it should work
- try to come up with a formula (?) to understand the best number of chunks (this part can be hardcoded) (it should be a curve - maybe use Chat GPT)
- use the checker
- use the visualizer
- write the function to handle 1, 3, 5 numbers stacks
*/

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

static void	fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
	int	i;

	i = 2;
	while (i < argc)
	{
		ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
		i++;
	}
}

static void	transform_stack(t_stack **stack_a)
{
	int	tmp_min;
	int	new_min;
	int	i;

	i = 1;
	tmp_min = ft_min_in_list(*stack_a);
	replace_data_in_list(stack_a, find_position_in_list(*stack_a, tmp_min), i);
	i++;
	while (i <= ft_stacksize(*stack_a))
	{
		new_min = ft_tmp_min_in_list(*stack_a, tmp_min);
		tmp_min = new_min;
		replace_data_in_list(stack_a,
			find_position_in_changed_list(*stack_a, tmp_min), i);
		i++;
	}
}

static int	calc_num_chunks(int input_numbers)
{
	int	num_chunks;

	if (input_numbers % 5 == 0)
		num_chunks = 5;
	else if (input_numbers % 2 == 0)
		num_chunks = 2;
	else
		num_chunks = 1;
	return (num_chunks);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		num_chunks;
	int		input_numbers;

	input_numbers = argc - 1;
	if (input_numbers == 0 || input_numbers == 1)
		exit(0);
	else
	{
		stack_a = ft_stacknew(ft_atoi(argv[1]));
		stack_b = NULL;
		fill_stack_a(stack_a, argc, argv);
		if (input_numbers == 2 || input_numbers == 3 || input_numbers == 5)
			sort_two_three_five(&stack_a, &stack_b, input_numbers);
		else
		{
			transform_stack(&stack_a);
			num_chunks = calc_num_chunks(input_numbers);
			sort_stack(&stack_a, &stack_b, ft_stacksize(stack_a), num_chunks);
		}
	}
	free_stack(&stack_a);
}

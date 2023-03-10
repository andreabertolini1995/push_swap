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

void	is_stack_sorted(t_stack *stack)
{
	int		count;
	t_stack	*ptr;

	ptr = stack;
	count = 0;
	while (ptr != NULL && ptr->next != NULL)
	{
		if (ptr->data < ptr->next->data)
			count++;
		ptr = ptr->next;
	}
	if (count == ft_stacksize(stack) - 1)
	{
		free_stack(&stack);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		input_numbers;

	input_numbers = argc - 1;
	if (input_numbers == 0)
		exit(0);
	else
	{
		check_input(input_numbers, argv);
		stack_a = ft_stacknew(ft_atoi(argv[1]));
		stack_b = NULL;
		fill_stack_a(stack_a, argc, argv);
		is_stack_sorted(stack_a);
		error_handling(stack_a);
		if (input_numbers == 2 || input_numbers == 3 || input_numbers == 5)
			sort_two_three_five(&stack_a, &stack_b, input_numbers);
		else
		{
			transform_stack(&stack_a);
			sort_stack(&stack_a, &stack_b, ft_stacksize(stack_a));
		}
	}
	free_stack(&stack_a);
}

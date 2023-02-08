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
		replace_data_in_list(stack_a, find_position_in_list(*stack_a, tmp_min), i);
		i++;
	}
}

static void	sort_three(t_stack **stack_a)
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
		sort_three(stack_a);
	}
	else if (pos_min == 1 && pos_max == 0)
	{
		rotate(stack_a);
		ft_printf("ra\n");
	}
	else if (pos_min == 2 && pos_max == 1)
	{
		reverse_rotate(stack_a);
		ft_printf("rra\n");
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		chunk_size;

	chunk_size = 20;
	if (argc == 1)
		exit(0);
	else
	{
		stack_a = ft_stacknew(ft_atoi(argv[1]));
		stack_b = NULL;
		fill_stack_a(stack_a, argc, argv);
		if (argc == 4)
			sort_three(&stack_a);
		else
		{
			transform_stack(&stack_a);
			sort_stack(&stack_a, &stack_b, ft_stacksize(stack_a), chunk_size);
		}
	}
	ft_print_list_data(stack_a);
}

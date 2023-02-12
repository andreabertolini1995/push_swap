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

void	ft_print_stack_stats(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("--------------------------------\n");
	ft_printf("Size stack_a: %d\n", ft_stacksize(stack_a));
	if (ft_stacksize(stack_a) > 0)
	{
		ft_printf("First element of stack a: %d\n", stack_a->data);
		ft_printf("Last element of stack a: %d\n", ft_stacklast(stack_a)->data);
	}
	ft_printf("\nSize stack_b: %d\n", ft_stacksize(stack_b));
	if (ft_stacksize(stack_b) > 0)
	{
		ft_printf("First element of stack b: %d\n", stack_b->data);
		ft_printf("Last element of stack b: %d\n", ft_stacklast(stack_b)->data);
	}
	ft_printf("--------------------------------\n");
}

void	ft_print_list_data(t_stack *stack)
{
	if (ft_stacksize(stack) > 0)
	{
		while (stack->next != NULL)
		{
			ft_printf("%d\n", stack->data);
			stack = stack->next;
		}
		ft_printf("%d\n", stack->data);
	}
}

void	ft_print_array(int *arr, int malloc_size)
{
	int	i;

	i = 0;
	while (i < malloc_size)
	{
		ft_printf("Array element: %d\n", arr[i]);
		i++;
	}
}

void	ft_print_rotations(int rotations_stack_a, int rev_rotations_stack_a,
		int rotations_stack_b, int rev_rotations_stack_b)
{
	ft_printf("-----------------------------\n");
	ft_printf("Rotations stack_a: %d\n", rotations_stack_a);
	ft_printf("Rotations stack_b: %d\n", rotations_stack_b);
	ft_printf("Rev rotations stack_a: %d\n", rev_rotations_stack_a);
	ft_printf("Rev rotations stack_b: %d\n", rev_rotations_stack_b);
	ft_printf("-----------------------------\n");
}

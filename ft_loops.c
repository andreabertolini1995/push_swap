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

void	loop_and_rotate(t_stack **stack, int lim, char *str)
{
	int	i;

	i = 0;
	while (i < lim)
	{
		rotate(stack);
		if (!ft_strncmp(str, "stack_a", ft_strlen(str)))
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
		i++;
	}
}

void	loop_and_reverse_rotate(t_stack **stack, int lim, char *str)
{
	int	i;

	i = 0;
	while (i < lim)
	{
		reverse_rotate(stack);
		if (!ft_strncmp(str, "stack_a", ft_strlen(str)))
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
		i++;
	}
}

void	multiple_rotations(t_stack **stack_a, int *arr,
								int malloc_size, int size)
{
	if (arr[0] <= (size - arr[malloc_size - 1]))
		loop_and_rotate(stack_a, arr[0], "stack_a");
	else
		loop_and_reverse_rotate(stack_a,
			size - arr[malloc_size - 1], "stack_a");
}

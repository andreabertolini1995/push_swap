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

void	only_rot(t_stack **stack_a, t_stack **stack_b,
			int rotations_stack_a, int rotations_stack_b)
{
	int	j;

	j = 0;
	while (j < ft_min(rotations_stack_a, rotations_stack_b))
	{
		rotate(stack_a);
		rotate(stack_b);
		ft_printf("rr\n");
		j++;
	}
	j = 0;
	if (rotations_stack_a >= rotations_stack_b)
		loop_and_rotate(stack_a, rotations_stack_a
			- rotations_stack_b, "stack_a");
	else
		loop_and_rotate(stack_b, rotations_stack_b
			- rotations_stack_a, "stack_b");
}

void	only_reverse_rot(t_stack **stack_a, t_stack **stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b)
{
	int	j;

	j = 0;
	while (j < ft_min(rev_rotations_stack_a, rev_rotations_stack_b))
	{
		reverse_rotate(stack_a);
		reverse_rotate(stack_b);
		ft_printf("rrr\n");
		j++;
	}
	j = 0;
	if (rev_rotations_stack_a >= rev_rotations_stack_b)
		loop_and_reverse_rotate(stack_a, rev_rotations_stack_a
			- rev_rotations_stack_b, "stack_a");
	else
		loop_and_reverse_rotate(stack_b, rev_rotations_stack_b
			- rev_rotations_stack_a, "stack_b");
}

void	rot_a_rev_rot_b(t_stack **stack_a, t_stack **stack_b,
			int rotations_stack_a, int rev_rotations_stack_b)
{
	loop_and_rotate(stack_a, rotations_stack_a, "stack_a");
	loop_and_reverse_rotate(stack_b, rev_rotations_stack_b, "stack_b");
}

void	rot_b_rev_rot_a(t_stack **stack_a, t_stack **stack_b,
			int rev_rotations_stack_a, int rotations_stack_b)
{
	loop_and_reverse_rotate(stack_a, rev_rotations_stack_a, "stack_a");
	loop_and_rotate(stack_b, rotations_stack_b, "stack_b");
}

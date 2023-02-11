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

int	condition_1(int rotations_stack_a, int rotations_stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b)
{
	if (ft_max(rotations_stack_a, rotations_stack_b)
		<= ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		&& ft_max(rotations_stack_a, rotations_stack_b)
		<= rotations_stack_b + rev_rotations_stack_a
		&& ft_max(rotations_stack_a, rotations_stack_b)
		<= rotations_stack_a + rev_rotations_stack_b)
		return (1);
	else
		return (0);
}

int	condition_2(int rotations_stack_a, int rotations_stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b)
{
	if (ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		<= ft_max(rotations_stack_a, rotations_stack_b)
		&& ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		<= rotations_stack_b + rev_rotations_stack_a
		&& ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		<= rotations_stack_a + rev_rotations_stack_b)
		return (1);
	else
		return (0);
}

int	condition_3(int rotations_stack_a, int rotations_stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b)
{
	if (rotations_stack_a + rev_rotations_stack_b
		<= ft_max(rotations_stack_a, rotations_stack_b)
		&& rotations_stack_a + rev_rotations_stack_b
		<= ft_max(rev_rotations_stack_a, rev_rotations_stack_b)
		&& rotations_stack_a + rev_rotations_stack_b
		<= (rotations_stack_b + rev_rotations_stack_a))
		return (1);
	else
		return (0);
}

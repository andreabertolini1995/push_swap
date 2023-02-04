/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 14:42:12 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/20 14:42:16 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_num_rotations_stack_a(t_stack **stack_a, int size, int number_to_push)
{
    int rotations;

    if (size == 1)
        rotations = 0;
    else
        rotations = find_position_in_list(*stack_a, number_to_push);
    return (rotations);
}

int calc_num_rev_rotations_stack_a(int size, int rotations)
{
    int rev_rotations;
    
    if (size == 1)
        rev_rotations = 0;
    else
        rev_rotations = size - rotations;
    return (rev_rotations);
}

int calc_num_rotations_stack_b(int number_to_push, int highest_lower, t_stack **stack_b)
{
    int rotations;

    if (number_to_push < ft_min_in_list(*stack_b) || number_to_push > ft_max_in_list(*stack_b))
        rotations = find_position_in_list(*stack_b, ft_max_in_list(*stack_b));
    else
        rotations = find_position_in_list(*stack_b, highest_lower);
    return (rotations);
}

int calc_num_rev_rotations_stack_b(int number_to_push, int highest_lower, t_stack **stack_b)
{
    int rev_rotations;
    
    if (number_to_push < ft_min_in_list(*stack_b) || number_to_push > ft_max_in_list(*stack_b))
        rev_rotations = ft_stacksize(*stack_b) - find_position_in_list(*stack_b, ft_max_in_list(*stack_b));
    else
        rev_rotations = ft_stacksize(*stack_b) - find_position_in_list(*stack_b, highest_lower);
    return (rev_rotations);
}
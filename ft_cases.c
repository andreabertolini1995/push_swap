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

extern int g;

void    only_rotations(t_stack **stack_a, t_stack **stack_b, int rotations_stack_a, int rotations_stack_b)
{
    int j;

    j = 0;
    while (j < ft_min(rotations_stack_a, rotations_stack_b))
    {
        rotate(stack_a);
        rotate(stack_b);
        ft_printf("rr\n");
        g++;
        j++;
    }
    j = 0;
    if (rotations_stack_a >= rotations_stack_b)
    { 
        while (j < (rotations_stack_a - rotations_stack_b))
        {
            rotate(stack_a);
            ft_printf("ra\n");
            g++;
            j++;
        }                        
    }
    else
    {
        while (j < (rotations_stack_b - rotations_stack_a))
        {
            rotate(stack_b);
            ft_printf("rb\n");
            g++;
            j++;
        }       
    }
}

void only_reverse_rotations(t_stack **stack_a, t_stack **stack_b, int rev_rotations_stack_a, int rev_rotations_stack_b)
{
    int j;

    j = 0;
    while (j < ft_min(rev_rotations_stack_a, rev_rotations_stack_b))
    {
        reverse_rotate(stack_a);
        reverse_rotate(stack_b);
        ft_printf("rr\n");
        g++;
        j++;
    }
    j = 0;
    if (rev_rotations_stack_a >= rev_rotations_stack_b)
    { 
        while (j < (rev_rotations_stack_a - rev_rotations_stack_b))
        {
            reverse_rotate(stack_a);
            ft_printf("rra\n");
            g++;
            j++;
        }                        
    } 
    else
    {
        while (j < (rev_rotations_stack_b - rev_rotations_stack_a))
        {
            reverse_rotate(stack_b);
            ft_printf("rrb\n");
            g++;
            j++;
        }       
    }
}

void    rotations_a_rev_rotations_b(t_stack **stack_a, t_stack **stack_b, int rotations_stack_a, int rev_rotations_stack_b)
{
    int j;

    j = 0;
    while (j < rotations_stack_a)
    {
        rotate(stack_a);
        ft_printf("ra\n");
        g++;
        j++;
    }
    j = 0;
    while (j < rev_rotations_stack_b)
    {
        reverse_rotate(stack_b);
        ft_printf("rrb\n");
        g++;
        j++;
    }      
}

void    rotations_b_rev_rotations_a(t_stack **stack_a, t_stack **stack_b, int rev_rotations_stack_a, int rotations_stack_b)
{
    int j;

    j = 0;
    while (j < rev_rotations_stack_a)
    {
        reverse_rotate(stack_a);
        ft_printf("rra\n");
        g++;
        j++;
    }
    j = 0;
    while (j < rotations_stack_b)
    {
        rotate(stack_b);
        ft_printf("rb\n");
        g++;
        j++;
    } 
}

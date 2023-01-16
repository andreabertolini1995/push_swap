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

void    ft_swap(int *stack, int size)
{
    int tmp;

    if (size >= 2)
        tmp = stack[0];
        stack[0] = stack[1];
        stack[1] = tmp;
}

void    ft_push(int* stack_a, int *stack_b, int size)
{
    int i;

    if (!stack_b)
    {
        // Maybe this can be done more efficiently with memmove
        i = size - 1;
        while (i > 0)
        {
            stack_a[i] = stack_a[i - 1];
            i--;
        }        
        stack_a[i] = stack_b[0];
        i = 0;
        while (i < size + 1)
        {
            stack_b[i] = stack_b[i + 1];
            i++;
        }
    }
}

void    ft_rotate(int* stack, int size)
{
    int i;
    int tmp;

    tmp = stack[0];
    i = 0;
    while (i < size)
    {
       stack[i] = stack[i + 1];
       i++;
    }
    stack[i] = tmp;
}

void    ft_reverse_rotate(int* stack, int size)
{
    int i;
    int tmp;

    tmp = stack[size - 1];
    i = size - 1;
    while (i > 0)
    {
       stack[i] = stack[i - 1];
       i--;
    }
    stack[i] = tmp;
}

/* 1st STRATEGY 
- go through stack A and check for the first pair of integers to swap
- swap them if they are the beginning
- if not, push all the already sorted elements in stack B 
- swap the elements in stack A
- push all the elements back from B to A and then repeat 

USING LINKED LISTS
- define a struct type called stack_t or something like that
- it can contain the array, the min, first, last value etc
*/
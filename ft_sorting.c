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

t_stack   *check_chunk(t_stack *stack_a, int chunk_threshold, int malloc_size)
{
    t_stack *ptr;
    int     i;
    int     count;
    int     *arr;

    // the malloc size is hardcoded - has to be changed
    arr = (int *) malloc (sizeof(int) * malloc_size);
    if (arr == NULL)
        return (NULL);
    ft_printf("Malloc size: %d\n", malloc_size);
    ptr = stack_a;
    i = 0;
    count = 0;
    while (ptr != NULL)
    {
        if (ptr->data <= chunk_threshold)
        {
            arr[i] = count;
            i++;
        }
        count++;
        ptr = ptr->next;
    }
    stack_a = multiple_rotations(stack_a, arr, malloc_size, ft_stacksize(stack_a));
    free(arr);
    return (stack_a);
}

t_stack    *multiple_rotations(t_stack *stack_a, int *arr, int malloc_size, int size)
{
    int     i;

    if (arr[0] <= (size - arr[malloc_size - 1]))
    {
        i = 0;
        while (i < arr[0])
        {
            stack_a = rotate(stack_a);
            ft_printf("ra\n");
            i++;
        }
    }
    else
    {
        i = 0;
        while (i < (size - arr[malloc_size - 1]))
        {
            stack_a = reverse_rotate(stack_a);
            ft_printf("rra\n");
            i++;
        }
    }
    return (stack_a);
}

t_stack    *sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    int chunk_size;
    int num_chunks;
    int chunk_threshold;
    int initial_size;

    initial_size = ft_stacksize(stack_a);
    // Hard-coded values (for now)
    chunk_size = 20; 
    num_chunks = initial_size / chunk_size; 
    chunk_threshold = chunk_size;
    while (num_chunks > 0)
    {
        while (ft_stacksize(stack_a) > (initial_size - chunk_threshold))
        {
            stack_a = check_chunk(stack_a, chunk_threshold, ft_stacksize(stack_a) - chunk_size * (num_chunks - 1));
            stack_b = push(stack_a, stack_b);
            stack_a = remove_first_node(stack_a);
            ft_printf("pb\n");
            ft_printf("Size stack_a: %d\n", ft_stacksize(stack_a));
            ft_printf("First element of stack a: %d\n", stack_a->data);
            ft_printf("Last element of stack a: %d\n", ft_stacklast(stack_a)->data);
            ft_printf("Size stack_b: %d\n", ft_stacksize(stack_b));
            ft_printf("First element of stack b: %d\n\n", stack_b->data);
        }
        num_chunks -= 1;
        chunk_threshold += chunk_threshold;
    }
    return (stack_a);
}
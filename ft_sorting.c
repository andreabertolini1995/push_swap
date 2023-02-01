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

int g;

void    ft_print_stack_stats(t_stack *stack_a, t_stack *stack_b)
{
    ft_printf("\nSize stack_a: %d\n", ft_stacksize(stack_a));
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
    ft_printf("Total number of operations: %d\n", g);
}

t_stack   *check_chunk(t_stack *stack_a, int chunk_threshold, int malloc_size)
{
    t_stack *ptr;
    int     i;
    int     count;
    int     *arr;

    arr = (int *) malloc (sizeof(int) * malloc_size);
    if (arr == NULL)
        return (NULL);
    // ft_printf("Malloc size: %d\n", malloc_size);
    ptr = stack_a;
    i = 0;
    count = 0;
    while (ptr != NULL)
    {
        if (ptr->data <= chunk_threshold)
        {
            arr[i] = count;
            // printf("Count: %d\n", count);
            // printf("i: %d\n", i);
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
            g++;
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
            g++;
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

    g = 0;
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
            g++;
            ft_print_stack_stats(stack_a, stack_b);
        }
        num_chunks -= 1;
        chunk_threshold += chunk_size;
    }
    return (stack_a);
}

/* NEXT STEPS
My theory was wrong - I was not considering the fact that I cant' directly access numbers from below 
Need to find an alternative to re order from the stack
So, now the plan is to push stuff in stack B already in right position (let's say we want to push N)
1. To do so, it is needed to check for the highest number lower than N and the lowest number higher than N in stack B and position N between the two (or something like that)
2. Given certain conditions (still to find out) here is where we might want to rotate / reverse rotate the two stacks simoultaneously (at least for a bit)
3. In theory, along the way the rotations needed are going to be always less and also bringing back at the top of stack B the highest number of all should not be very expensive
4. Push all the numbers back
5. Done

Margin for optimization can be: 
- Swap instead of rotate / reverse rotate if the first two numbers are both good to go (probably not going to make us gain a lot buy fairly easy to implement)
- More ideas will hopefully come up by looking at the visualizer
*/

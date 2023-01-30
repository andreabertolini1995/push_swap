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

t_stack    *swap(t_stack *stack)
{
    t_stack *tmp;

    tmp = stack->next;
    stack->next = stack->next->next;
    tmp->next = stack;
    stack = tmp;
    return(stack);
}

t_stack    *remove_first_node(t_stack *stack)
{
    t_stack *first_node;
    
    first_node = stack;
    stack = stack->next;
    free(first_node);
    return(stack);
}

t_stack    *push(t_stack *stack_a, t_stack *stack_b)
{
    int     size;
  
    size = ft_stacksize(stack_b);
    if (size == 0)
        stack_b = ft_stacknew(stack_a->data);
    else
        stack_b = ft_stackadd_front(stack_b, ft_stacknew(stack_a->data));
    return(stack_b);
}

t_stack    *rotate(t_stack *stack)
{
    ft_stackadd_back(stack, ft_stacknew(stack->data));
    remove_first_node(stack);
    return (stack);
}

t_stack    *reverse_rotate(t_stack *stack)
{    
    t_stack *last_node;
    t_stack *second_but_last_node;
    
    last_node = ft_stacklast(stack);
    second_but_last_node = ft_stacksecondbutlast(stack);
    second_but_last_node->next = NULL;
    stack = ft_stackadd_front(stack, last_node);
    // stack = last_node;
    return (stack);
}

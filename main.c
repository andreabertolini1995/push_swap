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

static void    fill_stack_a(t_stack *stack_a, int argc, char **argv)
{
    int i;

    i = 2;
    while (i < argc)
    {
        ft_stackadd_back(&stack_a, ft_stacknew(ft_atoi(argv[i])));
        i++;
    }
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;

    if (argc == 1)
        exit(0);
    else
    {
        stack_a = ft_stacknew(ft_atoi(argv[1]));
        stack_b = NULL;
        fill_stack_a(stack_a, argc, argv);
    }
    sort_stack(&stack_a, &stack_b, ft_stacksize(stack_a));
}
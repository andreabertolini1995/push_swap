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

int main(int argc, char **argv)
{
    int i;
    int *stack_a;
    int *stack_b;

    ft_printf("%d\n", argc);
    if (argc == 1)
        exit(0);
    else
    {
        stack_a = (int*) malloc (sizeof(int) * argc);
        if (stack_a == NULL)
            return (0);
        i = 1;
        while (i < argc)
        {
            stack_a[i - 1] = argv[i];
            i++;
        }
    }
}
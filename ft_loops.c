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

extern int	g;

void	loop_and_rotate(t_stack **stack, int lim, char *str)
{
	int	i;

	i = 0;
	while (i < lim)
	{
		rotate(stack);
		if (!strcmp(str, "stack_a"))
			ft_printf("ra\n");
		else
			ft_printf("rb\n");
		g++;
		i++;
	}
}

void	loop_and_reverse_rotate(t_stack **stack, int lim, char *str)
{
	int	i;

	i = 0;
	while (i < lim)
	{
		reverse_rotate(stack);
		if (!strcmp(str, "stack_a"))
			ft_printf("rra\n");
		else
			ft_printf("rrb\n");
		g++;
		i++;
	}
}

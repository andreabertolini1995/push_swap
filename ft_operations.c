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

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	tmp = (*stack)->next;
	(*stack)->next = (*stack)->next->next;
	tmp->next = *stack;
	*stack = tmp;
}

void	push(t_stack **src, t_stack **dest)
{
	int	size;

	size = ft_stacksize(*dest);
	if (size == 0)
		*dest = ft_stacknew((*src)->data);
	else
		ft_stackadd_front(dest, ft_stacknew((*src)->data));
	remove_first_node(src);
}

void	rotate(t_stack **stack)
{
	ft_stackadd_back(stack, ft_stacknew((*stack)->data));
	remove_first_node(stack);
}

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last_node;
	t_stack	*second_but_last_node;

	last_node = ft_stacklast(*stack);
	second_but_last_node = ft_stacksecondbutlast(*stack);
	second_but_last_node->next = NULL;
	ft_stackadd_front(stack, last_node);
}

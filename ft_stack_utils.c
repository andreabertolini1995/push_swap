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

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*last_node;

	if (lst == NULL)
		last_node = NULL;
	while (lst != NULL)
	{
		last_node = lst;
		lst = lst->next;
	}
	return (last_node);
}

t_stack	*ft_stacksecondbutlast(t_stack *lst)
{
	t_stack	*second_but_last_node;

	if (lst == NULL)
		second_but_last_node = NULL;
	while (lst->next != NULL)
	{
		second_but_last_node = lst;
		lst = lst->next;
	}
	return (second_but_last_node);
}

t_stack	*ft_stacknew(int data)
{
	t_stack	*tmp;

	tmp = malloc (sizeof(t_stack));
	if (tmp == NULL)
		return (NULL);
	tmp->data = data;
	tmp->next = NULL;
	tmp->changed = false;
	return (tmp);
}

void	remove_first_node(t_stack **stack)
{
	t_stack	*first_node;

	first_node = *stack;
	*stack = (*stack)->next;
	free(first_node);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	stack = NULL;
}

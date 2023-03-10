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

int	ft_stacksize(t_stack *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	if ((*lst) == NULL)
	{
		new->next = NULL;
		*lst = new;
	}
	else
	{
		last_node = ft_stacklast(*lst);
		last_node->next = new;
	}
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	if (lst != NULL)
	{
		if (*lst != NULL)
			new->next = *lst;
		*lst = new;
	}
}

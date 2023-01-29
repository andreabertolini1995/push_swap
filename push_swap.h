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

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

void    ft_stackadd_back(t_stack *lst, t_stack *new);
void	ft_stackadd_front(t_stack *lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack *ft_stacksecondbutlast(t_stack *lst);
t_stack	*ft_stacknew(int data);
int		ft_stacksize(t_stack *lst);

t_stack *swap(t_stack *stack);
t_stack *remove_first_node(t_stack *stack);
t_stack *push_add(t_stack *stack_a, t_stack *stack_b);
t_stack *rotate(t_stack *stack);
t_stack *reverse_rotate(t_stack *stack);

int     main(int argc, char **argv);

#endif

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

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "./libft/libft.h"
# include "./ft_printf/ft_printf.h"
# include <stdio.h>
#include <stdbool.h> // Double-check if we are allowed to import this library

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	bool 			changed;
	int				pos;
}	t_stack;

// Stack utils
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacksecondbutlast(t_stack *lst);
t_stack	*ft_stacknew(int data);
int		ft_stacksize(t_stack *lst);

// Operations allowed
void	swap(t_stack **stack);
void	remove_first_node(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

// Print functions (to delete before submission)
void	ft_print_stack_stats(t_stack *stack_a, t_stack *stack_b);
void	ft_print_list_data(t_stack *stack);
void	ft_print_array(int *arr, int malloc_size);
void	ft_print_rotations(int rotations_stack_a, int rev_rotations_stack_a, int rotations_stack_b, int rev_rotations_stack_b);

// Rotations and reverse rotations functions
int		calc_num_rotations_stack_a(t_stack **stack_a, int size, int number_to_push);
int		calc_num_rev_rotations_stack_a(int size, int rotations);
int		calc_num_rotations_stack_b(int number_to_push, int highest_lower, t_stack **stack_b);
int		calc_num_rev_rotations_stack_b(int number_to_push, int highest_lower, t_stack **stack_b);

// Operations in list
int		ft_max_in_list(t_stack *stack);
int		ft_min_in_list(t_stack *stack);
int		ft_tmp_min_in_list(t_stack *stack, int n);
int		ft_in_range(int n, int min, int max);
int		find_number_to_push(t_stack *stack_a, int *arr, int malloc_size, int size);
int		ft_highest_lower(int n, t_stack *stack_b);
int		find_position_in_list(t_stack *stack, int n);
int		find_position_in_changed_list(t_stack *stack, int n);
void	replace_data_in_list(t_stack **stack, int pos, int n);
void	put_higher_on_top(t_stack **stack_b);
void	push_everything_back(t_stack **stack_a, t_stack **stack_b);
int		ft_max(int a, int b);
int		ft_min(int a, int b);

// Cases
void	only_rotations(t_stack **stack_a, t_stack **stack_b, int rotations_stack_a, int rotations_stack_b);
void	only_reverse_rotations(t_stack **stack_a, t_stack **stack_b, int rev_rotations_stack_a, int rev_rotations_stack_b);
void	rotations_a_rev_rotations_b(t_stack **stack_a, t_stack **stack_b, int rotations_stack_a, int rev_rotations_stack_b);
void	rotations_b_rev_rotations_a(t_stack **stack_a, t_stack **stack_b, int rev_rotations_stack_a, int rotations_stack_b);

// Sort three and sort five functions
void	sort_three(t_stack **stack_a);
void	find_min_and_push(t_stack **stack_a, t_stack **stack_b, int pos_min);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack_a);

// Main and main function
void	sort_stack(t_stack **stack_a, t_stack **stack_b, int initial_size, int chunk_size);
int		main(int argc, char **argv);

#endif

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
# include <stdbool.h>
# include "./ft_printf/ft_printf.h"

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
	bool			changed;
}	t_stack;

// Stack utils
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *lst);
t_stack	*ft_stacksecondbutlast(t_stack *lst);
t_stack	*ft_stacknew(int data);
int		ft_stacksize(t_stack *lst);
void	remove_first_node(t_stack **stack);
void	free_stack(t_stack **stack);

// Operations allowed
void	swap(t_stack **stack);
void	push(t_stack **src, t_stack **dest);
void	rotate(t_stack **stack);
void	reverse_rotate(t_stack **stack);

// Print functions
void	ft_print_stack_stats(t_stack *stack_a, t_stack *stack_b);
void	ft_print_list_data(t_stack *stack);
void	ft_print_array(int *arr, int malloc_size);
void	ft_print_rotations(int rotations_stack_a, int rev_rotations_stack_a,
			int rotations_stack_b, int rev_rotations_stack_b);

// Rotations and reverse rotations functions
int		calc_num_rotations_stack_a(t_stack **stack_a,
			int size, int number_to_push);
int		calc_num_rev_rotations_stack_a(int size, int rotations);
int		calc_num_rotations_stack_b(int number_to_push,
			int highest_lower, t_stack **stack_b);
int		calc_num_rev_rotations_stack_b(int number_to_push,
			int highest_lower, t_stack **stack_b);
int		calc_min_num_operations(t_stack **stack_a,
			t_stack **stack_b, int number_to_push, int highest_lower);

// Operations in list
int		ft_max_in_list(t_stack *stack);
int		ft_min_in_list(t_stack *stack);
int		ft_tmp_min_in_list(t_stack *stack, int n);
int		ft_in_range(int n, int min, int max);
int		find_number_at_index(t_stack *stack_a, int index);
int		ft_highest_lower(int n, t_stack *stack_b);
int		find_position_in_list(t_stack *stack, int n);
int		find_position_in_changed_list(t_stack *stack, int n);
void	replace_data_in_list(t_stack **stack, int pos, int n);
void	put_higher_on_top(t_stack **stack_b);
void	push_everything_back(t_stack **stack_a, t_stack **stack_b);

// Utils
int		ft_max(int a, int b);
int		ft_min(int a, int b);
int		ft_in_range(int n, int min, int max);
int		ft_min_in_array(int **ops, int malloc_size);
int		ft_atoi(const char *str);

// Cases
void	only_rot(t_stack **stack_a, t_stack **stack_b,
			int rotations_stack_a, int rotations_stack_b);
void	only_reverse_rot(t_stack **stack_a, t_stack **stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b);
void	rot_a_rev_rot_b(t_stack **stack_a, t_stack **stack_b,
			int rotations_stack_a, int rev_rotations_stack_b);
void	rot_b_rev_rot_a(t_stack **stack_a, t_stack **stack_b,
			int rev_rotations_stack_a, int rotations_stack_b);

// Sort three and sort five functions
void	sort_three(t_stack **stack_a);
void	find_min_and_push(t_stack **stack_a, t_stack **stack_b, int pos_min);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_two(t_stack **stack_a);
void	sort_two_three_five(t_stack **stack_a,
			t_stack **stack_b, int input_numbers);

// Fill arrays
int		*fill_index_array(t_stack *stack_a, int chunk_threshold,
			int malloc_size);
int		**fill_ops_array(t_stack **stack_a, t_stack **stack_b,
			int *arr, int malloc_size);

// Loops
void	loop_and_rotate(t_stack **stack_a, int lim, char *str);
void	loop_and_reverse_rotate(t_stack **stack, int lim, char *str);
void	multiple_rotations(t_stack **stack_a, int *arr,
			int malloc_size, int size);

// Conditions
int		condition_1(int rotations_stack_a, int rotations_stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b);
int		condition_2(int rotations_stack_a, int rotations_stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b);
int		condition_3(int rotations_stack_a, int rotations_stack_b,
			int rev_rotations_stack_a, int rev_rotations_stack_b);

// Errors
int		count_occurences(t_stack *stack, int n);
void	error_handling(t_stack *stack);
int		ft_str_is_numeric(char *str);
void	check_input(int input_numbers, char **argv);

// Main
void	sort_stack(t_stack **stack_a, t_stack **stack_b,
			int initial_size, int chunk_size);
int		main(int argc, char **argv);

#endif

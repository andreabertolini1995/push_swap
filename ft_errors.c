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

int	count_occurences(t_stack *stack, int n)
{
	t_stack	*ptr;
	int		count;

	count = 0;
	ptr = stack;
	while (ptr != NULL)
	{
		if (n == ptr->data)
			count++;
		ptr = ptr->next;
	}
	return (count);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if ((str[i] < 48) || (str[i] > 57))
			return (0);
		i++;
	}
	return (1);
}

void	error_handling(t_stack *stack)
{
	t_stack	*ptr;

	ptr = stack;
	while (ptr != NULL)
	{
		if (count_occurences(stack, ptr->data) > 1)
		{
			ft_printf("Error\n");
			exit(0);
		}
		ptr = ptr->next;
	}
}

static int	limits_check(char *s1, char *s2, size_t i)
{
	if (ft_strlen(s1) > ft_strlen(s2))
		return (0);
	else if (ft_strlen(s1) == ft_strlen(s2))
	{
		while (i < ft_strlen(s1))
		{
			if (s1[i] < s2[i])
				return (1);
			else if (s1[i] > s2[i])
				return (0);
			else
				i++;
		}
	}
	return (1);
}

void	check_input(int input_numbers, char **argv)
{
	int	i;

	i = 1;
	while (i <= input_numbers)
	{
		if (argv[i][0] == '-')
		{
			if (!limits_check(argv[i], "-2147483648", 1))
			{
				ft_printf("Error\n");
				exit(0);
			}
		}
		else if (!limits_check(argv[i], "2147483647", 0)
			|| !ft_str_is_numeric(argv[i]))
		{
			ft_printf("Error\n");
			exit(0);
		}
		i++;
	}
}

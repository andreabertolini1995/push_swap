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

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	ft_min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

int	ft_in_range(int n, int min, int max)
{
	int	i;

	i = min;
	while (i <= max)
	{
		if (n == i)
			return (1);
		i++;
	}
	return (0);
}

int	ft_min_in_array(int **ops, int malloc_size)
{
	int	min;
	int	i;

	min = ops[0][1];
	i = 1;
	while (i < malloc_size)
	{
		if (ops[i][1] < min)
			min = ops[i][1];
		i++;
	}
	return (min);
}

int	ft_atoi(const char *str)
{
	int	sign;
	int	final_number;
	int	i;

	sign = 1;
	final_number = 0;
	i = 0;
	while (str[i] != '\0')
	{
		while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			i++;
		if (str[i] == '-' || str[i] == '+')
		{
			if (str[i] == '-')
				sign = -1;
			i++;
		}
		while ((str[i] >= '0') && (str[i] <= '9'))
		{
			final_number = final_number * 10 + (str[i] - 48);
			i++;
		}
		return (final_number * sign);
	}
	return (final_number * sign);
}

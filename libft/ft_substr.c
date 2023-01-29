/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abertoli <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:07:52 by abertoli          #+#    #+#             */
/*   Updated: 2022/10/27 15:07:53 by abertoli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_find_min(size_t a, size_t b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	substr = (char *) malloc (sizeof(char)
			* (ft_find_min(ft_strlen(s), len) + 1));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		if (start > ft_strlen(s) || s[start] == '\0')
		{
			substr[i] = '\0';
			return (substr);
		}
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

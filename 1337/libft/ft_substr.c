/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laghzal <laghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:25:06 by laghzal           #+#    #+#             */
/*   Updated: 2025/08/14 18:11:16 by laghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const	char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

char	*ft_substr(char	const *s, unsigned	int start, size_t len)
{
	size_t	i;
	size_t	len_t;
	char	*result;

	i = 0;
	if (!s)
		return (NULL);
	len_t = ft_strlen(s);
	if (start >= len_t)
	{
		result = malloc(1);
		if (!result)
			return (NULL);
		result[i] = '\0';
		return (result);
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i < len && s[start + i])
	{
		result[i] = s[start + i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

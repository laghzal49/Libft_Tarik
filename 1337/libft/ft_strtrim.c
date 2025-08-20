/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laghzal <laghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:25:02 by laghzal           #+#    #+#             */
/*   Updated: 2025/08/14 17:54:57 by laghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	in_set(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)// (123abcd123,123) == abcd
{
	char	*new;
	int		i;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s1);
	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[start] && in_set(s1[start], set))
		start++;
	while (start < end && in_set(s1[end - 1], set))
		end--;
	new = malloc(1 + end - start);
	if (!new)
		return (NULL);
	while (start < end)
		new[i++] = s1[start++];
	new[i] = '\0';
	return (new);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:24:46 by laghzal           #+#    #+#             */
/*   Updated: 2025/08/24 18:35:41 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_sep(char ch, char c)
{
	return (ch == c);
}

static int	word(const char *s, char c)
{
	int	inword;
	int	count;
	int	i;

	inword = 0;
	count = 0;
	i = 0;
	while (s[i])
	{
		if (inword == 0 && !is_sep(s[i], c))
		{
			count++;
			inword = 1;
		}
		if (inword == 1 && is_sep(s[i], c))
			inword = 0;
		i++;
	}
	return (count);
}

static char	*copy(const char *s, char sep)
{
	char	*mal;
	int		i;

	i = 0;
	while (s[i] && s[i] != sep)
		i++;
	mal = malloc(i + 1);
	if (!mal)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != sep)
	{
		mal[i] = s[i];
		i++;
	}
	mal[i] = '\0';
	return (mal);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!s || !*s)
		return (NULL);
	result = malloc(sizeof(char *) * (word(s, c) + 1));
	if (!result)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
			result[j++] = copy(s + i, c);
		while (s[i] && s[i] != c)
			i++;
	}
	result[j] = NULL;
	return (result);
}

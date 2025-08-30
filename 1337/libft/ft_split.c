/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:24:46 by laghzal           #+#    #+#             */
/*   Updated: 2025/08/30 18:37:41 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
		if (inword == 0 && s[i] != c)
		{
			count++;
			inword = 1;
		}
		if (inword == 1 && s[i] == c)
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

static void	free_split(char **arr, int j)
{
	while (j > 0)
		free(arr[--j]);
	free(arr);
}

static char	**fill_result(const char *s, char c, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] && s[i] != c)
		{
			result[j] = copy(s + i, c);
			if (!result[j])
			{
				free_split(result, j);
				return (NULL);
			}
			j++;
		}
		while (s[i] && s[i] != c)
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	int		words;

	if (!s)
		return (NULL);
	words = word(s, c);
	result = malloc(sizeof(char *) * (words + 1));
	if (!result)
		return (NULL);
	return (fill_result(s, c, result));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 17:24:46 by laghzal           #+#    #+#             */
/*   Updated: 2025/08/30 20:11:15 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(const char *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*extract_word(const char **s, char c)
{
	const char	*start;
	size_t		len;
	char		*word;

	start = *s;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	ft_memcpy(word, start, len);
	word[len] = '\0';
	*s += len;
	return (word);
}

static void	free_split(char **arr, size_t count)
{
	while (count > 0)
		free(arr[--count]);
	free(arr);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	word_count;
	size_t	i;

	if (!s)
		return (NULL);
	word_count = count_words(s, c);
	result = malloc(sizeof(char *) * (word_count + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s && i < word_count)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = extract_word(&s, c);
			if (!result[i])
				return (free_split(result, i), NULL);
			i++;
		}
	}
	return (result[i] = NULL, result);
}

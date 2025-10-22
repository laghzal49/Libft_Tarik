/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 12:25:12 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/19 09:56:16 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word(const char *s, char c)
{
	int	count;
	int	in;

	count = 0;
	in = 0;
	while (*s)
	{
		if (*s == c)
			in = 0;
		else if (in == 0)
		{
			count++;
			in = 1;
		}
		s++;
	}
	return (count);
}

static char	*extractw(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

static void	*fsplit(char **arr, size_t count)
{
	while (count > 0)
	{
		count--;
		free(arr[count]);
	}
	free(arr);
	return (NULL);
}

static char	**ft_fill_array(char **result, const char *s, char c, size_t count)
{
	size_t	i;

	i = 0;
	while (*s && i < count)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			result[i] = extractw(s, c);
			if (!result[i])
				return (fsplit(result, i));
			while (*s && *s != c)
				s++;
			i++;
		}
	}
	result[i] = NULL;
	return (result);
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	count;

	if (!s)
		return (NULL);
	count = word(s, c);
	result = malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	return (ft_fill_array(result, s, c, count));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 10:54:59 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/17 18:56:44 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_it(const char *set, const char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}	
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	i;
	char	*ptr;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_it(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_it(set, s1[end - 1]))
		end--;
	ptr = malloc((end - start) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (start < end)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:39:32 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/21 17:42:18 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(dst);
	if (size <= l)
		return (l + ft_strlen(src));
	i = 0;
	while (l + i + 1 < size && src[i])
	{
		dst[l + i] = src[i];
		i++;
	}
	dst[l+i] = '\0';
	return (i +l);
}

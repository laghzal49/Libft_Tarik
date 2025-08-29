/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:17:03 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/29 15:10:45 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*d;
	const unsigned char	*s;
	size_t				i;

	if (!dst && !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	slen;
	size_t	real_len;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start >= slen)
	{
		ptr = malloc(1);
		if (!ptr)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	real_len = len;
	if (real_len > slen - start)
		real_len = slen - start;
	ptr = malloc(real_len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, real_len);
	ptr[real_len] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	size_t	len1;
	size_t	len2;
	size_t	len;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_substr(s2, 0, ft_strlen(s2)));
	if (!s2)
		return (ft_substr(s1, 0, ft_strlen(s1)));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	len = len1 + len2;
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	ft_memcpy(p, s1, len1);
	ft_memcpy(p + len1, s2, len2);
	p[len] = '\0';
	return (p);
}

char	*ft_strchr(char const *s, int c)
{
	const char	*p;

	if (!s)
		return (NULL);
	p = s;
	while (*p)
	{
		if (*p == (char)c)
			return ((char *)p);
		p++;
	}
	if ((char)c == '\0')
		return ((char *)p);
	return (NULL);
}

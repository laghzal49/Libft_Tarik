/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 22:14:41 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/19 09:48:28 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	tlen;

	if (!s)
		return (NULL);
	tlen = ft_strlen(s);
	if (start >= tlen)
		return (ft_strdup(""));
	if (len > tlen - start)
		len = tlen - start;
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s + start, len);
	ptr[len] = '\0';
	return (ptr);
}

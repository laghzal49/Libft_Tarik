/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:38 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/30 20:55:10 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	unsigned char	find;

	if (!s)
		return (NULL);
	p = (unsigned char *)s;
	find = (unsigned char)c;
	while (n > 0)
	{
		if (*p == find)
			return ((void *)p);
		p++;
		n--;
	}
	return (NULL);
}

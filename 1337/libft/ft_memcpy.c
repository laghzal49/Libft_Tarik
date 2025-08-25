/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:28 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/25 19:13:52 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*s;

	if (!dest && !src)
		return (NULL);
	p = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (n)
	{
		*(p++) = *(s++);
		n--;
	}
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:28 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/24 18:50:45 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*p;
	char	*s;
	size_t	i;

	p = (char *)dest;
	s = (char *)src;
	if (!src || !dest)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	return (dest);
}

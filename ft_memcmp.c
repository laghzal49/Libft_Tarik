/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:16:23 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/19 11:54:30 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*ptr;
	unsigned char	*str;

	ptr = (unsigned char *)s1;
	str = (unsigned char *)s2;
	while (n--)
	{
		if (*ptr != *str)
			return (*ptr - *str);
		ptr++;
		str++;
	}
	return (0);
}

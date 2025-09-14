/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 16:28:42 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/18 14:10:03 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*ptr;
	int				len;

	ptr = (unsigned char *)s;
	len = ft_strlen(s);
	while (len >= 0)
	{
		if (ptr[len] == (unsigned char)c)
			return ((char *)&ptr[len]);
		len--;
	}
	return (NULL);
}

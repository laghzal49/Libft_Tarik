/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 19:38:11 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/19 10:48:50 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char		*ptr;
	size_t		i;

	i = ft_strlen(s1);
	ptr = (char *)malloc(i + 1);
	if (!ptr)
		return (NULL);
	ft_memcpy(ptr, s1, i + 1);
	return (ptr);
}

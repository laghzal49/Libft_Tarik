/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:39:45 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/21 17:42:18 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int	i;
	int	len;
	
	len = ft_strlen(s1) + 1;
	ptr = malloc(sizeof(char) * len);
	i = 0;
	if (!ptr)
		return (NULL);
	while(i < len)
	{
		ptr[i] = s1[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);

}

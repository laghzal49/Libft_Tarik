/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:41:02 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/21 17:42:19 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

void ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while(n--)
	{
		*ptr = 0;
		ptr++;
	}
}
void *ft_calloc(size_t nmemb, size_t size)
{
    void *ptr;
    size_t tsize;
    
    if (nmemb > 0 && size > 0 && nmemb * size / size != nmemb)
        return (NULL);
    tsize = nmemb * size;
    ptr = malloc(tsize);
    if (!ptr)
        return (NULL);
    ft_bzero(ptr, tsize);
    
    return (ptr);
}

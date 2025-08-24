/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <laaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:46 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/24 18:57:28 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_get_len(long long n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static void	ft_fill(char *p, long long num, size_t len)
{
	if (num == 0)
	{
		p[0] = '0';
		return ;
	}
	if (num < 0)
	{
		p[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		p[--len] = (num % 10) + '0';
		num /= 10;
	}
}

char	*ft_itoa(int n)
{
	long long	num;
	size_t		len;
	char		*p;

	num = n;
	len = ft_get_len(num);
	p = malloc(len + 1);
	if (!p)
		return (NULL);
	p[len] = '\0';
	ft_fill(p, num, len);
	return (p);
}

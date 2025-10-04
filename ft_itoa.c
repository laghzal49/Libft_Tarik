/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:42:46 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/17 19:12:15 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ilen(long num)
{
	size_t	len;

	len = 0;
	if (num < 0)
		len++;
	if (num == 0)
		len++;
	while (num != 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

static char	*alloc(long nbr, int i, char *str)
{
	if (nbr == 0)
		str[0] = '0';
	while (nbr != 0)
	{
		str[i] = ((nbr % 10) + 48);
		i--;
		nbr /= 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	int		len;
	char	*ptr;
	long	nbr;

	nbr = n;
	len = ilen(nbr);
	ptr = malloc(len + 1);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n < 0)
	{
		ptr[0] = '-';
		nbr *= -1;
	}
	ptr = alloc(nbr, len - 1, ptr);
	return (ptr);
}

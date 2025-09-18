/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 15:46:28 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/21 16:25:04 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_overf(long max, long result, int s)
{
	if (max > result && s > 0)
		return (-1);
	if (max > result && s < 0)
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	int		a;
	int		signe;
	long	result;
	long	max;

	a = 0;
	signe = 1;
	result = 0;
	while (str[a] == ' ' || (str[a] >= '\t' && str[a] <= '\r'))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			signe = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		max = result;
		result = result * 10 +(str[a] - 48);
		if (ft_overf(max, result, signe) != 1)
			return (ft_overf(max, result, signe));
		a++;
	}
	return (result * signe);
}

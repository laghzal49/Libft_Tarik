/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/21 17:40:08 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/21 17:42:18 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	c;
	num = n;
	if (num < 0)
	{
		write(fd,"-",1);
		num = -num;
	}
	if (num >= 10)
		ft_putnbr_fd(num / 10,fd);
	c = (num % 10) + '0';
	write(fd,&c,1);
}

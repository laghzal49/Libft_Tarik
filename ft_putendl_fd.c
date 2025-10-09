/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 21:56:30 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/19 09:49:39 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL)
		return ;
	while (*str)
	{
		write(fd, str, 1);
		str++;
	}
	write(fd, "\n", 1);
}

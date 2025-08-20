/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laghzal <laghzal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/14 23:20:49 by laghzal           #+#    #+#             */
/*   Updated: 2025/08/14 23:34:16 by laghzal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	explicit_bzero(void *s, size_t n)
{
	volatile unsigned char	*ptr;

	ptr = s;
	while (n)
	{
		ptr = 0;
		ptr++;
		n--;
	}
}

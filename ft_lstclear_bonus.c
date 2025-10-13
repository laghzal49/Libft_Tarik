/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:34:28 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/18 16:34:03 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*test;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		test = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = test;
	}
}

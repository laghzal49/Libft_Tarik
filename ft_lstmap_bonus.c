/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlaghzal <tlaghzal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 11:45:38 by tlaghzal          #+#    #+#             */
/*   Updated: 2025/10/19 11:55:27 by tlaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l_new;
	t_list	*n_node;
	void	*new_thing;

	if (!lst || !f || !del)
		return (NULL);
	l_new = NULL;
	while (lst)
	{
		new_thing = f(lst->content);
		n_node = ft_lstnew(new_thing);
		if (!n_node)
		{
			del(new_thing);
			ft_lstclear(&l_new, del);
			return (NULL);
		}
		ft_lstadd_back(&l_new, n_node);
		lst = lst->next;
	}
	return (l_new);
}

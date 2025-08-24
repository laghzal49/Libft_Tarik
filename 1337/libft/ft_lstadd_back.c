/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laaghzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 01:40:04 by laaghzal          #+#    #+#             */
/*   Updated: 2025/08/24 01:40:06 by laaghzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{
    t_list *last;
  if (!lst || !new)
    return;
  if (*lst == NULL)
    {
        *lst = new;
        return;
    }
  last = *lst;
  while (last->next)
    last = last->next;
  last->next = new;
}


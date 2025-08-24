#include "libft.h"

void del(void *c)
{
  free(c);
}
void ft_lstdelone(t_list *lst, void (*del)(void *))
{
  if (!lst || !del)
    return;
  del(lst->content);
  free(lst);
}

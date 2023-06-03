#include "libft.h"

void	ft_dlstclear(t_dlist **lst, void(*del)(void *))
{
	t_dlist *tmp;

	if (!lst || !(*lst))
		return ;
	tmp = *lst;
	while (*lst)
	{
		*lst = (*lst)->next;
		del(tmp->content);
		free(tmp);
		tmp = *lst;
	}
}
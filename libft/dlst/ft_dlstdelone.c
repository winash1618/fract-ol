#include "libft.h"

void	ft_dlstdelone(t_dlist *lst, void (*del)(void*))
{
	if (!lst)
		return ;
	del(lst->content);
	free(lst);
}
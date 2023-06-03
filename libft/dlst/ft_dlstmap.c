#include "libft.h"

t_dlist	*ft_dlstmap(t_dlist *lst, void *(*f)(void *), void (*del)(void *))
{
	t_dlist *new;

	if (!lst || !f)
		return (NULL);
	new = ft_dlstnew(f(lst->content));
	if (!new)
	{
		ft_dlstclear(&new, del);
		return (NULL);
	}
	new->next = ft_dlstmap(lst->next, f, del);
	return (new);
}
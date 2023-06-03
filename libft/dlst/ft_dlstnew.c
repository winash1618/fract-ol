#include "libft.h"

t_dlist	*ft_dlstnew(void *content)
{
	t_dlist	*new;

	new = (t_dlist *)malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->down = NULL;
	new->x = 0;
	new->y = 0;
	new->z = 0;
	new->c = 0;
	return (new);
}
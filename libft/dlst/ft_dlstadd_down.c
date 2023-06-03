#include "libft.h"

void	ft_dlstadd_down(t_dlist **olst, t_dlist *nlst)
{
	t_dlist *tmp;

	if (!olst || !nlst)
		return ;
	if (*olst == NULL)
	{
		*olst = nlst;
		return ;
	}
	tmp = *olst;
	while (tmp->down)
		tmp = tmp->down;
	tmp->down = nlst;
}

// int main()
// {
// 	t_dlist *olst;
// 	t_dlist *nlst;

// 	olst = (t_dlist *)malloc(sizeof(t_dlist));
// 	nlst = (t_dlist *)malloc(sizeof(t_dlist));
// 	ft_dlstadd_down(&olst, nlst);
// 	printf("%p\n", olst);
// 	printf("%p\n", olst->down);
// 	printf("%p\n", nlst);
// 	printf("%p\n", nlst->down);
// 	return (0);
// }

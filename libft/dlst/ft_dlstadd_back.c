#include "libft.h"

void	ft_dlstadd_back(t_dlist **olst, t_dlist *nlst)
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
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = nlst;
}

// int main()
// {
// 	t_dlist *olst;
// 	t_dlist *nlst;

// 	olst = (t_dlist *)malloc(sizeof(t_dlist));
// 	nlst = (t_dlist *)malloc(sizeof(t_dlist));
// 	ft_dlstadd_back(&olst, nlst);
// 	printf("%p\n", olst);
// 	printf("%p\n", olst->next);
// 	printf("%p\n", nlst);
// 	printf("%p\n", nlst->next);
// 	return (0);
// }
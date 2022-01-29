#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list));
	if (!cell)
		return (NULL);
	cell -> next = NULL;
	cell -> content = content;
	return (cell);
}

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*cell;

	if (new != NULL)
	{
		cell = *lst;
		if (cell == NULL)
			*lst = new;
		else
		{
			while (cell -> next != NULL)
				cell = cell -> next;
			cell -> next = new;
		}
	}
}

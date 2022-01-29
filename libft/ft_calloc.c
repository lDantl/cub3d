#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*mas;
	size_t	i;

	i = 0;
	mas = NULL;
	mas = malloc(size * count);
	if (!mas)
		return (NULL);
	while (i < (count * size))
	{
		mas[i] = 0;
		i++;
	}
	return ((void *)mas);
}

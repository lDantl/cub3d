#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*b;

	b = s;
	while (n--)
		*b++ = '\0';
}

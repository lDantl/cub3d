#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*d;

	d = (unsigned char *)arr;
	while (n--)
	{
		if (*d == (unsigned char)c)
			return (d);
		d++;
	}
	return (NULL);
}

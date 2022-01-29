#include "libft.h"

void	*ft_memccpy(void *dst, const void *s, int c, size_t n)
{
	unsigned int	i;
	char			*dest;
	char			*src;
	char			*ptr;

	dest = (char *)dst;
	src = (char *)s;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dest[i] = src[i];
		if (src[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}

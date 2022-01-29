#include "libft.h"

void	*ft_memcpy(void *dst, const void *s, size_t n)
{
	unsigned char	*dest;
	unsigned char	*src;
	size_t			i;

	if (!s && !dst)
		return (NULL);
	dest = (unsigned char *)dst;
	src = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

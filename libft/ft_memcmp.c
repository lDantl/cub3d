#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*dst;
	unsigned char	*str;
	int				i;

	dst = (unsigned char *)s1;
	str = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (dst[i] != str[i])
			return (dst[i] - str[i]);
		i++;
	}
	return (0);
}

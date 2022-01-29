#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	const char	*destination;
	const char	*source;
	size_t		x;
	size_t		dlen;

	destination = dst;
	source = src;
	x = size;
	while ((x-- != 0) && (*dst != '\0'))
		dst++;
	dlen = dst - destination;
	x = size - dlen;
	if (x-- == 0)
		return (dlen + ft_strlen(src));
	while (*src != '\0')
	{
		if (x != 0)
		{
			*dst++ = *src;
			x--;
		}
		src++;
	}
	*dst = '\0';
	return (dlen + (src - source));
}

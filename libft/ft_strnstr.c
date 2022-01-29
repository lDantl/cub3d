#include "libft.h"

char	*ft_strnstr(const char *hs, const char *nd, size_t len)
{
	size_t	i;
	size_t	n;

	i = 0;
	if (nd[0] == '\0')
		return ((char *)hs);
	while (hs[i] && i < len)
	{
		n = 0;
		while (hs[i + n] && nd[n] && (i + n) < len && hs[i + n] == nd[n])
		{
			n++;
			if (!nd[n])
				return ((char *)hs + i);
		}
		i++;
	}
	return (NULL);
}

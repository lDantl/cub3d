#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	i = ft_strlen(s1);
	s2 = malloc(sizeof(char) * (i + 1));
	if (!s2)
		return (NULL);
	s2[i] = '\0';
	i--;
	while (i >= 0)
	{
		s2[i] = s1[i];
		i--;
	}
	return (s2);
}

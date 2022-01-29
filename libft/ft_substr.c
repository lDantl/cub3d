#include "libft.h"

static char	*ft_strdup_ft(const char *s1)
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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	if (!s)
		return (NULL);
	if (len <= 0)
		return (ft_strdup_ft(""));
	if (ft_strlen(s) < start)
		return (ft_strdup_ft(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	while (s[start + i] && i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

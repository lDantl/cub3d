#include "libft.h"

static char	**ft_split_free(char **tab)
{
	unsigned int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (0);
}

static	size_t	ft_get_nb_strs(char const *s, char c)
{
	size_t	i;
	size_t	nb_strs;

	if (!s[0])
		return (0);
	i = 0;
	nb_strs = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			nb_strs++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		nb_strs++;
	return (nb_strs);
}

static void	ft_get_next_str(char **next_str, size_t *next_str_len, char c)
{
	size_t	i;

	*next_str += *next_str_len;
	*next_str_len = 0;
	i = 0;
	while (**next_str && **next_str == c)
		(*next_str)++;
	while ((*next_str)[i])
	{
		if ((*next_str)[i] == c)
			return ;
		(*next_str_len)++;
		i++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	**buf;
	char	*next_str;
	size_t	next_str_len;
	size_t	nb_strs;
	size_t	i;

	if (!s)
		return (NULL);
	nb_strs = ft_get_nb_strs(s, c);
	buf = (char **)malloc(sizeof(char *) * (nb_strs + 1));
	if (!buf)
		return (NULL);
	i = -1;
	next_str = (char *)s;
	next_str_len = 0;
	while (++i < nb_strs)
	{
		ft_get_next_str(&next_str, &next_str_len, c);
		buf[i] = (char *)malloc(sizeof(char) * (next_str_len + 1));
		if (!buf[i])
			return (ft_split_free(buf));
		ft_strlcpy(buf[i], next_str, (next_str_len + 1));
	}
	buf[i] = NULL;
	return (buf);
}

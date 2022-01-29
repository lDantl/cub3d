#include "get_next_line.h"

static int	value_return(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*strdup_for_line(char *str1)
{
	int		i;
	char	*str2;

	i = 0;
	if (!str1)
		return (0);
	while (str1[i] && str1[i] != '\n')
		i++;
	str2 = malloc(sizeof(char) * (i + 1));
	if (!str2)
		return (0);
	i = 0;
	while (str1[i] && str1[i] != '\n')
	{
		str2[i] = str1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

static char	*get_storage(char *storage)
{
	int		n;
	int		i;
	char	*str;

	i = 0;
	n = 0;
	if (!storage)
		return (0);
	while (storage[i] && storage[i] != '\n')
		i++;
	if (!storage[i])
	{
		free (storage);
		return (0);
	}
	str = malloc(sizeof(char) * ((ft_strlen(storage) - i) + 1));
	if (!str)
		return (0);
	while (storage[i])
		str[n++] = storage[++i];
	str[n] = '\0';
	free (storage);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*storage;
	int			byte_was_read;
	char		*trash;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (-1);
	byte_was_read = 1;
	if (!storage)
		storage = ft_strdup("");
	while (!value_return(storage) && byte_was_read != 0)
	{
		byte_was_read = read(fd, buf, BUFFER_SIZE);
		buf[byte_was_read] = '\0';
		trash = storage;
		storage = ft_strjoin(storage, buf);
		free (trash);
	}
	*line = strdup_for_line(storage);
	storage = get_storage(storage);
	if (byte_was_read)
		return (1);
	return (0);
}

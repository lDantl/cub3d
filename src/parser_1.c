/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:34:35 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:19:29 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_check_header_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->start_map = ft_only_map(data);
	if (data->start_map)
	{
		ft_parse_header(data);
		ft_valid_header(data->no, ".xpm");
		ft_valid_header(data->so, ".xpm");
		ft_valid_header(data->we, ".xpm");
		ft_valid_header(data->ea, ".xpm");
	}
}

void	copy_all_map(t_data *data)
{
	int	i;
	int	j;
	int	g;

	i = 0;
	j = 0;
	g = 0;
	while (i < data->count_str)
	{
		while (data->buffer[j] != '\n' && data->buffer[j] != '\0')
		{
			data->massiv[i][g] = data->buffer[j++];
			g++;
		}
		g = 0;
		j++;
		i++;
	}
	free (data->buffer);
}

void	memory_for_str(t_data *data)
{
	int	i;

	i = 0;
	data->massiv = (char **)malloc(sizeof(char *) * (data->count_str) + 1);
	if (!data->massiv)
		ft_error(3);
	while (i < data->count_str)
	{
		data->massiv[i] = (char *)malloc(sizeof(char *) * (data->len_str + 1));
		if (!data->massiv[i])
			ft_error(3);
		data->massiv[i][data->len_str] = '\0';
		i++;
	}
	data->massiv[i] = NULL;
}

void	copy_in_massive(t_data *data, char **argv)
{
	int		i;
	char	buff;
	int		fd;

	i = 0;
	fd = open (argv[1], O_RDONLY);
	while (read(fd, &buff, 1) > 0)
		i++;
	close (fd);
	data->buffer = (char *)malloc(sizeof(char) * (i + 1));
	if (!data->buffer)
		ft_error (3);
	fd = open (argv[1], O_RDONLY);
	read(fd, data->buffer, i);
	data->buffer[i] = '\0';
	close (fd);
}

void	read_map(char **argv, t_data *data)
{
	int		fd;
	char	*mass;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error(4);
	while (get_next_line(fd, &mass))
	{
		data->count_str++;
		data->len_str = ft_strlen(mass);
		if (data->long_str < (int)data->len_str)
			data->long_str = (int)data->len_str;
		free (mass);
	}
	data->count_str++;
	free (mass);
	close (fd);
}

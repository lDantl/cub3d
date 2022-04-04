/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:37:01 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:18:37 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	check_path_nswe(char *nswe)
{
	int		fd;
	char	*b;

	b = NULL;
	fd = open(nswe, O_RDONLY);
	if (fd == -1)
		ft_error(1);
	if (get_next_line(fd, &b) == -1)
		ft_error(7);
	free(b);
	close(fd);
}

void	parse_header_2(t_data *data, char **header)
{
	if (header && !ft_strncmp(header[0], "SO", 2) && header[1])
	{
		if (data->so != NULL)
			ft_error(1);
		data->so = ft_strdup(header[1]);
		check_path_nswe(data->so);
	}
	else if (header && !ft_strncmp(header[0], "C", 1) && header[1])
	{
		if (data->c != NULL || header[2])
			ft_error(1);
		data->c = ft_split(header[1], ',');
	}
	else if (header && !ft_strncmp(header[0], "F", 1) && header[1])
	{
		if (data->f != NULL || header[2])
			ft_error(1);
		data->f = ft_split(header[1], ',');
	}
	else
		ft_error(1);
}

int	parse_header_1(t_data *data, char **header)
{
	if (header && !ft_strncmp(header[0], "EA", 2) && header[1])
	{
		if (data->ea != NULL)
			ft_error(1);
		data->ea = ft_strdup(header[1]);
		check_path_nswe(data->ea);
		return (1);
	}
	else if (header && !ft_strncmp(header[0], "WE", 2) && header[1])
	{
		if (data->we != NULL)
			ft_error(1);
		data->we = ft_strdup(header[1]);
		check_path_nswe(data->we);
		return (1);
	}
	else if (header && !ft_strncmp(header[0], "NO", 2) && header[1])
	{
		if (data->no != NULL)
			ft_error(1);
		data->no = ft_strdup(header[1]);
		check_path_nswe(data->no);
		return (1);
	}
	return (0);
}

void	ft_parse_header(t_data *data)
{
	int		i;
	char	**header;

	i = -1;
	header = NULL;
	while (++i < data->start_map)
	{
		header = ft_split(data->massiv[i], ' ');
		if (header[0] == NULL)
			continue ;
		if (parse_header_1(data, header))
			continue ;
		parse_header_2(data, header);
		free_argv(header);
	}
}

int	ft_only_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->massiv[++i])
	{
		j = 0;
		while (data->massiv[i][j] == ' ')
			j++;
		if (data->massiv[i][j] == '0')
			return (0);
		if (data->massiv[i][j] == '1')
			return (i);
	}
	return (0);
}

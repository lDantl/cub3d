/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:12 by rdanica           #+#    #+#             */
/*   Updated: 2022/01/29 19:46:34 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	str_in_integer(t_data *data)
{
	data->cr = ft_atoi(data->c[0]);
	data->cg = ft_atoi(data->c[1]);
	data->cb = ft_atoi(data->c[2]);
	data->fr = ft_atoi(data->f[0]);
	data->fg = ft_atoi(data->f[1]);
	data->fb = ft_atoi(data->f[2]);
	if (!(data->cr >= 0 && data->cg >= 0 && data->cb >= 0
		&& data->fr >= 0 && data->fg >= 0 && data->fb >= 0
		&& data->cr <= 255 && data->cg <= 255 && data->cb <= 355
		&& data->fr <= 255 && data->fg <= 255 && data->fb <= 255))
		ft_error (1);
}

void	ft_valid_color(t_data *data)
{
	int	j;
	int	i;

	i = -1;
	while (data->f[++i])
	{
		j = -1;
		while (data->f[i][++j])
			if (!(data->f[i][j] >= '0' && data->f[i][j] <= '9'))
				ft_error (1);
	}
	i = -1;
	while (data->c[++i])
	{
		j = -1;
		while (data->c[i][++j])
			if (!(data->c[i][j] >= '0' && data->c[i][j] <= '9'))
				ft_error (1);
	}
}

void	ft_valid_header(char *s, char *d)
{
	int	i;

	i = ft_strlen(s) - ft_strlen(d);
	if (i <= 0)
		ft_error(7);
	while (s[i])
	{
		if (s[i] != *d)
			ft_error(7);
		d++;
		i++;
	}
}

void	ft_check_player_pos(t_data *data, int i, int j)
{
	while (data->massiv[++j])
	{
		i = -1;
		while (data->massiv[j][++i])
		{
			if (data->massiv[j][i] == 'N'
				|| (data->massiv[j][i] == 'E')
				|| (data->massiv[j][i] == 'W')
				|| (data->massiv[j][i] == 'S'))
			{
				if (data->pl_pos)
					ft_error (8);
				data->pl_pos = data->massiv[j][i];
			}
		}
	}
	if (data->pl_pos == '\0')
		ft_error (10);
}

void	ft_memset_new(char *b, char c, int len)
{
	int  i;
	char *b2;	
	if (len == 0)
		return ;
	i = 0;
	b2 = b;
	while (i != len)
	{
		b2[i] = c;
		i++;
	}
}

void	ft_lead_to_a_rectangle(t_data *data)
{
	char	**buffer;
	int		i;
	int		j;
	
	buffer = malloc(sizeof(char *) * (data->count_str - data->start_map + 3));
	buffer[0] = ft_calloc(sizeof(char), (data->long_str + 3));
	ft_memset_new(buffer[0], ' ', data->long_str + 2);
	i = 1;
	while (data->massiv[data->start_map])
	{
		buffer[i] = ft_calloc(sizeof(char), (data->long_str + 3));
		ft_memset_new(buffer[i], ' ', data->long_str + 2);
		j = -1;
		while (data->massiv[data->start_map][++j] != '\0')
			buffer[i][j + 1] = data->massiv[data->start_map][j];
		data->start_map++;
		i++;
	}
	buffer[i] = ft_calloc(sizeof(char), (data->long_str + 3));
	ft_memset_new(buffer[i], ' ', data->long_str + 2);
	buffer[i + 1] = NULL;
	free_argv(data->massiv);
	data->massiv = buffer;
}

void	ft_check_map_only(t_data *data, int i, int j)
{
	while (data->massiv[++j])
	{
		i = -1;
		while (data->massiv[j][++i])
		{
			if ((data->massiv[j][i] != '1') && (data->massiv[j][i] != ' ')
				&& (data->massiv[j][i] != '0') && (data->massiv[j][i] != 'N')
				&& (data->massiv[j][i] != 'E') && (data->massiv[j][i] != 'W')
				&& (data->massiv[j][i] != 'S') && (data->massiv[j][i] != '\0'))
					ft_error (1);
		}
	}
	j = -1;
	while (data->massiv[++j])
	{
		i = -1;
		while (data->massiv[j][++i])
			if (data->massiv[j][i] != '1' && data->massiv[j][i] != ' ')
				if ((data->massiv[j - 1][i] == ' ')
					|| (data->massiv[j + 1][i] == ' ')
					|| (data->massiv[j][i - 1] == ' ')
					|| (data->massiv[j][i + 1] == ' '))
					ft_error (1);
	}
}

void	ft_parse_header(t_data *data)
{
	int		i;
	char	**header;

	i = -1;
	header = NULL;
	while(++i < data->start_map)
	{
		header = ft_split(data->massiv[i], ' ');
		if (header[0] == NULL)
			continue ;			
		if (header && !ft_strncmp(header[0], "EA", 2) && header[1])
		{
			if (data->ea != NULL)
				ft_error(1);
			data->ea = ft_strdup(header[1]);
		}
		else if (header && !ft_strncmp(header[0], "WE", 2) && header[1])
		{
			if (data->we != NULL)
				ft_error(1);
			data->we = ft_strdup(header[1]);
		}
		 else if (header && !ft_strncmp(header[0], "NO", 2) && header[1])
		{
			if (data->no != NULL)
				ft_error(1);
			data->no = ft_strdup(header[1]);
		}
		else if (header && !ft_strncmp(header[0], "SO", 2) && header[1])
		{
			if (data->so != NULL)
				ft_error(1);
			data->so = ft_strdup(header[1]);
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
		free_argv(header);
	}
}

int	ft_only_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while(data->massiv[++i])
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

void	nool_struct(t_data *data)
{
	data->massiv = NULL;
	data->long_str = 0;
	data->len_str = 0;
	data->count_str = 0;
	data->flag = 1;
	data->pl_pos = '\0';
	data->ea = NULL;
	data->we = NULL;
	data->no = NULL;
	data->so = NULL;
	data->c = NULL;
	data->f = NULL;
	data->cr = 0;
	data->cg = 0;
	data->cb = 0;
	data->fr = 0;
	data->fg = 0;
	data->fb = 0;
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 2 && argc > 2)
		ft_error(2);
	ft_valid_header(argv[1], ".cub");
	nool_struct(&data);
	read_map(argv, &data);
	copy_in_massive(&data, argv);
	memory_for_str(&data);
	copy_all_map(&data);
	ft_check_header_map(&data);
	ft_lead_to_a_rectangle(&data);
	ft_check_map_only(&data, -1, -1);
	ft_check_player_pos(&data, -1, -1);
	ft_valid_color(&data);
	str_in_integer(&data);
    ft_print_result(&data);
	// while (1)
	// 	;
    return (0);
	// ft_map(&data);
	// ft_checker(argv, &data);
	// mlx_key_hook(data.mlx_win, &key_hook, &data);
	// mlx_hook(data.mlx_win, 17, (1L << 17), &ft_close, &data);
	// mlx_loop(data.mlx);
}

void    ft_print_result(t_data *data)
{
    int i;

    i = 0;
	printf("%s\n", data->ea);
	printf("%s\n", data->we);
	printf("%s\n", data->no);
	printf("%s\n", data->so);
	printf("%c\n", data->pl_pos);
	printf("%d\n", data->cr);
	printf("%d\n", data->cg);
	printf("%d\n", data->cb);
	printf("%d\n", data->fr);
	printf("%d\n", data->fg);
	printf("%d\n", data->fb);

	
    while (data->massiv[i])
    {
        printf("%s\n", data->massiv[i]);
        i++;
    }
}
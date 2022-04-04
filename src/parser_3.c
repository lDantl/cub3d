/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:48:22 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:13:56 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	int		i;
	char	*b2;

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
	int		sm;

	sm = data->start_map;
	buffer = malloc(sizeof(char *) * (data->count_str - sm + 3));
	buffer[0] = ft_calloc(sizeof(char), (data->long_str + 3));
	ft_memset_new(buffer[0], ' ', data->long_str + 2);
	i = 1;
	while (data->massiv[sm])
	{
		buffer[i] = ft_calloc(sizeof(char), (data->long_str + 3));
		ft_memset_new(buffer[i], ' ', data->long_str + 2);
		j = -1;
		while (data->massiv[sm][++j] != '\0')
			buffer[i][j + 1] = data->massiv[sm][j];
		sm++;
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_the_third_part.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:19:00 by ghumbert          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:50 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	record_player_dir(t_data **data, char c)
{
	if (c == 'E')
	{
		(*data)->lodev.dir_x = 0;
		(*data)->lodev.dir_y = 1;
		(*data)->lodev.plane_y = 0;
		(*data)->lodev.plane_x = 0.66;
	}
	else if (c == 'W')
	{
		(*data)->lodev.dir_x = 0;
		(*data)->lodev.dir_y = -1;
		(*data)->lodev.plane_y = 0;
		(*data)->lodev.plane_x = -0.66;
	}
}

void	init_player_dir(t_data **data, char c)
{
	if (c == 'N')
	{
		(*data)->lodev.dir_x = -1;
		(*data)->lodev.dir_y = 0;
		(*data)->lodev.plane_y = 0.66;
		(*data)->lodev.plane_x = 0;
	}
	else if (c == 'S')
	{
		(*data)->lodev.dir_x = 1;
		(*data)->lodev.dir_y = 0;
		(*data)->lodev.plane_y = -0.66;
		(*data)->lodev.plane_x = 0;
	}
	record_player_dir(data, c);
}

static int	is_player(char c, t_data **data, int x, int y)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		init_player_dir(data, c);
		(*data)->lodev.pos_x = y + 0.5;
		(*data)->lodev.pos_y = x + 0.5;
		(*data)->massiv[y][x] = '0';
		return (1);
	}
	return (0);
}

void	init_player(t_data *data)
{
	int		x;
	int		y;
	char	**map;

	y = 0;
	map = data->massiv;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (is_player(map[y][x], &data, x, y))
				break ;
			x++;
		}
		y++;
	}
}

void	print_all(t_data *data, int x, t_lodev *all)
{
	int	i;

	i = 0;
	while (i < all->draw_start)
	{
		my_mlx_pixel_put(data->img_win, x, i, data->floor);
		i++;
	}
	i = print_texture(data, all, i, x);
	while (i < HEIGHT)
	{
		my_mlx_pixel_put(data->img_win, x, i, data->cell);
		i++;
	}
}

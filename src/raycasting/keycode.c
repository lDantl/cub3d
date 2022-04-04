/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:56:55 by ghumbert          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:27 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	key_w(t_data **data, char **map, double moveSpeed)
{
	if ((map[(int)((*data)->lodev.pos_x + (*data)->lodev.dir_x
				* moveSpeed * 1.2)][(int)(*data)->lodev.pos_y]) == '0')
	(*data)->lodev.pos_x += (*data)->lodev.dir_x * moveSpeed;
	if (map[(int)(*data)->lodev.pos_x][(int)((*data)->lodev.pos_y
		+ (*data)->lodev.dir_y * moveSpeed * 1.2)] == '0')
	(*data)->lodev.pos_y += (*data)->lodev.dir_y * moveSpeed;
}

void	key_s(t_data **data, char **map, double moveSpeed)
{
	if (map[(int)((*data)->lodev.pos_x - (*data)->lodev.dir_x
			* moveSpeed * 1.2)][(int)(*data)->lodev.pos_y] == '0')
	(*data)->lodev.pos_x -= (*data)->lodev.dir_x * moveSpeed;
	if (map[(int)((*data)->lodev.pos_x)][(int)((*data)->lodev.pos_y
		- (*data)->lodev.dir_y * moveSpeed * 1.2)] == '0')
	(*data)->lodev.pos_y -= (*data)->lodev.dir_y * moveSpeed;
}

void	key_d(t_data **data, char **map, double moveSpeed)
{
	if (map[(int)((*data)->lodev.pos_x + (*data)->lodev.dir_y
			* moveSpeed * 1.2)][(int)((*data)->lodev.pos_y)] == '0')
		(*data)->lodev.pos_x += (*data)->lodev.dir_y * moveSpeed;
	if (map[(int)((*data)->lodev.pos_x)][(int)((*data)->lodev.pos_y
			- (*data)->lodev.dir_x * moveSpeed * 1.2)] == '0')
		(*data)->lodev.pos_y -= (*data)->lodev.dir_x * moveSpeed;
}

void	key_a(t_data **data, char **map, double moveSpeed)
{
	if ((map[(int)((*data)->lodev.pos_x - (*data)->lodev.dir_y
				* moveSpeed * 1.2)][(int)(*data)->lodev.pos_y]) == '0')
		(*data)->lodev.pos_x -= (*data)->lodev.dir_y * moveSpeed;
	if (map[(int)(*data)->lodev.pos_x][(int)((*data)->lodev.pos_y
			+ (*data)->lodev.dir_x * moveSpeed * 1.2)] == '0')
		(*data)->lodev.pos_y += (*data)->lodev.dir_x * moveSpeed;
}

void	key_rl(t_data **data, double olddir_x, double oldplane_x, int keycode)
{
	double	rotspeed;

	rotspeed = ROTSPEED;
	if (keycode == ARROW_RIGHT)
	{
		(*data)->lodev.dir_x = (*data)->lodev.dir_x * cos(-rotspeed)
			- (*data)->lodev.dir_y * sin(-rotspeed);
		(*data)->lodev.dir_y = olddir_x * sin(-rotspeed)
			+ (*data)->lodev.dir_y * cos(-rotspeed);
		(*data)->lodev.plane_x = (*data)->lodev.plane_x
			* cos(-rotspeed) - (*data)->lodev.plane_y * sin(-rotspeed);
		(*data)->lodev.plane_y = oldplane_x * sin(-rotspeed)
			+ (*data)->lodev.plane_y * cos(-rotspeed);
	}
	else if (keycode == ARROW_LEFT)
	{
		(*data)->lodev.dir_x = (*data)->lodev.dir_x * cos(rotspeed)
			- (*data)->lodev.dir_y * sin(rotspeed);
		(*data)->lodev.dir_y = olddir_x * sin(rotspeed)
			+ (*data)->lodev.dir_y * cos(rotspeed);
		(*data)->lodev.plane_x = (*data)->lodev.plane_x * cos(rotspeed)
			- (*data)->lodev.plane_y * sin(rotspeed);
		(*data)->lodev.plane_y = oldplane_x * sin(rotspeed)
			+ (*data)->lodev.plane_y * cos(rotspeed);
	}
}

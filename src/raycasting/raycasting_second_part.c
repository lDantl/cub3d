/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_second_part.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:18:08 by ghumbert          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:43 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	step1(t_lodev *all, t_data *data, int x)
{
	(void)data;
	all->camera_x = 2 * x / (double)WIDTH - 1;
	all->raydir_x = all->dir_x + all->plane_x * all->camera_x;
	all->raydir_y = all->dir_y + all->plane_y * all->camera_x;
	all->map_x = (int)all->pos_x;
	all->map_y = (int)all->pos_y;
	all->delta_dist_x = sqrt(1 + (all->raydir_y * all->raydir_y)
			/ (all->raydir_x * all->raydir_x));
	all->delta_dist_y = sqrt(1 + (all->raydir_x * all->raydir_x)
			/ (all->raydir_y * all->raydir_y));
	all->hit = 0;
}

void	step2(t_lodev *all, t_data *data)
{
	(void)data;
	if (all->raydir_x < 0)
	{
		all->step_x = -1;
		all->side_dist_x = (all->pos_x - all->map_x) * all->delta_dist_x;
	}
	else
	{
		all->step_x = 1;
		all->side_dist_x = (all->map_x + 1.0 - all->pos_x) * all->delta_dist_x;
	}
	if (all->raydir_y < 0)
	{
		all->step_y = -1;
		all->side_dist_y = (all->pos_y - all->map_y) * all->delta_dist_y;
	}
	else
	{
		all->step_y = 1;
		all->side_dist_y = (all->map_y + 1.0 - all->pos_y) * all->delta_dist_y;
	}
}

void	step3(t_lodev *all, t_data *data)
{
	while (all->hit == 0)
	{
		if (all->side_dist_x < all->side_dist_y)
		{
			all->side_dist_x += all->delta_dist_x;
			all->map_x += all->step_x;
			all->side = 0;
		}
		else
		{
			all->side_dist_y += all->delta_dist_y;
			all->map_y += all->step_y;
			all->side = 1;
		}
		if (data->massiv[all->map_x][all->map_y] == '1')
			all->hit = 1;
	}
	if (all->side == 0)
		all->perp_wall_dist = (all->map_x - all->pos_x
				+ (1 - all->step_x) / 2) / all->raydir_x;
	else
		all->perp_wall_dist = (all->map_y - all->pos_y
				+ (1 - all->step_y) / 2) / all->raydir_y;
}

void	step4(t_lodev *all, t_data *data)
{
	(void)data;
	all->line_height = (int)(HEIGHT / all->perp_wall_dist);
	all->draw_start = -all->line_height / 2 + HEIGHT / 2;
	if (all->draw_start < 0)
		all->draw_start = 0;
	all->draw_end = all->line_height / 2 + HEIGHT / 2;
	if (all->draw_end >= HEIGHT)
		all->draw_end = HEIGHT - 1;
	if (all->side == 0)
		all->wall_x = all->pos_y + all->perp_wall_dist * all->raydir_y;
	else
		all->wall_x = all->pos_x + all->perp_wall_dist * all->raydir_x;
	all->wall_x -= floor ((all->wall_x));
	all->tex_x = (int)(all->wall_x * (double)TEX_WIDTH);
	if (all->side == 0 && all->raydir_x > 0)
		all->tex_x = TEX_WIDTH - all->tex_x - 1;
	if (all->side == 1 && all->raydir_y < 0)
		all->tex_x = TEX_WIDTH - all->tex_x - 1;
	all->step = 1.0 * TEX_HEIGHT / all->line_height;
	all->tex_pos = (all->draw_start - HEIGHT
			/ 2 + all->line_height / 2) * all->step;
}

void	*output(t_data *data)
{
	int	x;

	x = 0;
	init_lodev(&data->lodev);
	while (x < WIDTH)
	{
		step1(&data->lodev, data, x);
		step2(&data->lodev, data);
		step3(&data->lodev, data);
		step4(&data->lodev, data);
		print_all(data, x, &data->lodev);
		x++;
	}
	image_to_image_cp(data->img_win, &data->img_map, point_set(0, 0));
	mlx_put_image_to_window(data->img_win->mlx, data->img_win->win,
		data->img_win->img, 0, 0);
	return (NULL);
}

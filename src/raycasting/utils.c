/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 13:35:38 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:06:50 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_lodev(t_lodev *all)
{
	all->camera_x = 0;
	all->raydir_x = 0;
	all->raydir_y = 0;
	all->map_x = 0;
	all->map_y = 0;
	all->side_dist_x = 0;
	all->side_dist_y = 0;
	all->delta_dist_x = 0;
	all->delta_dist_y = 0;
	all->perp_wall_dist = 0;
	all->step_x = 0;
	all->step_y = 0;
	all->hit = 0;
	all->side = 0;
	all->line_height = 0;
	all->draw_start = 0;
	all->draw_end = 0;
	all->wall_x = 0;
	all->tex_x = 0;
	all->step = 0;
	all->tex_pos = 0;
}

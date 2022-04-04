/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_fill_image.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:08:03 by ghumbert          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:33 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	vlen_map(char **maps)
{
	int	v;
	int	h;
	int	max;

	v = -1;
	h = -1;
	max = -1;
	while (maps[++v])
	{
		while (maps[v][++h])
			;
		if (max < h)
			max = h;
		h = -1;
	}
	if (v > max)
		max = v;
	return (max);
}

void	fill_big_pixel(t_win img, t_point pnt, int v, int color)
{
	t_point	to_p;

	to_p.x = pnt.x + v;
	to_p.y = pnt.y + v;
	while (pnt.y < to_p.y && pnt.y >= 0 && pnt.y <= img.size_img.y)
	{
		while (pnt.x < to_p.x && pnt.x >= 0 && pnt.x <= img.size_img.x)
		{
			my_mlx_pixel_put(&img, pnt.x, pnt.y, color);
			pnt.x++;
		}
		pnt.x = to_p.x - v;
		pnt.y++;
	}
}

void	map_fill_img(t_win img_map, char **maps)
{
	t_point	point;
	t_point	in_pix_coord;
	int		size_block;
	int		maxyx;

	point.x = 0;
	fill_big_pixel(img_map, point, 9999, 0x0);
	maxyx = img_map.size_img.x;
	if (img_map.size_img.y > img_map.size_img.x)
		maxyx = img_map.size_img.y;
	size_block = maxyx / vlen_map(maps);
	point.y = -1;
	while (maps[++point.y])
	{
		point.x = -1;
		while (maps[point.y][++point.x])
		{
			if (maps[point.y][point.x] == '1')
			{
				in_pix_coord.x = point.x * size_block;
				in_pix_coord.y = point.y * size_block;
				fill_big_pixel(img_map, in_pix_coord, size_block, 0x00552233);
			}
		}
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:18:15 by ghumbert          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:56 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_l + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	color_pixel_texture(t_win *img, int i, int j)
{
	char			*adr;
	unsigned int	color;

	adr = img->addr + (j * img->line_l + i * (img->bpp / 8));
	color = *(unsigned int *)adr;
	return (color);
}

void static	get_color_texure(t_data *data, int ***color, char *way)
{
	int		w;
	int		h;
	int		i;
	int		j;
	t_win	img;

	i = -1;
	img.img = mlx_xpm_file_to_image(data->img_win->mlx, way, &w, &h);
	if (!img.img)
		ft_error(9);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.line_l, &img.en);
	(*color) = malloc(sizeof(int *) * w);
	if (!(*color))
		ft_error(3);
	while (++i < TEX_WIDTH)
	{
		j = -1;
		(*color)[i] = malloc(sizeof(int) * h);
		while (++j < TEX_HEIGHT)
			(*color)[i][j] = color_pixel_texture(&img, i, j);
	}
}

void	init_texture(t_data *data)
{
	get_color_texure(data, &data->nor, data->no);
	get_color_texure(data, &data->sou, data->so);
	get_color_texure(data, &data->wes, data->we);
	get_color_texure(data, &data->eas, data->ea);
}

int	print_texture(t_data *data, t_lodev *all, int i, int x)
{
	int	color;
	int	tex_y;

	while (i <= all->draw_end)
	{
		tex_y = (int) data->lodev.tex_pos & (TEX_HEIGHT - 1);
		data->lodev.tex_pos += data->lodev.step;
		if (all->side == 1)
		{
			if (all->step_y == -1)
				color = data->wes[data->lodev.tex_x][tex_y];
			else
				color = data->eas[data->lodev.tex_x][tex_y];
		}
		else
		{
			if (all->step_x == -1)
				color = data->nor[data->lodev.tex_x][tex_y];
			else
				color = data->sou[data->lodev.tex_x][tex_y];
		}
		my_mlx_pixel_put(data->img_win, x, i, color);
		i++;
	}
	return (i);
}

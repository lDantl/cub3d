/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 13:26:47 by ghumbert          #+#    #+#             */
/*   Updated: 2022/04/04 13:32:12 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_win	image_create(int x, int y, void *mlx_ptr)
{
	t_win	image;

	image.img = mlx_new_image(mlx_ptr, x, y);
	image.addr = mlx_get_data_addr(image.img, &image.bpp, \
		&image.line_l, &image.en);
	image.mlx = mlx_ptr;
	image.win = NULL;
	image.size_img.x = x;
	image.size_img.y = y;
	return (image);
}

t_win	*new_image_create(int x, int y, void *mlx_ptr)
{
	t_win	*image;

	image = malloc(sizeof(t_win));
	if (!image)
		exit (1);
	image->img = mlx_new_image(mlx_ptr, x, y);
	image->addr = mlx_get_data_addr(image->img, &image->bpp, &image->line_l,
			&image->en);
	image->mlx = mlx_ptr;
	image->win = NULL;
	image->size_img.x = x;
	image->size_img.y = y;
	return (image);
}

// закрашиваю один пиксель на изображении
void	pixel_put(t_win *img, t_point	p, unsigned int colour)
{
	char	*dst;

	if (p.x < 0 || p.x >= img->size_img.x || p.y < 0 || p.y >= img->size_img.y)
		return ;
	dst = img->addr + ((p.y * img->line_l) + (p.x * (img->bpp / 8)));
	*(unsigned int *)dst = colour;
}

// Получаю пиксель из изображения
size_t	pixel_get(t_win *img, t_point p)
{
	void			*dst;
	unsigned int	ret;

	if (p.x < 0 || p.x >= img->size_img.x || p.y < 0 || p.y >= img->size_img.y)
		return (0xFF000000);
	dst = img->addr + ((p.y * img->line_l) + (p.x * (img->bpp / 8)));
	ret = *(unsigned int *)dst;
	return (ret);
}

void	image_to_image_cp(t_win *dst, t_win *src, t_point position)
{
	t_point	i;
	t_point	tmp;
	int		color;

	i.y = -1;
	i.x = -1;
	while (++i.y < src->size_img.y)
	{
		while (++i.x < src->size_img.x)
		{
			tmp.x = i.x + position.x;
			tmp.y = i.y + position.y;
			color = pixel_get(src, i);
			if (color == 0x0)
				continue ;
			pixel_put(dst, tmp, color);
		}
		i.x = -1;
	}
}

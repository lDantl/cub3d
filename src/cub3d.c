/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 18:32:46 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:21:16 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	keycode(int keycode, t_data **cub)
{
	char	**map;
	double	move_speed;
	double	old_dir_x;
	double	old_plane_x;

	map = (*cub)->massiv;
	move_speed = 0.11;
	old_dir_x = (*cub)->lodev.dir_x;
	old_plane_x = (*cub)->lodev.plane_x;
	if (keycode == ESC)
		exit(0);
	if (keycode == KEY_W)
		key_w(cub, map, move_speed);
	if (keycode == KEY_S)
		key_s(cub, map, move_speed);
	if (keycode == KEY_D)
		key_d(cub, map, move_speed);
	if (keycode == KEY_A)
		key_a(cub, map, move_speed);
	else if (keycode == ARROW_RIGHT || keycode == ARROW_LEFT)
		key_rl(cub, old_dir_x, old_plane_x, keycode);
	return (0);
}

void	raycasting(t_data *data)
{
	init_player(data);
	data->img_win = (t_win *)malloc(sizeof(t_win));
	data->img_win->mlx = mlx_init();
	data->img_win->win = mlx_new_window(data->img_win->mlx, WIDTH, HEIGHT,
			"CUB3D\n");
	data->img_win->img = mlx_new_image(data->img_win->mlx, WIDTH, HEIGHT);
	data->img_win->addr = mlx_get_data_addr(data->img_win->img,
			&data->img_win->bpp, &data->img_win->line_l, &data->img_win->en);
	data->img_win->size_img.y = HEIGHT;
	data->img_win->size_img.x = WIDTH;
	init_texture(data);
	mlx_loop_hook(data->img_win->mlx, (void *)output, data);
	mlx_hook(data->img_win->win, 2, 1L << 0, keycode, &data);
	mlx_hook(data->img_win->win, 17, 1L << 2, close_all, &data);
	mlx_loop(data->img_win->mlx);
}

int	parser(char **argv, t_data *data)
{
	ft_valid_header(argv[1], ".cub");
	read_map(argv, data);
	copy_in_massive(data, argv);
	memory_for_str(data);
	copy_all_map(data);
	ft_check_header_map(data);
	ft_lead_to_a_rectangle(data);
	ft_check_map_only(data, -1, -1);
	ft_check_player_pos(data, -1, -1);
	ft_valid_color(data);
	str_in_integer(data);
	data->floor = create_trgb(0, data->fr, data->fg, data->fb);
	data->cell = create_trgb(0, data->cr, data->cg, data->cb);
	return (1);
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
	nool_struct(&data);
	if (!parser(argv, &data))
		return (1);
	raycasting(&data);
	return (0);
}

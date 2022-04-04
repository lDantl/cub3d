/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:21 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:23:39 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include "../libft/libft.h"
# include "../minilibx_opengl_20191021/mlx.h"

# define HEIGHT 1080
# define WIDTH 1920

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

# define ARROW_UP 126
# define ARROW_DOWN 125
# define ARROW_LEFT 123
# define ARROW_RIGHT 124

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define ESC 53

# define TURN 0.05
# define ROTSPEED 0.055

typedef struct s_point
{
	int		x;
	int		y;
}	t_point;

typedef struct s_win
{
	void	*mlx;
	void	*win;
	void	*img;
	void	*addr;
	int		line_l;
	int		bpp;
	int		en;
	t_point	size_img;
}t_win;

typedef struct s_lodev
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	raydir_x;
	double	raydir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
	int		tex_x;
	double	step;
	double	tex_pos;
}				t_lodev;

typedef struct s_data {
	char				**massiv;
	int					long_str;
	int					len_str;
	int					count_str;
	char				pl_pos;
	char				*buffer;
	int					flag;
	int					start_map;
	char				*ea;
	char				*we;
	char				*no;
	char				*so;
	char				**c;
	char				**f;
	int					floor;
	int					cell;
	int					**nor;
	int					**sou;
	int					**wes;
	int					**eas;
	int					cr;
	int					cg;
	int					cb;
	int					fr;
	int					fg;
	int					fb;
	struct s_lodev		lodev;
	void				*mlx;
	void				*mlx_win;
	void				*img;
	void				*adr;
	t_win				*img_win;
	t_win				img_map;
}				t_data;

int		main(int argc, char **argv);
void	nool_struct(t_data *data);
int		parser(char **argv, t_data *data);
void	read_map(char **argv, t_data *data);
void	copy_in_massive(t_data *data, char **argv);
void	memory_for_str(t_data *data);
void	copy_all_map(t_data *data);
void	ft_check_header_map(t_data *data);
int		ft_only_map(t_data *data);
void	ft_parse_header(t_data *data);
void	ft_check_map_only(t_data *data, int i, int j);
void	ft_lead_to_a_rectangle(t_data *data);
void	ft_memset_new(char *b, char c, int len);
void	ft_check_player_pos(t_data *data, int i, int j);
void	ft_valid_header(char *s, char *d);
void	ft_valid_color(t_data *data);
void	str_in_integer(t_data *data);
int		close_all(t_data *data);
int		create_trgb(int t, int r, int g, int b);

void	ft_error(int i);
void	free_argv(char **argv);
void	key_w(t_data **data, char **map, double moveSpeed);
void	key_s(t_data **data, char **map, double moveSpeed);
void	key_d(t_data **data, char **map, double moveSpeed);
void	key_a(t_data **data, char **map, double moveSpeed);
void	key_rl(t_data **data, double olddir_x, double oldplane_x, int keycode);

void	raycasting(t_data *data);
void	init_texture(t_data *data);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);

void	*output(t_data *data);
void	step1(t_lodev *all, t_data *data, int x);
void	step2(t_lodev *all, t_data *data);
void	step3(t_lodev *all, t_data *data);
void	step4(t_lodev *all, t_data *data);
void	init_player(t_data *data);
t_point	point_set(int x, int y);
void	image_to_image_cp(t_win *dst, t_win *src, t_point position);
void	init_lodev(t_lodev *all);

void	print_all(t_data *data, int x, t_lodev *all);
int		keycode(int keycode, t_data **data);
int		print_texture(t_data *data, t_lodev *all, int i, int x);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:21 by rdanica           #+#    #+#             */
/*   Updated: 2022/01/29 19:29:13 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include "../gnl/get_next_line.h"
# include"../libft/libft.h"

# define HEIGHT 1080
# define WIDTH 1920

# define TEX_WIDTH 64
# define TEX_HEIGHT 64

typedef struct s_data {
	char	**massiv;	
	int		long_str;
	int		len_str;
	int		count_str;
	char	pl_pos;
	char	*buffer;
	int		flag;
	int		start_map;
	char	*ea;
	char	*we;
	char	*no;
	char	*so;
	char	**c;
	char	**f;
	int		cr;
	int		cg;
	int		cb;
	int		fr;
	int		fg;
	int		fb;
	
	
	
}				t_data;

int     main(int argc, char **argv);
void	ft_error(int i);
void    ft_print_result(t_data *data);
void	free_argv(char **argv);

#endif
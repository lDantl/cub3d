/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 19:50:30 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/04 15:11:31 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	str_in_integer(t_data *data)
{
	data->cr = ft_atoi(data->c[0]);
	data->cg = ft_atoi(data->c[1]);
	data->cb = ft_atoi(data->c[2]);
	data->fr = ft_atoi(data->f[0]);
	data->fg = ft_atoi(data->f[1]);
	data->fb = ft_atoi(data->f[2]);
	if (!(data->cr >= 0 && data->cg >= 0 && data->cb >= 0
			&& data->fr >= 0 && data->fg >= 0 && data->fb >= 0
			&& data->cr <= 255 && data->cg <= 255 && data->cb <= 355
			&& data->fr <= 255 && data->fg <= 255 && data->fb <= 255))
		ft_error (1);
}

void	ft_valid_color(t_data *data)
{
	int	j;
	int	i;

	i = -1;
	while (data->f[++i])
	{
		j = -1;
		while (data->f[i][++j])
			if (!(data->f[i][j] >= '0' && data->f[i][j] <= '9'))
				ft_error (1);
	}
	i = -1;
	while (data->c[++i])
	{
		j = -1;
		while (data->c[i][++j])
			if (!(data->c[i][j] >= '0' && data->c[i][j] <= '9'))
				ft_error (1);
	}
}

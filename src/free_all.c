/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:16:47 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/03 20:16:04 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	close_all(t_data *data)
{
	(void)data;
	exit(0);
	return (0);
}

void	free_str(char *string_free)
{
	if (string_free)
		free(string_free);
}

void	free_argv(char **argv)
{
	int	i;

	i = -1;
	if (argv && *argv != '\0')
	{
		if (*argv)
			while (argv[++i])
				free_str(argv[i]);
	}
	if (argv)
		free(argv);
}

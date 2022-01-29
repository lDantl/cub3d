/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 12:16:47 by rdanica           #+#    #+#             */
/*   Updated: 2022/01/27 14:22:28 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

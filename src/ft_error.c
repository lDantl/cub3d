/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rdanica <rdanica@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 10:27:25 by rdanica           #+#    #+#             */
/*   Updated: 2022/04/03 20:16:08 by rdanica          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_error(int i)
{
	if (i == 1)
		printf("\033[0;31mError: maps not valid\nMAPS: KO\n");
	else if (i == 2)
		printf("\033[0;31mError: many arguments\n");
	else if (i == 3)
		printf("\033[0;31mError: malloc\n");
	else if (i == 4)
		printf("\033[0;31mError: File not found\n");
	else if (i == 5)
		printf("\033[0;31mError: Bad textures\nFILE: KO\n");
	else if (i == 6)
		printf("\033[0;31mError: Exceeds the range\nFILE: KO\n");
	else if (i == 7)
		printf("\033[0;31mError: Invalid file extension\nFILE: KO\n");
	else if (i == 8)
		printf("\033[0;31mError: Many players\nFILE: KO\n");
	else if (i == 9)
		printf("\033[0;31mError: xpm!\nFILE: KO\n");
	else if (i == 10)
		printf("\033[0;31mError: there are no players!\nFILE: KO\n");
	exit (1);
}

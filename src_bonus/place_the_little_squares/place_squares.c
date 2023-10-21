/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_squares.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:43:40 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/06 10:50:51 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D.h"

void	place_squares(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->nb_line)
	{
		j = -1;
		while (++j < cub->nb_cols)
		{
			if (cub->map[i][j] == SPAWN)
			{
				cub->cam->x = i + 0.5;
				cub->cam->y = j + 0.5;
			}
		}
	}
	cub->fork_ambiance = fork();
	if (cub->fork_ambiance == 0)
	{
		system("afplay -v 1 -q 1 ./ressources/ambiance.mp3");
		exit(0);
	}
}

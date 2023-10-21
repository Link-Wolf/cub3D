/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_squares.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 15:43:40 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/28 15:33:26 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

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
}

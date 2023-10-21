/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 10:16:14 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 10:20:17 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/check3D.h"

int	check_map_plus(t_cub *cub, int i, int j, int *spawn)
{
	if (cub->map[i][j] == 18 && (j + 1 >= cub->nb_line - 1 || j == 0
		|| cub->map[i][j + 1] != WALL || cub->map[i][j - 1] != WALL))
	{
		cub->check->err_code = DOOR_WITHOUT_WALL;
		return (-1);
	}
	if (cub->map[i][j] == 8 && (i + 1 >= cub->nb_cols - 1 || i == 0
		|| cub->map[i + 1][j] != WALL || cub->map[i - 1][j] != WALL))
	{
		cub->check->err_code = DOOR_WITHOUT_WALL;
		return (-1);
	}
	if (cub->map[i][j] == SPAWN && *spawn >= 1)
		cub->check->err_code = DUP_SPAWN_INVALID_ELEM;
	if (cub->map[i][j] == SPAWN && *spawn >= 1)
		return (-1);
	return (0);
}

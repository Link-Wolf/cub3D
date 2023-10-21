/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:09:09 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 14:11:27 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

void	update_frames(t_cub *cub)
{
	int	i;
	int	j;

	if (cub->sophie_itr > 6)
	{
		cub->sophie_trigger = 0;
		tini_image(cub);
		tini(cub);
	}
	i = -1;
	while (++i < cub->nb_line)
	{
		j = -1;
		while (++j < cub->nb_cols)
		{
			if (cub->map[i][j] == EW_OPENING && cub->indexator)
				cub->map[i][j] = EW_OPEN;
			else if (cub->map[i][j] == EW_CLOSING && cub->indexator)
				cub->map[i][j] = EW_CLOSE;
			else if (cub->map[i][j] == NS_OPENING && cub->indexator)
				cub->map[i][j] = NS_OPEN;
			else if (cub->map[i][j] == NS_CLOSING && cub->indexator)
				cub->map[i][j] = NS_CLOSE;
		}
	}
}

void	door_msg(t_cub *cub)
{
	if (cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y) + 1]
	== NS_CLOSE || cub->map[(int)floor(cub->cam->x) + 1][(int)floor(cub->cam
		->y)] == EW_CLOSE || cub->map[(int)floor(cub->cam->x)][(int)floor(cub
			->cam->y) - 1] == NS_CLOSE || cub->map[(int)floor(cub->cam->x)
			- 1][(int)floor(cub->cam->y)] == EW_CLOSE)
		mlx_string_put(cub->mlx_ptr, cub->win_ptr, 550, 550, mlx_get_color_value
			(cub->mlx_ptr, 0x00FFFFFF),
			"Press SPACE to Open/Close doors around you");
	mlx_mouse_hide();
	usleep(600);
}

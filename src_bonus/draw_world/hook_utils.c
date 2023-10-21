/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:49:01 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/09 10:49:41 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

void	door_sound(void)
{
	if (fork() == 0)
	{
		system("afplay -v 5 -q 1 ./ressources/door_clanch.mp3");
		exit(0);
	}
}

void	hook_next(t_cub *cub, int kc)
{
	if (kc == 49 && cub->start)
		trigger_door(cub);
	if (!cub->start)
		cub->start = 1;
}

void	moving_plus(t_cub *cub)
{
	cub->cam->x -= sin(cub->cam->alpha) * 0.2;
	if (cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] > 1 && cub
	->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] != EW_OPEN && cub
	->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] != NS_OPEN)
		cub->cam->x += sin(cub->cam->alpha) * 0.2;
	cub->cam->y -= cos(cub->cam->alpha) * 0.2;
	if (cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] > 1 && cub
	->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] != EW_OPEN && cub
	->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] != NS_OPEN)
		cub->cam->y += cos(cub->cam->alpha) * 0.2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:00:59 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/29 13:27:01 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw3D.h"

static void	moving(t_cub *cub, int kc);

int	keydown(int kc, t_cub *cub)
{
	if (kc == 53)
		close_cub(cub);
	else if (kc == 126 || kc == 125)
		moving(cub, kc);
	else if (kc == 123)
	{
		cub->cam->alpha -= M_PI / 60;
		cub->cam->alpha += 2.0 * M_PI;
		cub->cam->alpha = fmod(cub->cam->alpha, 2.0 * M_PI);
	}
	else if (kc == 124)
	{
		cub->cam->alpha += M_PI / 60;
		cub->cam->alpha += 2.0 * M_PI;
		cub->cam->alpha = fmod(cub->cam->alpha, 2.0 * M_PI);
	}
	return (1);
}

static void	moving(t_cub *cub, int kc)
{
	if (kc == 126)
	{
		cub->cam->x += sin(cub->cam->alpha) * 0.2;
		cub->cam->y += cos(cub->cam->alpha) * 0.2;
	}
	else if (kc == 125)
	{
		cub->cam->x -= sin(cub->cam->alpha) * 0.2;
		cub->cam->y -= cos(cub->cam->alpha) * 0.2;
	}
}

int	close_cub(t_cub *cub)
{
	tini(cub);
	exit (1);
}

int	mousedown(int button, int x, int y, t_cub *cub)
{
	(void) cub;
	(void) x;
	(void) y;
	(void) button;
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:00:59 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/06 10:44:42 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

static void	moving(t_cub *cub, int kc);

int	keydown(int kc, t_cub *cub)
{
	if (kc == 53)
		close_cub(cub);
	else if ((kc == 126 || kc == 125 || kc == 1 || kc == 13) && cub->start)
		moving(cub, kc);
	else if ((kc == 123 || kc == 0) && cub->start)
	{
		cub->cam->alpha -= M_PI / 60;
		cub->cam->alpha += 2.0 * M_PI;
		cub->cam->alpha = fmod(cub->cam->alpha, 2.0 * M_PI);
	}
	else if ((kc == 124 || kc == 2) && cub->start)
	{
		cub->cam->alpha += M_PI / 60;
		cub->cam->alpha += 2.0 * M_PI;
		cub->cam->alpha = fmod(cub->cam->alpha, 2.0 * M_PI);
	}
	else if (kc == 11 && cub->start)
	{
		cub->cam->alpha += M_PI;
		cub->cam->alpha += 2.0 * M_PI;
		cub->cam->alpha = fmod(cub->cam->alpha, 2.0 * M_PI);
	}
	else
		hook_next(cub, kc);
	return (1);
}

void	trigger_door(t_cub *c)
{
	if (c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) + 1] == NS_OPEN || c
->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) + 1] == NS_CLOSE || c->map[
(int)floor(c->cam->x)][(int)floor(c->cam->y) - 1] == NS_OPEN || c->map[(int)
floor(c->cam->x)][(int)floor(c->cam->y) - 1] == NS_CLOSE || c->map[(int)floor(c
->cam->x) + 1][(int)floor(c->cam->y)] == EW_OPEN || c->map[(int)floor(c->cam->x)
	+ 1][(int)floor(c->cam->y)] == EW_CLOSE || c->map[(int)floor(c->cam->x) - 1]
[(int)floor(c->cam->y)] == EW_OPEN || c->map[(int)floor(c->cam->x) - 1][(int)
floor(c->cam->y)] == EW_CLOSE)
		door_sound();
	if (c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) + 1] == NS_OPEN)
		c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) + 1] = NS_CLOSING;
	if (c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) + 1] == NS_CLOSE)
		c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) + 1] = NS_OPENING;
	if (c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) - 1] == NS_OPEN)
		c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) - 1] = NS_CLOSING;
	if (c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) - 1] == NS_CLOSE)
		c->map[(int)floor(c->cam->x)][(int)floor(c->cam->y) - 1] = NS_OPENING;
	if (c->map[(int)floor(c->cam->x) + 1][(int)floor(c->cam->y)] == EW_OPEN)
		c->map[(int)floor(c->cam->x) + 1][(int)floor(c->cam->y)] = EW_CLOSING;
	if (c->map[(int)floor(c->cam->x) + 1][(int)floor(c->cam->y)] == EW_CLOSE)
		c->map[(int)floor(c->cam->x) + 1][(int)floor(c->cam->y)] = EW_OPENING;
	if (c->map[(int)floor(c->cam->x) - 1][(int)floor(c->cam->y)] == EW_OPEN)
		c->map[(int)floor(c->cam->x) - 1][(int)floor(c->cam->y)] = EW_CLOSING;
	if (c->map[(int)floor(c->cam->x) - 1][(int)floor(c->cam->y)] == EW_CLOSE)
		c->map[(int)floor(c->cam->x) - 1][(int)floor(c->cam->y)] = EW_OPENING;
}

static void	moving(t_cub *cub, int kc)
{
	if (kc == 126 || kc == 13)
	{
		cub->cam->x += sin(cub->cam->alpha) * 0.2;
		if (cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] > 1 &&
		cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] != EW_OPEN
		&& cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)]
		!= NS_OPEN)
			cub->cam->x -= sin(cub->cam->alpha) * 0.2;
		cub->cam->y += cos(cub->cam->alpha) * 0.2;
		if (cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] > 1 &&
		cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] != EW_OPEN
		&& cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)]
		!= NS_OPEN)
			cub->cam->y -= cos(cub->cam->alpha) * 0.2;
	}
	else if (kc == 125 || kc == 1)
		moving_plus(cub);
	if (cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] == -42)
		sophie_scream(cub);
}

int	close_cub(t_cub *cub)
{
	tini(cub);
	exit (1);
}

int	mousemove(int x, int y, t_cub *cub)
{
	if (cub->start)
	{
		mlx_mouse_move(cub->win_ptr, WIN_W / 2, WIN_H / 2);
		cub->cam->alpha += (M_PI / 60) * 20 * ((double)(x - WIN_W / 2)) / WIN_W;
		cub->cam->alpha += 2.0 * M_PI;
		cub->cam->alpha = fmod(cub->cam->alpha, 2.0 * M_PI);
		(void) y;
	}
	return (1);
}

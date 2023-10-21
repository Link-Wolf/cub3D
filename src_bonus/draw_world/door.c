/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 09:53:28 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 14:12:54 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

static int	door_y2(t_cub *cb, t_camvar *v);
static int	door_x2(t_cub *cb, t_camvar *v);
static int	door_x3(t_cub *cb, t_camvar *v);

int	door_x(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex]
		[(int) v->casey] <= 1 && cb->map[(int) v->casex - 1][(int) v
		->casey] == EW_CLOSE)
	{
		ft_memcpy(v->texture_slice.img, cb->door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->y - floor(v->y)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	if (cb->map[(int) v->casex][(int) v->casey] == EW_CLOSE && cb->map[(int)
			v->casex - 1][(int) v->casey] <= 1)
	{
		ft_memcpy(v->texture_slice.img, cb->door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->y + floor(v->y)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (door_x2(cb, v));
}

static int	door_x2(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex]
		[(int) v->casey] <= 1 && cb->map[(int) v->casex - 1][(int) v->casey]
		== EW_CLOSING && (fmod(v->y, 1) < .25 || (fmod(v->y, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->y - floor(v->y)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	if (cb->map[(int) v->casex][(int) v->casey] == EW_CLOSING && cb->map[(int)
			v->casex - 1][(int) v->casey] <= 1 && (fmod(v->y, 1) < .25
			|| (fmod(v->y, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->y + floor(v->y)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (door_x3(cb, v));
}

static int	door_x3(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex]
		[(int) v->casey] <= 1 && cb->map[(int) v->casex - 1][(int) v->casey]
			== EW_OPENING && (fmod(v->y, 1) < .25 || (fmod(v->y, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->y - floor(v->y)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	if (cb->map[(int) v->casex][(int) v->casey] == EW_OPENING && cb->map[(int)
			v->casex - 1][(int) v->casey] <= 1 && (fmod(v->y, 1) < .25
			|| (fmod(v->y, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->y + floor(v->y)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (0);
}

int	door_y(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex]
		[(int) v->casey] <= 1 && cb->map[(int) v->casex][(int) v
		->casey - 1] == NS_CLOSE)
	{
		ft_memcpy(v->texture_slice.img, cb->door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->x + floor(v->x)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	if (cb->map[(int) v->casex][(int) v->casey] == NS_CLOSE && cb->map[(int)
			v->casex][(int) v->casey - 1] <= 1)
	{
		ft_memcpy(v->texture_slice.img, cb->door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->x - floor(v->x)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (door_y2(cb, v));
}

static int	door_y2(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex]
		[(int) v->casey] <= 1 && cb->map[(int) v->casex][(int) v
		->casey - 1] == NS_CLOSING && (fmod(v->x, 1) < .25
		|| (fmod(v->x, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->x + floor(v->x)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	if (cb->map[(int) v->casex][(int) v->casey] == NS_CLOSING && cb->map[(int)
			v->casex][(int) v->casey - 1] <= 1 && (fmod(v->x, 1) < .25
			|| (fmod(v->x, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->x - floor(v->x)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (door_y3(cb, v));
}

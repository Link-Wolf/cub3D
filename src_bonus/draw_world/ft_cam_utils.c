/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:20:10 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 10:12:07 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

void	init_cam1(t_cub *cub, t_camvar *v)
{
	v->x = (v->dist * sin (cub->cam->alpha)) + (cub->cam->x) + ((double) v
			->slice / WIN_H * tan(FOV / 2) * 2 * v->dist * sin(cub->cam
				->alpha + M_PI_2));
	v->y = (v->dist * cos (cub->cam->alpha)) + (cub->cam->y) + ((double) v
			->slice / WIN_H * tan(FOV / 2) * 2 * v->dist * cos(cub->cam
				->alpha + M_PI_2));
	v->x_next = ((v->dist + 1) * sin (cub->cam->alpha)) + (cub->cam->x)
		+ ((double) v->slice / WIN_H * tan(FOV / 2) * 2 * (v->dist + 1)
			* sin(cub->cam->alpha + M_PI_2));
	v->y_next = ((v->dist + 1) * cos (cub->cam->alpha)) + (cub->cam->y)
		+ ((double) v->slice / WIN_H * tan(FOV / 2) * 2 * (v->dist + 1)
			* cos(cub->cam->alpha + M_PI_2));
	v->alpha = atan2(v->x_next - v->x, v->y_next - v->y);
	if (sin(v->alpha) > 0)
	{
		v->dx = ceil(v->x) - v->x;
		v->casex = floor(v->x);
	}
	else
	{
		v->dx = v->x - floor(v->x);
		v->casex = floor(v->x);
	}
}

void	init_cam2(t_camvar *v)
{
	if (cos(v->alpha) > 0)
	{
		v->dy = ceil(v->y) - v->y;
		v->casey = floor(v->y);
	}
	else
	{
		v->dy = v->y - floor(v->y);
		v->casey = floor(v->y);
	}
	if (fabs(v->x - round(v->x)) < 0.000000001)
	{
		v->dx = 1;
		v->casex = round(v->x);
	}
	if (fabs(v->y - round(v->y)) < 0.000000001)
	{
		v->dy = 1;
		v->casey = round(v->y);
	}
	if (fabs(sin(v->alpha)) < 0.000000001)
		v->stepx = 100000000;
	else
		v->stepx = v->dx / sin(v->alpha);
}

int	in_if_x(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex][(int) v->casey] == WALL && (cb->map[(int)
			v->casex - 1][(int) v->casey] <= 1 || cb->map[(int)
					v->casex - 1][(int) v->casey] >= 8))
	{
		ft_memcpy(v->texture_slice.img, cb->so_text, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->y + floor(v->y)) * cb
			->so_text->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	else if ((cb->map[(int) v->casex][(int) v->casey] <= 1 || cb->map[(int) v
			->casex][(int) v->casey] >= 8) && cb
	->map[(int) v->casex - 1][(int) v->casey] == WALL)
	{
		ft_memcpy(v->texture_slice.img, cb->no_text, sizeof (t_text) * 2);
			v->texture_slice.pix_col = (1 - ceil(v->y) + v->y) * cb
			->no_text->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (door_x(cb, v));
}

int	in_if_y(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex][(int) v->casey] == WALL && (cb->map[(int)
	v->casex][(int) v->casey - 1] <= 1 || cb->map[(int)
	v->casex][(int) v->casey - 1] >= 8))
	{
		ft_memcpy(v->texture_slice.img, cb->ea_text, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->x - floor(v->x)) * cb->ea_text
			->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	else if ((cb->map[(int) v->casex][(int) v->casey] <= 1 || cb->map[(int) v
			->casex][(int) v->casey] >= 8) && cb
	->map[(int) v->casex][(int) v->casey - 1] == WALL)
	{
		ft_memcpy(v->texture_slice.img, cb->we_text, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (ceil(v->x) - v->x) * cb->we_text
			->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (door_y(cb, v));
}

int	in_while(t_cub *cub, t_camvar *v)
{
	init_cam1(cub, v);
	init_cam2(v);
	if (fabs(cos(v->alpha)) < 0.000000001)
		v->stepy = 100000000;
	else
		v->stepy = v->dy / cos(v->alpha);
	if ((int) v->casex < 1 || (int) v->casex >= cub->nb_line || (int) v
		->casey < 1 || (int) v->casey >= cub->nb_cols)
		return (1);
	if (fabs(v->x - round(v->x)) < 0.000000001)
	{
		if (in_if_x(cub, v))
			return (1);
	}
	else if (fabs(v->y - round(v->y)) < 0.000000001)
		if (in_if_y(cub, v))
			return (1);
	v->eucl = fmin (fabs(v->stepx), fabs(v->stepy));
	v->dist += (v->eucl * sin (v->alpha) * sin (cub->cam->alpha) + v->eucl
			* cos (v->alpha) * cos (cub->cam->alpha));
	return (0);
}

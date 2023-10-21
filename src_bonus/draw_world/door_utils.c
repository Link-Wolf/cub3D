/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 14:03:58 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 14:08:08 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

int	door_y3(t_cub *cb, t_camvar *v)
{
	if (cb->map[(int) v->casex]
		[(int) v->casey] <= 1 && cb->map[(int) v->casex][(int) v->casey - 1]
		== NS_OPENING && (fmod(v->x, 1) < .25 || (fmod(v->x, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (1 - v->x + floor(v->x)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	if (cb->map[(int) v->casex][(int) v->casey] == NS_OPENING && cb->map[(int)
			v->casex][(int) v->casey - 1] <= 1 && (fmod(v->x, 1) < .25
			|| (fmod(v->x, 1) > .75)))
	{
		ft_memcpy(v->texture_slice.img, cb->o_door, sizeof (t_text) * 2);
		v->texture_slice.pix_col = (v->x - floor(v->x)) * cb
			->door->w;
		line(cb, v->slice + WIN_W / 2, fmin(v->dist, RDIST), &v->texture_slice);
		return (1);
	}
	return (0);
}

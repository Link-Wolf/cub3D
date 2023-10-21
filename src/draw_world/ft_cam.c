/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:40:44 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/03 13:57:27 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw3D.h"

static void		line2(t_cub *cub, double dist, t_textslice *texture_slice,
					int slice);
static double	ft_map_to_01(double x, double a, double b);
static double	ft_map_from_01(double x, double a, double b);

void	ft_cam(t_cub *cub)
{
	t_camvar	v;

	v.slice = -WIN_W / 2;
	while (v.slice < WIN_W - WIN_W / 2)
	{
		v.dist = 0;
		while (1)
		{
			if (in_while(cub, &v))
				break ;
		}
		v.slice++;
	}
}

void	line(t_cub *cub, int slice, double dist, t_textslice *texture_slice)
{
	int	i;
	int	pos;

	i = -1;
	while (++i < (int)(WIN_H - WIN_H / dist) / 2 && i < WIN_H)
	{
		pos = (i * cub->img[cub->indexator].line_size + slice * (cub->img[cub
					->indexator].bits_per_pixel / 8));
		*(unsigned *)(cub->img[cub->indexator].px + pos)
			= mlx_get_color_value(cub->mlx_ptr, (cub->ceiling->red << 16) | (cub
					->ceiling->green << 8) | (cub->ceiling->blue));
	}
	line2(cub, dist, texture_slice, slice);
}

static void	line2(t_cub *cub, double dist, t_textslice *texture_slice,
	int slice)
{
	int	pos_in_image;
	int	i;
	int	pos;

	i = (int) fmax((WIN_H - WIN_H / dist) / 2, 0);
	while (i < (WIN_H + WIN_H / dist) / 2 && i < WIN_H)
	{
		pos = i * cub->img[cub->indexator].line_size + slice * (cub->img[cub
				->indexator].bits_per_pixel / 8);
		pos_in_image = ((int)ft_map_from_01(ft_map_to_01((i++), (int)(WIN_H
							- WIN_H / dist) / 2, (WIN_H + WIN_H / dist) / 2), 0,
					texture_slice->img->h)) * texture_slice->img->line_size
			+ ((int)texture_slice->pix_col) * (texture_slice->img
				->bits_per_pixel / 8);
		*(unsigned *)(cub->img[cub->indexator].px + pos)
			= *(unsigned *)(texture_slice->img->px + pos_in_image);
	}
	while (i < WIN_H)
	{
		pos = ((i++) * cub->img[cub->indexator].line_size + slice * (cub
					->img[cub->indexator].bits_per_pixel / 8));
		*(unsigned *)(cub->img[cub->indexator].px + pos)
			= mlx_get_color_value(cub->mlx_ptr, (cub->floor->red << 16) | (cub
					->floor->green << 8) | (cub->floor->blue));
	}
}

static double	ft_map_to_01(double x, double a, double b)
{
	return ((x - a) / (b - a));
}

static double	ft_map_from_01(double x, double a, double b)
{
	return (x * (b - a) + a);
}

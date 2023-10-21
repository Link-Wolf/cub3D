/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cam.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 14:40:44 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/04 10:55:27 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

static void		line2(t_cub *cub, double dist, t_textslice *texture_slice,
					int slice);
static void		line3(t_cub *cub, int slice, int i9);
static double	ft_map(double x, double a, double b, int trt);

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
	int				i;
	double			mult;
	int				pos;

	i = -1;
	while (++i < (int)(WIN_H - WIN_H / dist) / 2 && i < WIN_H)
	{
		if (i < ((cub->img[cub->indexator].h - (cub->img[cub->indexator].h
						/ RDIST) / 2)))
		mult = ft_map(i, (cub->img[cub->indexator].h - cub->img[cub
						->indexator].h / RDIST) / 1.9, 0, 1);
		pos = (i * cub->img[cub->indexator].line_size + slice * (cub->img[cub
					->indexator].bits_per_pixel / 8));
		*(unsigned *)(cub->img[cub->indexator].px + pos)
			= mlx_get_color_value(cub->mlx_ptr,
				(unsigned char)(cub->ceiling->red * mult) << 16
				| (unsigned char)(cub->ceiling->green * mult) << 8
				| (unsigned char)(cub->ceiling->blue * mult));
	}
	line2(cub, dist, texture_slice, slice);
}

static void	line2(t_cub *cub, double dist, t_textslice *texture_slice,
	int slice)
{
	int				i;
	int				pos_in_image;
	double			mult;
	int				pos;
	unsigned int	color;

	i = (int) fmax((WIN_H - WIN_H / dist) / 2, 0);
	while (i < (WIN_H + WIN_H / dist) / 2 && i < WIN_H)
	{
		mult = ft_map(dist, RDIST, 0, 1);
		pos = i * cub->img[cub->indexator].line_size + slice * (cub->img[cub
				->indexator].bits_per_pixel / 8);
		pos_in_image = ((int)ft_map(ft_map((i++), (int)(WIN_H - WIN_H / dist)
						/ 2, (WIN_H + WIN_H / dist) / 2, 1),
					0, texture_slice->img->h, 0)) * texture_slice->img
			->line_size + ((int)texture_slice->pix_col) * (texture_slice->img
				->bits_per_pixel / 8);
		color = *(unsigned *)(texture_slice->img[cub->indexator].px
				+ pos_in_image);
		*(unsigned *)(cub->img[cub->indexator].px + pos)
			= ((int)((0x000000FF & (color >> 16)) * mult) << 16 | (int)
				((0x000000FF & (color >> 8)) * mult) << 8 | (int)((0x000000FF
						& color) * mult));
	}
	line3(cub, slice, i);
}

static void	line3(t_cub *cub, int slice, int i)
{
	double		mult;
	int			pos;

	while (i < WIN_H)
	{
		mult = 0;
		if (i > ((cub->img[cub->indexator].h + cub->img[cub->indexator].h
					/ RDIST) / 2))
		mult = ft_map(i, (cub->img[cub->indexator].h + cub->img[cub
						->indexator].h / RDIST) / 2.1, cub->img[cub->indexator]
					.h, 1);
		pos = ((i++) * cub->img[cub->indexator].line_size + slice * (cub
					->img[cub->indexator].bits_per_pixel / 8));
		*(unsigned *)(cub->img[cub->indexator].px + pos)
			= mlx_get_color_value(cub->mlx_ptr,
				(unsigned char)(cub->floor->red * mult) << 16
				| (unsigned char)(cub->floor->green * mult) << 8
				| (unsigned char)(cub->floor->blue * mult));
	}
}

static double	ft_map(double x, double a, double b, int t)
{
	if (t == 1)
		return ((x - a) / (b - a));
	return (x * (b - a) + a);
}

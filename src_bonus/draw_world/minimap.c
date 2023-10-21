/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:07:29 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 10:35:21 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"
//
static void			cursor(t_cub *cub);
static unsigned int	get_map_color(t_cub *cub, int i, int j);
static void			cursor_bis(t_cub *cub, double angle);

void	set_minimap(t_cub *cub)
{
	int	w;
	int	h;

	cub->mmap->mask->ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/Mask42stein3D.xpm", &w, &h);
	cub->mmap->mapframe_ptr = mlx_png_file_to_image(cub->mlx_ptr,
			"textures/Horrorstein3D.png", &w, &h);
	cub->mmap->map->ptr = mlx_new_image(cub->mlx_ptr, w, h);
	cub->mmap->mask->px = mlx_get_data_addr(cub->mmap->mask->ptr,
			&cub->mmap->mask->bits_per_pixel, &cub->mmap->mask->line_size,
			&cub->mmap->mask->endian);
	cub->mmap->map->px = mlx_get_data_addr(cub->mmap->map->ptr,
			&cub->mmap->map->bits_per_pixel, &cub->mmap->map->line_size,
			&cub->mmap->map->endian);
	refresh_minimap(cub);
}

void	refresh_minimap(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 270)
	{
		j = -1;
		while (++j < 480)
		{
			if (*(unsigned int *)(cub->mmap->mask->px + j * cub->mmap->mask
				->bits_per_pixel / 8 + i * cub->mmap->mask->line_size)
				== mlx_get_color_value(cub->mlx_ptr, 0x00FFFFFF))
				*(unsigned int *)(cub->mmap->map->px + j * cub->mmap->map
						->bits_per_pixel / 8 + i * cub->mmap->mask->line_size)
					= get_map_color(cub, i, j);
			else
				*(unsigned int *)(cub->mmap->map->px + j * cub->mmap->map
						->bits_per_pixel / 8 + i * cub->mmap->mask->line_size)
					= 0xFF000000;
		}
	}
	cursor(cub);
}

static void	cursor(t_cub *cub)
{
	double	angle;

	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap->map->ptr,
		0, 0);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap->mapframe_ptr,
		0, 0);
	angle = fmod(cub->cam->alpha, M_PI * 2);
	if (angle >= M_PI_4 / 2.0 && angle < 3.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[6], 202, 152);
	else if (angle >= 3.0 * M_PI_4 / 2.0 && angle < 5.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[5], 202, 152);
	else if (angle >= 5.0 * M_PI_4 / 2.0 && angle < 7.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[4], 202, 152);
	else if (angle >= 7.0 * M_PI_4 / 2.0 && angle < 9.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[3], 202, 152);
	else
		cursor_bis(cub, angle);
}

static void	cursor_bis(t_cub *cub, double angle)
{
	if (angle >= 9.0 * M_PI_4 / 2.0 && angle < 11.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[2], 202, 152);
	else if (angle >= 11.0 * M_PI_4 / 2.0 && angle < 13.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[1], 202, 152);
	else if (angle >= 13.0 * M_PI_4 / 2.0 && angle < 15.0 * M_PI_4 / 2.0)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[0], 202, 152);
	else
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->mmap
			->cursor_ptr[7], 202, 152);
}

static unsigned int	get_map_color(t_cub *cub, int i, int j)
{
	int		my_x;
	int		my_y;
	double	down;
	double	right;

	down = -cub->cam->x + 270 / 1.7 / 16;
	right = -cub->cam->y + 480 / 2.3 / 16;
	my_x = (int) floor((i - down * 16) / 16);
	my_y = (int) floor((j - right * 16) / 16);
	if (my_x >= cub->nb_line || my_x < 0 || my_y >= cub->nb_cols || my_y < 0)
		return (mlx_get_color_value(cub->mlx_ptr, 0x00F4FEFE));
	if (cub->map[my_x][my_y] == WALL || cub->map[my_x][my_y] == NS_CLOSE || cub
		->map[my_x][my_y] == EW_CLOSE)
		return (mlx_get_color_value(cub->mlx_ptr, 0x00606060));
	if (cub->map[my_x][my_y] == NS_OPEN || cub->map[my_x][my_y] == EW_OPEN)
		return (mlx_get_color_value(cub->mlx_ptr, 0x007A7A7A));
	if (cub->map[my_x][my_y] == NS_OPENING || cub->map[my_x][my_y]
		== EW_OPENING || cub->map[my_x][my_y] == NS_CLOSING || cub
		->map[my_x][my_y] == EW_CLOSING)
		return (mlx_get_color_value(cub->mlx_ptr, 0x006C6C6C));
	if (cub->map[my_x][my_y] == FLOOR || cub->map[my_x][my_y] == SPAWN
		|| cub->map[my_x][my_y] == SOPHIE)
		return (mlx_get_color_value(cub->mlx_ptr, 0x009F9F9F));
	else
		return (mlx_get_color_value(cub->mlx_ptr, 0x00F4FEFE));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:37:31 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/29 13:29:56 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/draw3D.h"

static void	create_textures(t_cub *cub);
static int	frame(t_cub *cub);
static void	init_img(t_cub *cb);

void	draw(t_cub *cb)
{
	cb->mlx_ptr = mlx_init();
	cb->win_ptr = mlx_new_window(cb->mlx_ptr, WIN_W, WIN_H, "42stein3D");
	init_img(cb);
	create_textures(cb);
	cb->no_text->px = mlx_get_data_addr(cb->no_text->ptr, &cb->no_text
			->bits_per_pixel, &cb->no_text->line_size, &cb->no_text->endian);
	cb->so_text->px = mlx_get_data_addr(cb->so_text->ptr, &cb->so_text
			->bits_per_pixel, &cb->so_text->line_size, &cb->so_text->endian);
	cb->ea_text->px = mlx_get_data_addr(cb->ea_text->ptr, &cb->ea_text
			->bits_per_pixel, &cb->ea_text->line_size, &cb->ea_text->endian);
	cb->we_text->px = mlx_get_data_addr(cb->we_text->ptr, &cb->we_text
			->bits_per_pixel, &cb->we_text->line_size, &cb->we_text->endian);
	place_squares(cb);
	ft_cam(cb);
	mlx_hook(cb->win_ptr, ON_KEYDOWN, 1, keydown, cb);
	mlx_hook(cb->win_ptr, ON_MOUSEDOWN, 1, mousedown, cb);
	mlx_hook(cb->win_ptr, ON_DESTROY, 0, close_cub, cb);
	mlx_loop_hook(cb->mlx_ptr, frame, cb);
	mlx_put_image_to_window(cb->mlx_ptr, cb->win_ptr, cb->img[cb->indexator]
		.ptr, 0, 0);
	mlx_loop(cb->mlx_ptr);
}

static void	init_img(t_cub *cb)
{
	cb->img[0].ptr = mlx_new_image(cb->mlx_ptr, WIN_W, WIN_H);
	cb->img[0].h = WIN_H;
	cb->img[0].w = WIN_W;
	cb->img[1].ptr = mlx_new_image(cb->mlx_ptr, WIN_W, WIN_H);
	cb->img[1].h = WIN_H;
	cb->img[1].w = WIN_W;
	cb->img[0].px = mlx_get_data_addr(cb->img[0].ptr, &cb->img[0]
			.bits_per_pixel, &cb->img[0].line_size, &cb->img[0].endian);
	cb->img[1].px = mlx_get_data_addr(cb->img[1].ptr, &cb->img[1]
			.bits_per_pixel, &cb->img[1].line_size, &cb->img[1].endian);
}

static int	frame(t_cub *cub)
{
	ft_cam(cub);
	mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
		cub->img[cub->indexator].ptr, 0, 0);
	cub->indexator = (cub->indexator + 1) % 2;
	return (0);
}

static void	create_textures(t_cub *cub)
{
	if (!ft_strcmp(ft_strrchr(cub->no_path, '.'), ".png"))
		cub->no_text->ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->no_path,
				&(cub->no_text->w), &(cub->no_text->h));
	else
		cub->no_text->ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->no_path,
				&cub->no_text->w, &cub->no_text->h);
	if (!ft_strcmp(ft_strrchr(cub->so_path, '.'), ".png"))
		cub->so_text->ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->so_path,
				&cub->so_text->w, &cub->so_text->h);
	else
		cub->so_text->ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->so_path,
				&cub->so_text->w, &cub->so_text->h);
	if (!ft_strcmp(ft_strrchr(cub->ea_path, '.'), ".png"))
		cub->ea_text->ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->ea_path,
				&cub->ea_text->w, &cub->ea_text->h);
	else
		cub->ea_text->ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->ea_path,
				&cub->ea_text->w, &cub->ea_text->h);
	if (!ft_strcmp(ft_strrchr(cub->we_path, '.'), ".png"))
		cub->we_text->ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->we_path,
				&cub->we_text->w, &cub->we_text->h);
	else
		cub->we_text->ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->we_path,
				&cub->we_text->w, &cub->we_text->h);
}

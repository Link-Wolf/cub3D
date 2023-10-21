/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_world.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 15:37:31 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 14:11:18 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

static void	create_textures(t_cub *cub);
static int	frame(t_cub *cub);
static void	init_img(t_cub *cb);

void	draw(t_cub *cb)
{
	cb->mlx_ptr = mlx_init();
	cb->win_ptr = mlx_new_window(cb->mlx_ptr, WIN_W, WIN_H, "42stein3D");
	init_img(cb);
	create_textures(cb);
	cb->no_text[0].px = mlx_get_data_addr(cb->no_text[0].ptr, &cb->no_text[0]
			.bits_per_pixel, &cb->no_text[0].line_size, &cb->no_text[0].endian);
	cb->so_text[0].px = mlx_get_data_addr(cb->so_text[0].ptr, &cb->so_text[0]
			.bits_per_pixel, &cb->so_text[0].line_size, &cb->so_text[0].endian);
	cb->ea_text[0].px = mlx_get_data_addr(cb->ea_text[0].ptr, &cb->ea_text[0]
			.bits_per_pixel, &cb->ea_text[0].line_size, &cb->ea_text[0].endian);
	cb->we_text[0].px = mlx_get_data_addr(cb->we_text[0].ptr, &cb->we_text[0]
			.bits_per_pixel, &cb->we_text[0].line_size, &cb->we_text[0].endian);
	place_squares(cb);
	no_such_place2(cb);
	ft_cam(cb);
	mlx_mouse_hide();
	mlx_mouse_move(cb->win_ptr, WIN_W / 2, WIN_H / 2);
	mlx_hook(cb->win_ptr, ON_KEYDOWN, 1, keydown, cb);
	mlx_hook(cb->win_ptr, ON_MOUSEMOVE, 1, mousemove, cb);
	mlx_hook(cb->win_ptr, ON_DESTROY, 0, close_cub, cb);
	set_minimap(cb);
	mlx_loop_hook(cb->mlx_ptr, frame, cb);
	mlx_put_image_to_window(cb->mlx_ptr, cb->win_ptr, cb->img[cb->indexator]
		.ptr, 0, 0);
	mlx_loop(cb->mlx_ptr);
}

static void	init_img(t_cub *cb)
{
	cb->door[0].ptr = mlx_xpm_file_to_image(cb->mlx_ptr,
			"./textures/door.xpm",
			&cb->door[0].w, &cb->door[0].h);
	cb->door[1].ptr = mlx_xpm_file_to_image(cb->mlx_ptr,
			"./textures/door2.xpm",
			&cb->door[1].w, &cb->door[1].h);
	cb->o_door[0].ptr = mlx_xpm_file_to_image(cb->mlx_ptr,
			"./textures/o_door.xpm",
			&cb->o_door[0].w, &cb->o_door[0].h);
	cb->o_door[1].ptr = mlx_xpm_file_to_image(cb->mlx_ptr,
			"./textures/o_door.xpm",
			&cb->o_door[1].w, &cb->o_door[1].h);
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
	init_sophie(cb);
}

void	init_cursor(t_cub *cub)
{
	int	w;
	int	h;

	cub->mmap->cursor_ptr[0] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorCursedpp.xpm", &w, &h);
	cub->mmap->cursor_ptr[1] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorUp.xpm", &w, &h);
	cub->mmap->cursor_ptr[2] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorCursedmp.xpm", &w, &h);
	cub->mmap->cursor_ptr[3] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorLeft.xpm", &w, &h);
	cub->mmap->cursor_ptr[4] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorCursedmm.xpm", &w, &h);
	cub->mmap->cursor_ptr[5] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorDown.xpm", &w, &h);
	cub->mmap->cursor_ptr[6] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorCursedpm.xpm", &w, &h);
	cub->mmap->cursor_ptr[7] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/CursorRight.xpm", &w, &h);
}

static int	frame(t_cub *cub)
{
	if (!cub->start)
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->begin, 0, 0);
	if (!cub->start)
		return (0);
	ft_cam(cub);
	mlx_clear_window(cub->mlx_ptr, cub->win_ptr);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
		cub->img[cub->indexator].ptr, 0, 0);
	refresh_minimap(cub);
	cub->indexator = (cub->indexator + 1) % 2;
	if (cub->sophie_trigger >= 1)
	{
		mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr,
			cub->sophie_frames[cub->sophie_itr], 220, -100);
		if (cub->indexator == 1)
			(cub->sophie_itr)++;
	}
	update_frames(cub);
	door_msg(cub);
	return (0);
}

static void	create_textures(t_cub *cub)
{
	if (!ft_strcmp(ft_strrchr(cub->no_path, '.'), ".png"))
		cub->no_text[0].ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->no_path,
				&(cub->no_text[0].w), &(cub->no_text[0].h));
	else
		cub->no_text[0].ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->no_path,
				&cub->no_text[0].w, &cub->no_text[0].h);
	if (!ft_strcmp(ft_strrchr(cub->so_path, '.'), ".png"))
		cub->so_text[0].ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->so_path,
				&cub->so_text[0].w, &cub->so_text[0].h);
	else
		cub->so_text[0].ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->so_path,
				&cub->so_text[0].w, &cub->so_text[0].h);
	if (!ft_strcmp(ft_strrchr(cub->ea_path, '.'), ".png"))
		cub->ea_text[0].ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->ea_path,
				&cub->ea_text[0].w, &cub->ea_text[0].h);
	else
		cub->ea_text[0].ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->ea_path,
				&cub->ea_text[0].w, &cub->ea_text[0].h);
	if (!ft_strcmp(ft_strrchr(cub->we_path, '.'), ".png"))
		cub->we_text[0].ptr = mlx_png_file_to_image(cub->mlx_ptr, cub->we_path,
				&cub->we_text[0].w, &cub->we_text[0].h);
	else
		cub->we_text[0].ptr = mlx_xpm_file_to_image(cub->mlx_ptr, cub->we_path,
				&cub->we_text[0].w, &cub->we_text[0].h);
	init_alt_text(cub);
}

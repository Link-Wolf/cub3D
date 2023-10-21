/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sophie.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:21:58 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/06 10:56:19 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

void	init_sophie(t_cub *cub)
{
	int	w;
	int	h;

	cub->sophie_frames[0] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie2.xpm", &w, &h);
	cub->sophie_frames[1] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie1.xpm", &w, &h);
	cub->sophie_frames[2] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie2.xpm", &w, &h);
	cub->sophie_frames[3] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie3.xpm", &w, &h);
	cub->sophie_frames[4] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie2.xpm", &w, &h);
	cub->sophie_frames[5] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie1.xpm", &w, &h);
	cub->sophie_frames[6] = mlx_xpm_file_to_image(cub->mlx_ptr,
			"textures/sophie2.xpm", &w, &h);
	cub->begin = mlx_png_file_to_image(cub->mlx_ptr,
			"./textures/title_screen.png", &w, &h);
}

void	sophie_scream(t_cub *cub)
{
	if (fork() == 0)
	{
		system("afplay -v 1 -q 1 ./ressources/aAA.mp3");
		kill(SIGKILL, cub->fork_ambiance);
		exit(0);
	}
	else
	{
		cub->sophie_trigger = 1;
		cub->map[(int)floor(cub->cam->x)][(int)floor(cub->cam->y)] = FLOOR;
	}
}

void	init_alt_text(t_cub *cub)
{
	if (!cub->ea_text[1].ptr && !cub->we_text[1].ptr
		&& !cub->no_text[1].ptr && !cub->so_text[1].ptr)
	{
		cub->no_text[1].ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
				"./textures/imane_cursed.xpm",
				&cub->no_text[1].w, &cub->no_text[1].h);
		cub->so_text[1].ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
				"./textures/abel_cursed.xpm",
				&cub->so_text[1].w, &cub->so_text[1].h);
		cub->we_text[1].ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
				"./textures/yohan_cursed.xpm",
				&cub->we_text[1].w, &cub->we_text[1].h);
		cub->ea_text[1].ptr = mlx_xpm_file_to_image(cub->mlx_ptr,
				"./textures/caroline_cursed.xpm",
				&cub->ea_text[1].w, &cub->ea_text[1].h);
	}
}

void	no_such_place2(t_cub *cb)
{
	cb->door[0].px = mlx_get_data_addr(cb->door[0].ptr, &cb->door[0]
			.bits_per_pixel, &cb->door[0].line_size, &cb->door[0].endian);
	cb->o_door[0].px = mlx_get_data_addr(cb->o_door[0].ptr, &cb->o_door[0]
			.bits_per_pixel, &cb->o_door[0].line_size, &cb->o_door[0].endian);
	cb->door[1].px = mlx_get_data_addr(cb->door[1].ptr, &cb->door[1]
			.bits_per_pixel, &cb->door[1].line_size, &cb->door[1].endian);
	cb->o_door[1].px = mlx_get_data_addr(cb->o_door[1].ptr, &cb->o_door[1]
			.bits_per_pixel, &cb->o_door[1].line_size, &cb->o_door[1].endian);
	cb->no_text[1].px = mlx_get_data_addr(cb->no_text[1].ptr, &cb->no_text[1]
			.bits_per_pixel, &cb->no_text[1].line_size, &cb->no_text[1].endian);
	cb->so_text[1].px = mlx_get_data_addr(cb->so_text[1].ptr, &cb->so_text[1]
			.bits_per_pixel, &cb->so_text[1].line_size, &cb->so_text[1].endian);
	cb->ea_text[1].px = mlx_get_data_addr(cb->ea_text[1].ptr, &cb->ea_text[1]
			.bits_per_pixel, &cb->ea_text[1].line_size, &cb->ea_text[1].endian);
	cb->we_text[1].px = mlx_get_data_addr(cb->we_text[1].ptr, &cb->we_text[1]
			.bits_per_pixel, &cb->we_text[1].line_size, &cb->we_text[1].endian);
	init_cursor(cb);
}

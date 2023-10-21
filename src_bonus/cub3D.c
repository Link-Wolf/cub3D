/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:08:12 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/09 10:47:35 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes_bonus/check3D.h"

static void	init_cub(t_cub *cub);
static void	init_cub2(t_cub *cub);

int	main(int argc, char *argv[])
{
	t_cub	*cub;

	cub = malloc(sizeof(t_cub));
	if (argc != 2 || !ft_strrchr(argv[1], '.')
		|| ft_strcmp(ft_strrchr(argv[1], '.') + 1, "cub"))
		return (ft_printf("Usage : ./cub3D [cub file location]\n"));
	init_cub(cub);
	cub->check->fd = open(argv[1], O_RDONLY);
	if (cub->check->fd < 0)
	{
		perror("Error ");
		return (-1);
	}
	check_file(cub);
	ft_printf("[File seems okay, let's begin now]\n\nLoading . . .");
	close(cub->check->fd);
	system("osascript -e \"set Volume 2\"");
	draw(cub);
	tini(cub);
}

static void	init_cub(t_cub *cub)
{
	cub->check = ft_calloc(1, sizeof (t_check));
	cub->no_path = NULL;
	cub->so_path = NULL;
	cub->we_path = NULL;
	cub->ea_path = NULL;
	cub->ceiling = ft_calloc(1, sizeof (t_rgb));
	cub->floor = ft_calloc(1, sizeof (t_rgb));
	cub->map = ft_calloc(1, sizeof (int *));
	cub->nb_line = 0;
	cub->nb_cols = 1;
	cub->nb_walls = 0;
	cub->check_null = 0;
	cub->o_door = ft_calloc(2, sizeof (t_text));
	cub->door = ft_calloc(2, sizeof (t_text));
	cub->no_text = ft_calloc(2, sizeof (t_text));
	cub->so_text = ft_calloc(2, sizeof (t_text));
	cub->ea_text = ft_calloc(2, sizeof (t_text));
	cub->we_text = ft_calloc(2, sizeof (t_text));
	cub->cam = ft_calloc(1, sizeof (t_cam));
	cub->mmap = ft_calloc(1, sizeof (t_minimap));
	cub->neg = -1;
	cub->start = 0;
	init_cub2(cub);
}

static void	init_cub2(t_cub *cub)
{
	cub->indexator = 0;
	cub->sophie_trigger = 0;
	cub->sophie_itr = 0;
	cub->mlx_ptr = NULL;
	if (!cub->check || !cub->ceiling || !cub->floor || !cub->map
		// || !cub->no_text || !cub->so_text || !cub->ea_text || !cub->we_text
		|| !cub->cam || !cub->mmap)
	{
		ft_printf("AAAAAAAAAAError\nCode : 3\n\tUnexpected error during memory allocation. F\
or this one.. unfortunately I have to admit I can't blame you, just try again o\
r clear ur cache lmao\n");
		tini(cub);
	}
	cub->mmap->mask = ft_calloc(1, sizeof (t_image));
	cub->mmap->map = ft_calloc(1, sizeof (t_image));
	if (!cub->mmap->mask || !cub->mmap->map)
	{
		ft_printf("BBBBBBBBBBError\nCode : 3\n\tUnexpected error during memory allocation. F\
or this one.. unfortunately I have to admit I can't blame you, just try again o\
r clear ur cache lmao\n");
		tini(cub);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_path_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 12:06:19 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/02 13:05:38 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check3D.h"

static void	check_path_null(char *path, int *check);
static void	fill_path_but_next_next(t_cub *cb, char **c, char *line,
				char *path);

void	fill_path_but_next(t_cub *cb, char **c, char *line, char *path)
{
	if (!ft_strcmp(c[0], "NO") && !cb->no_path && cb->check->nb_walls < 4)
	{
		cb->no_path = ft_strdup(path);
		check_path_null(cb->no_path, &cb->check_null);
	}
	else if (!ft_strcmp(c[0], "SO") && !cb->so_path && cb->check->nb_walls < 4)
	{
		cb->so_path = ft_strdup(path);
		check_path_null(cb->so_path, &cb->check_null);
	}
	else if (!ft_strcmp(c[0], "WE") && !cb->we_path && cb->check->nb_walls < 4)
	{
		cb->we_path = ft_strdup(path);
		check_path_null(cb->we_path, &cb->check_null);
	}
	else if (!ft_strcmp(c[0], "EA") && !cb->ea_path && cb->check->nb_walls < 4)
	{
		cb->ea_path = ft_strdup(path);
		check_path_null(cb->ea_path, &cb->check_null);
	}
	else
		catch_texture_errors(cb, c, line);
	fill_path_but_next_next(cb, c, line, path);
}

static void	fill_path_but_next_next(t_cub *cb, char **c, char *line, char *path)
{
	if (cb->check_null >= 1)
	{
		(void) path;
		mixed_free(c, line);
		ft_printf("CCCCCCCCError\nCode : 3\n\tUnexpected error during memory allocation. F\
or this one.. unfortunately I have to admit I can't blame you, just try again o\
r clear ur cache lmao\n");
		tini(cb);
	}
	cb->check->nb_walls += 1;
}

static void	check_path_null(char *path, int *check)
{
	if (!path)
		(*check) += 1;
}

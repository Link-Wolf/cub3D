/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:55:24 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/02 13:15:15 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/check3D.h"

static void	fill_path(t_cub *cub, char **cont, char *line, char *path);
static void	catch_too_many_walls(t_cub *cub, char **cont, char *line);
static void	catch_extension_errors(t_cub *cub, char **c, char *line);

void	check_wall_path(t_cub *cub, char **cont, char *line)
{
	char	*path;

	if (cub->check->nb_walls >= 4)
		catch_too_many_walls(cub, cont, line);
	while (ft_isspace(**cont))
		(*cont)++;
	if (ft_strcmp(cont[0], "NO") && ft_strcmp(cont[0], "SO")
		&& ft_strcmp(cont[0], "WE") && ft_strcmp(cont[0], "EA"))
	{
		mixed_free(cont, line);
		cub->check->err_code = INVALID_WALL_TEXTURE_ID;
		error_manager(cub);
	}
	path = ft_strchr(line, ' ');
	path++;
	path = space_crop_tm(path);
	fill_path(cub, cont, line, path);
}

static void	fill_path(t_cub *cb, char **c, char *line, char *path)
{
	int		tmp_fd;

	if (!ft_strrchr(path, '.') || (ft_strcmp(ft_strrchr(path, '.') + 1, "xpm")
			&& ft_strcmp(ft_strrchr(path, '.') + 1, "png")))
		catch_extension_errors(cb, c, line);
	tmp_fd = open(path, O_RDONLY);
	if (tmp_fd < 0)
	{
		mixed_free(c, line);
		cb->check->err_code = INVALID_WALL_TEXTURE;
		error_manager(cb);
	}
	close(tmp_fd);
	fill_path_but_next(cb, c, line, path);
}

static void	catch_extension_errors(t_cub *cub, char **c, char *line)
{
	mixed_free(c, line);
	cub->check->err_code = WRONG_TEXTURE_EXTENSION;
	error_manager(cub);
}

static void	catch_too_many_walls(t_cub *cub, char **cont, char *line)
{
	mixed_free(cont, line);
	cub->check->err_code = TOO_MANY_WALLS;
	error_manager(cub);
}

void	catch_texture_errors(t_cub *cub, char **cont, char *line)
{
	mixed_free(cont, line);
	cub->check->err_code = WALL_TEXTURE_DUP_MISS;
	error_manager(cub);
}

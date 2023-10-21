/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:48:52 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/27 14:29:08 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/check3D.h"

static void	check_line_type(t_cub *cub, char **cont, char **line);
static void	check_map_validity(t_cub *cub);
static void	error_check_file(t_cub *cub, char *tmp);

void	check_file(t_cub *cub)
{
	char	*tmp;
	char	**cont;

	tmp = get_next_line(cub->check->fd);
	tmp[ft_strlen(tmp) - 1] = 0;
	if (!tmp)
		cub->check->err_code = EMPTY_FILE;
	if (!tmp)
		error_manager(cub);
	while (tmp)
	{
		cont = ft_split(tmp, 32);
		if (!cont)
			error_check_file(cub, tmp);
		if (*tmp)
			check_line_type(cub, cont, &tmp);
		if (cub->check->is_map == 1)
			break ;
		free(tmp);
		tmp = get_next_line(cub->check->fd);
		if (tmp)
			tmp[ft_strlen(tmp) - 1] = 0;
	}
	free(tmp);
	check_map_validity(cub);
}

static void	check_line_type(t_cub *cub, char **cont, char **line)
{
	if (!ft_strcmp(cont[0], "NO") || !ft_strcmp(cont[0], "SO")
		|| !ft_strcmp(cont[0], "WE") || !ft_strcmp(cont[0], "EA"))
		check_wall_path(cub, cont, *line);
	else if ((!ft_strcmp(cont[0], "C") || !ft_strcmp(cont[0], "F"))
		&& cont[1] && ft_strchr(cont[1], ','))
		check_cf(cub, cont, *line);
	else if (cont[0])
	{
		if (cub->check->nb_walls == 4 && cub->check->is_cf == 3)
			check_map(cub, cont, line);
		else
		{
			mixed_free(cont, *line);
			cub->check->err_code = INVALID_FILE;
			error_manager(cub);
		}
	}
	big_free(cont);
}

static void	check_map_validity(t_cub *cub)
{
	if (!cub->check->is_map)
		cub->check->err_code = DUP_SPAWN_INVALID_ELEM;
	if (!cub->check->is_map)
		error_manager(cub);
	if (!(cub->check->nb_walls == 4 && cub->we_path && cub->no_path
			&& cub->ea_path && cub->so_path && cub->check->is_cf == 3
			&& !cub->check->err_code))
	{
		cub->check->err_code = INVALID_FILE;
		error_manager(cub);
	}
}

static void	error_check_file(t_cub *cub, char *tmp)
{
	free(tmp);
	cub->check->err_code = ALLOCATION_FAILED;
	error_manager(cub);
}

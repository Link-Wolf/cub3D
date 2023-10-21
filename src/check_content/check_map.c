/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:34:29 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/23 15:38:15 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check3D.h"

static void	resize_map(t_cub *cub);
static void	append_int(t_cub *cub, char c, int i, int j);
static void	check_map_content(t_cub *cub, int *spawn);
static void	check_map_border(t_cub *cub, int i, int j, int *spawn);

void	check_map(t_cub *cub, char **cont, char **line)
{
	int	i;
	int	j;
	int	spawn;

	spawn = 0;
	i = 0;
	while (*line)
	{
		resize_map(cub);
		j = -1;
		while ((*line)[++j])
			append_int(cub, (*line)[j], i, j);
		free(*line);
		*line = get_next_line(cub->check->fd);
		i++;
	}
	check_map_content(cub, &spawn);
	if (cub->check->err_code)
	{
		mixed_free(cont, *line);
		error_manager(cub);
	}
}

static void	resize_map(t_cub *cub)
{
	int	**tmp;

	tmp = ft_calloc(cub->nb_line + 1, sizeof(int *));
	ft_memmove(tmp, cub->map, cub->nb_line * sizeof (int *));
	tmp[cub->nb_line] = ft_calloc(cub->nb_cols, sizeof (int));
	cub->nb_line++;
	free(cub->map);
	cub->map = tmp;
}

static void	append_int(t_cub *cub, char c, int i, int j)
{
	int	k;

	if (j >= cub->nb_cols)
	{
		k = -1;
		while (++k < cub->nb_line)
		{
			cub->map[k] = (int *) ft_realloc(cub->map[k], j * sizeof (int *),
					cub->nb_cols * sizeof (int *));
		}
		cub->nb_cols = j;
	}
	if (ft_isspace(c))
		cub->map[i][j] = VOID;
	else if (c == '1')
		cub->map[i][j] = WALL;
	else if (c == '0')
		cub->map[i][j] = FLOOR;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		cub->map[i][j] = SPAWN;
		cub->cam->alpha = get_alpha(c);
	}
	else
		cub->map[i][j] = ERROR;
}

static void	check_map_content(t_cub *cub, int *spawn)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++i < cub->nb_line)
	{
		j = -1;
		while (++j < cub->nb_cols)
		{
			if (cub->map[i][j] == -666)
				cub->check->err_code = INVALID_SPAWN_ELEM;
			if (cub->map[i][j] == -666)
				return ;
			if (cub->map[i][j] == SPAWN && *spawn >= 1)
				cub->check->err_code = DUP_SPAWN_INVALID_ELEM;
			if (cub->map[i][j] == SPAWN && *spawn >= 1)
				return ;
			check_map_border(cub, i, j, spawn);
			if (cub->check->err_code)
				return ;
		}
	}
	if (*spawn == 1)
		cub->check->is_map = 1;
}

static void	check_map_border(t_cub *cub, int i, int j, int *spawn)
{
	if ((cub->map[i][j] == FLOOR || cub->map[i][j] == SPAWN) && !(j + 1
								<= cub->nb_cols && cub->map[i][j + 1]
	!= VOID && j - 1 >= 0 && cub->map[i][j - 1] != VOID && i + 1
			<= cub->nb_line && cub->map[i + 1][j] != VOID && i - 1 >= 0
												&& cub->map[i - 1][j] != VOID))
	{
		cub->check->err_code = MAP_MUST_BE_CLOSED;
		return ;
	}
	else if (cub->map[i][j] == SPAWN)
		(*spawn)++;
}

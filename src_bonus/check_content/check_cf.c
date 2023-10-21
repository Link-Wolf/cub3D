/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 11:59:43 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/26 13:24:41 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/check3D.h"

static void	check_f(t_cub *cub, char **cont, char *line, char *to_free);
static void	check_c(t_cub *cub, char **cont, char *line, char *to_free);
static void	fill_f(t_cub *cub, char **tmp);
static void	fill_c(t_cub *cub, char **tmp);

void	check_cf(t_cub *cub, char **cont, char *line)
{
	char	*dup;

	dup = line;
	while (ft_isspace(*dup))
		dup++;
	if (!(dup[0] == 'F' && ft_isspace(dup[1])) && !(dup[0] == 'C'
			&& ft_isspace(dup[1])))
	{
		big_free(cont);
		free(line);
		cub->check->err_code = CF_INVALID_FORMAT;
		error_manager(cub);
	}
	if (dup[0] == 'F')
		check_f(cub, cont, dup, line);
	else
		check_c(cub, cont, dup, line);
	if (cub->check->err_code == C_DUPLICATE
		|| cub->check->err_code == F_DUPLICATE)
	{
		mixed_free(cont, line);
		error_manager(cub);
	}
}

static void	check_f(t_cub *cub, char **cont, char *line, char *to_free)
{
	char	**tmp;

	line++;
	tmp = ft_split(line, ',');
	if (!tmp)
	{
		mixed_free(cont, to_free);
		cub->check->err_code = ALLOCATION_FAILED;
		error_manager(cub);
	}
	if ((tmp[0] && tmp[1] && tmp[2] && !tmp[3]) && ft_atoi(tmp[0]) >= 0
		&& ft_atoi(tmp[0]) <= 255 && ft_atoi(tmp[1]) >= 0 && ft_atoi(tmp[1])
		<= 255 && ft_atoi(tmp[2]) >= 0 && ft_atoi(tmp[2]) <= 255)
		fill_f(cub, tmp);
	else
	{
		big_free(cont);
		mixed_free(tmp, to_free);
		cub->check->err_code = INVALID_FLOOR_FORMAT;
		error_manager(cub);
	}
	big_free(tmp);
}

static void	check_c(t_cub *cub, char **cont, char *line, char *to_free)
{
	char	**tmp;

	line++;
	tmp = ft_split(line, ',');
	if (!tmp)
	{
		mixed_free(cont, to_free);
		cub->check->err_code = ALLOCATION_FAILED;
		error_manager(cub);
	}
	if ((tmp[0] && tmp[2] && !tmp[3]) && ft_atoi(tmp[0]) >= 0 && ft_atoi(tmp[0])
		<= 255 && ft_atoi(tmp[1]) >= 0 && ft_atoi(tmp[1])
		<= 255 && ft_atoi(tmp[2]) >= 0 && ft_atoi(tmp[2]) <= 255)
		fill_c(cub, tmp);
	else
	{
		big_free(cont);
		mixed_free(tmp, to_free);
		cub->check->err_code = INVALID_CEILING_FORMAT;
		error_manager(cub);
	}
	big_free(tmp);
}

static void	fill_f(t_cub *cub, char **tmp)
{
	if (cub->check->is_cf != 1 && cub->check->is_cf != 3)
	{
		cub->floor->red = (unsigned char) ft_atou(tmp[0]);
		cub->floor->green = (unsigned char) ft_atou(tmp[1]);
		cub->floor->blue = (unsigned char) ft_atou(tmp[2]);
		cub->check->is_cf += 1;
	}
	else
		cub->check->err_code = F_DUPLICATE;
}

static void	fill_c(t_cub *cub, char **tmp)
{
	if (cub->check->is_cf != 2 && cub->check->is_cf != 3)
	{
		cub->ceiling->red = (char) ft_atoi(tmp[0]);
		cub->ceiling->green = (char) ft_atoi(tmp[1]);
		cub->ceiling->blue = (char) ft_atoi(tmp[2]);
		cub->check->is_cf += 2;
	}
	else
		cub->check->err_code = C_DUPLICATE;
}

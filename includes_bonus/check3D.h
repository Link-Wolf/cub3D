/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3D.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:13:33 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 10:19:50 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECK3D_H
# define CHECK3D_H

# include "struct.h"
# include "cub3D.h"

enum {
	EMPTY_FILE = 1,
	INVALID_WALL_TEXTURE_ID = 2,
	ALLOCATION_FAILED = 3,
	INVALID_WALL_TEXTURE = 4,
	WALL_TEXTURE_DUP_MISS = 5,
	CF_INVALID_FORMAT = 6,
	TOO_MANY_WALLS = 7,
	INVALID_FLOOR_FORMAT = 8,
	INVALID_CEILING_FORMAT = 9,
	F_DUPLICATE = 10,
	C_DUPLICATE = 11,
	INVALID_FILE = 12,
	MISSPLACED_MAP = 13,
	MAP_MUST_BE_CLOSED = 14,
	INVALID_SPAWN_ELEM = 15,
	DUP_SPAWN_INVALID_ELEM = 16,
	WRONG_TEXTURE_EXTENSION = 17,
	DOOR_WITHOUT_WALL = 18
};

void	check_file(t_cub *cub);
void	error_manager(t_cub *cub);
void	check_map(t_cub *cub, char **cont, char **line);
void	check_wall_path(t_cub *cub, char **cont, char *line);
void	check_cf(t_cub *cub, char **cont, char *line);
char	*space_crop_tm(char *s);
void	mixed_free(char **s1, char *s2);
void	big_free(char **s);
void	tini(t_cub *cub);
char	*is_space_n(char *s, int n);
void	double_free(char *s1, char *s2);
void	*ft_realloc(void *ptr, int size, int old);
double	get_alpha(char c);
void	fill_path_but_next(t_cub *cb, char **c, char *line, char *path);
void	catch_texture_errors(t_cub *cub, char **cont, char *line);
void	no_such_place(t_cub *cub, int i, int j, char c);
void	tini_image(t_cub *cub);
int		check_map_plus(t_cub *cub, int i, int j, int *spawn);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:35:01 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/29 12:45:38 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW3D_H
# define DRAW3D_H

# include "struct.h"
# include "cub3D.h"
# include "check3D.h"

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

void	draw(t_cub *cub);
t_vec3	*line_plane_inter(t_line *line, t_plane *plane);
double	dot_product(t_vec3 *v1, t_vec3 *v2);
t_vec3	*cross_product(t_vec3 *v1, t_vec3 *v2);
int		keydown(int keycode, t_cub *cub);
int		close_cub(t_cub *cub);
int		mousedown(int button, int x, int y, t_cub *cub);
void	ft_cam(t_cub *cub);
void	set_minimap(t_cub *cub);
void	refresh_minimap(t_cub *cub);
t_vec3	*create_vec3(double x, double y, double z);
t_vec3	*sub_vec3(t_vec3 *v1, t_vec3 *v2);
void	init_cam1(t_cub *cub, t_camvar *v);
void	init_cam2(t_camvar *v);
int		in_if_x(t_cub *cub, t_camvar *v);
int		in_if_y(t_cub *cub, t_camvar *v);
void	line(t_cub *cub, int slice, double dist, t_textslice *texture_slice);
int		in_while(t_cub *cub, t_camvar *v);

#endif

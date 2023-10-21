/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw3D.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:35:01 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/05 14:12:01 by xxxxxxx          ###   ########.fr       */
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
int		mousemove(int x, int y, t_cub *cub);
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
void	init_sophie(t_cub *cub);
void	sophie_scream(t_cub *cub);
void	init_cursor(t_cub *cub);
void	init_alt_text(t_cub *cub);
void	no_such_place2(t_cub *cb);
int		door_x(t_cub *cb, t_camvar *v);
int		door_y(t_cub *cb, t_camvar *v);
void	door_sound(void);
void	hook_next(t_cub *cub, int kc);
void	trigger_door(t_cub *c);
void	moving_plus(t_cub *cub);
int		door_y3(t_cub *cb, t_camvar *v);
void	door_msg(t_cub *cub);
void	update_frames(t_cub *cub);

#endif

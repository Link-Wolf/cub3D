/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_plane_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 21:27:43 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/26 15:46:07 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

/*
**	TODO: all cross products are malloced -> need to precalc them then free
**
**	TODO: -line->dir needs to be precalced (not a class, we cannot be smart)
**
**	NB: 22 cross pructuct (vec perpendicular to plane) + dot product
**		(return 0 if 2 vecs perpendicular) = 0 if line parrallel to plane
**
**	NB: 34 actually the distance between the origin of the line and the plane
*/
t_vec3	*line_plane_inter(t_line *line, t_plane *plane)
{
	t_vec3	*res;
	t_vec3	*minus_dir;

	minus_dir = create_vec3(-line->dir->x, -line->dir->y, -line->dir->z);
	if (!dot_product(line->dir, cross_product(plane->y_dir, minus_dir)))
		return (NULL);
	res = malloc(sizeof (t_vec3));
	if (!res)
		return (NULL);
	res->x = dot_product(
			cross_product(plane->y_dir, minus_dir),
			sub_vec3(line->origin, plane->origin))
		/ dot_product(minus_dir, cross_product(plane->x_dir, plane->y_dir));
	res->y = dot_product(
			cross_product(minus_dir, plane->x_dir),
			sub_vec3(line->origin, plane->origin))
		/ dot_product(minus_dir, cross_product(plane->x_dir, plane->y_dir));
	res->z = dot_product(
			cross_product(plane->x_dir, plane->x_dir),
			sub_vec3(line->origin, plane->origin))
		/ dot_product(minus_dir, cross_product(plane->x_dir, plane->y_dir));
	free(minus_dir);
	return (res);
}

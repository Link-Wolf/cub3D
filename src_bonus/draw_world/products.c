/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   products.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bguyot <bguyot@student.42mulhouse.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:22:31 by bguyot            #+#    #+#             */
/*   Updated: 2022/04/21 15:16:09 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/draw3D.h"

double	dot_product(t_vec3 *v1, t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3	*cross_product(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*res;

	res = malloc(sizeof (t_vec3));
	if (!res)
		return (NULL);
	res->x = v1->y * v2->z - v2->y * v1->z;
	res->y = v2->x * v1->z - v1->x * v2->z;
	res->z = v1->x * v2->y - v2->x * v1->y;
	return (res);
}

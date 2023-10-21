/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_utils_bis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 11:21:46 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/27 13:14:56 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/check3D.h"
#include "../../includes/draw3D.h"

void	*ft_realloc(void *ptr, int size, int old_size)
{
	void	*tmp;

	tmp = ft_calloc(1, size);
	if (!tmp)
		return (NULL);
	if (size < old_size)
		ft_memmove(tmp, ptr, size);
	else
		ft_memmove(tmp, ptr, old_size);
	free(ptr);
	ptr = tmp;
	return (ptr);
}

t_vec3	*create_vec3(double x, double y, double z)
{
	t_vec3	*res;

	res = malloc (sizeof (t_vec3));
	res->x = x;
	res->y = y;
	res->z = z;
	return (res);
}

t_vec3	*sub_vec3(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3	*res;

	res = malloc(sizeof (t_vec3));
	res->x = v1->x - v2->x;
	res->y = v1->y - v2->y;
	res->z = v1->z - v2->z;
	return (res);
}

double	get_alpha(char c)
{
	if (c == 'N')
		return (3.0 * M_PI_2);
	if (c == 'E')
		return (0);
	if (c == 'S')
		return (M_PI_2);
	else
		return (M_PI);
}

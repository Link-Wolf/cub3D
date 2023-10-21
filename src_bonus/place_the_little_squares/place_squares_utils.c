/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_squares_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 14:12:34 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/02 17:17:29 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/cub3D.h"

int	do_we_wall_it(int x)
{
	return (x == FLOOR || x == SOPHIE || x == SPAWN);
}

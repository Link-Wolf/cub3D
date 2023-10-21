/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 13:12:41 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/04/25 10:36:43 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include "struct.h"
# include "../libft/libft.h"

enum {
	VOID = 0,
	WALL = 2,
	FLOOR = 1,
	ENNEMY = -42,
	SPAWN = -30903,
	ERROR = -666
};

typedef struct s_cub	t_cub;

void	place_squares(t_cub *cub);
int		do_we_wall_it(int x);
void	draw(t_cub *cub);

#endif

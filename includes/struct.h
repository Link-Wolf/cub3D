/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:34:33 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/02 12:18:37 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "cub3D.h"

# ifndef WIN_H
#  define WIN_H 810
# endif

# ifndef WIN_W
#  define WIN_W 1440
# endif

# ifndef RDIST
#  define RDIST 10
# endif

# ifndef FOV
#  define FOV 1.0471975511965977461533
# endif

# ifndef T_IMAGE
#  define T_IMAGE

typedef struct s_image
{
	void	*ptr;
	char	*px;
	int		endian;
	int		bits_per_pixel;
	int		line_size;
	int		h;
	int		w;
}		t_image;
# endif

# ifndef T_TEXTSLICE
#  define T_TEXTSLICE

typedef struct s_textslice
{
	int			is_north_south;
	int			quad;
	double		pix_col;
	t_image		*img;
}		t_textslice;
# endif

# ifndef T_CHECK
#  define T_CHECK

typedef struct s_check
{
	int		fd;
	int		err_code;
	int		nb_walls;
	int		is_cf;
	int		is_map;
}		t_check;
# endif

# ifndef T_RGB
#  define T_RGB

typedef struct s_rgb
{
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;
}		t_rgb;
# endif

# ifndef T_VEC3
#  define T_VEC3

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}		t_vec3;
# endif

# ifndef T_LINE
#  define T_LINE

typedef struct s_line
{
	t_vec3	*origin;
	t_vec3	*dir;
}		t_line;
# endif

# ifndef T_PLANE
#  define T_PLANE

typedef struct s_plane
{
	t_vec3	*origin;
	t_vec3	*x_dir;
	t_vec3	*y_dir;
}		t_plane;
# endif

# ifndef T_TEXT
#  define T_TEXT

typedef struct s_text
{
	void	*text;
	char	*px;
	int		w;
	int		h;
	int		endian;
	int		line_bytes;
	int		pixel_bits;
}		t_text;
# endif

# ifndef T_MINIMAP
#  define T_MINIMAP

typedef struct s_minimap
{
	void	*mapframe_ptr;
	void	*cursor_ptr[8];
	t_image	*mask;
	t_image	*map;
}		t_minimap;
# endif

# ifndef T_CAM
#  define T_CAM

typedef struct s_cam
{
	double	x;
	double	y;
	double	alpha;

}		t_cam;
# endif

# ifndef T_CUB
#  define T_CUB

typedef struct s_cub
{
	int			check_null;
	int			indexator;
	t_check		*check;
	t_image		*no_text;
	t_image		*so_text;
	t_image		*ea_text;
	t_image		*we_text;
	void		*mlx_ptr;
	void		*win_ptr;
	t_image		img[2];
	char		*no_path;
	char		*so_path;
	char		*ea_path;
	char		*we_path;
	t_rgb		*ceiling;
	t_rgb		*floor;
	int			**map;
	int			nb_line;
	int			nb_cols;
	int			nb_walls;
	t_minimap	*mmap;
	t_cam		*cam;
}		t_cub;
# endif

# ifndef T_CAMVAR
#  define T_CAMVAR

typedef struct t_camvar
{
	double		dist;
	t_textslice	texture_slice;
	int			slice;
	double		x;
	double		y;
	double		dx;
	double		dy;
	double		stepx;
	double		stepy;
	double		alpha;
	double		eucl;
	double		casex;
	double		casey;
	double		x_next;
	double		y_next;
}		t_camvar;
# endif

#endif

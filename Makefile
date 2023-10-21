# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/21 17:33:35 by xxxxxxx           #+#    #+#              #
#    Updated: 2022/05/09 12:39:22 by xxxxxxx          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= cub3D
NAME_BONUS			= cub3D_bonus

INCLUDE				= ./includes/
INCLUDE_BONUS		= ./includes_bonus/
LIBFTDIR			= ./libft/
LIBFT				= ./libft/libft.a
SRC_DIR				= ./src/
SRC_DRAW_DIR		= ./src/draw_world/
SRC_SQUARE_DIR		= ./src/place_the_little_squares/
SRC_CHECK_DIR		= ./src/check_content/
SRC_OTHER_DIR		= ./src/other_stuff/
SRC_DIR_BONUS		= ./src_bonus/
SRC_DRAW_DIR_BONUS	= ./src_bonus/draw_world/
SRC_SQUARE_DIR_BONUS= ./src_bonus/place_the_little_squares/
SRC_CHECK_DIR_BONUS	= ./src_bonus/check_content/
SRC_OTHER_DIR_BONUS	= ./src_bonus/other_stuff/

SRC_FILES			= cub3D.c
SRC_DRAW_FILES		= draw_world.c hook.c ft_cam.c products.c \
					  line_plane_inter.c ft_cam_utils.c
SRC_SQUARE_FILES	= place_squares.c place_squares_utils.c
SRC_CHECK_FILES 	= check_file.c check_map.c check_wall_path.c check_cf.c \
					  check_wall_path_utils.c
SRC_OTHER_FILES		= error_manager.c cub3D_utils.c cub3D_utils_bis.c
SRC_FILES_B			= cub3D.c
SRC_DRAW_FILES_B	= draw_world.c hook.c ft_cam.c products.c minimap.c \
					  line_plane_inter.c ft_cam_utils.c sophie.c door.c \
					  hook_utils.c door_utils.c draw_world_utils.c
SRC_SQUARE_FILES_B	= place_squares.c place_squares_utils.c
SRC_CHECK_FILES_B 	= check_file.c check_map.c check_wall_path.c check_cf.c \
					  check_wall_path_utils.c check_map_utils.c
SRC_OTHER_FILES_B	= error_manager.c cub3D_utils.c cub3D_utils_bis.c

SRCS				= $(addprefix $(SRC_DIR),$(SRC_FILES)) \
				  	$(addprefix $(SRC_DRAW_DIR),$(SRC_DRAW_FILES)) \
				  	$(addprefix $(SRC_SQUARE_DIR),$(SRC_SQUARE_FILES)) \
				  	$(addprefix $(SRC_CHECK_DIR),$(SRC_CHECK_FILES)) \
				  	$(addprefix $(SRC_OTHER_DIR),$(SRC_OTHER_FILES))
SRCS_BONUS			= $(addprefix $(SRC_DIR_BONUS),$(SRC_FILES_B)) \
				  	$(addprefix $(SRC_DRAW_DIR_BONUS),$(SRC_DRAW_FILES_B)) \
				  	$(addprefix $(SRC_SQUARE_DIR_BONUS),$(SRC_SQUARE_FILES_B)) \
				  	$(addprefix $(SRC_CHECK_DIR_BONUS),$(SRC_CHECK_FILES_B)) \
				  	$(addprefix $(SRC_OTHER_DIR_BONUS),$(SRC_OTHER_FILES_B))
OBJS				= $(SRCS:.c=.o)
OBJS_BONUS			= $(SRCS_BONUS:.c=.o)

CC					= @gcc
CFLAGS				= -Wall -Wextra -Werror
RM					= @rm -f

all: $(NAME) $(NAME_BONUS)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) -Llibft -lft $(OBJS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
	@printf "\e[36m\tCompilation \t[ ✓ ]\n\e[39m"

$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

$(NAME_BONUS): $(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) -Llibft -lft $(OBJS_BONUS) -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
	@printf "\e[96m\tBonus \t\t[ ✓ ]\n\e[39m"

clean:
	@$(MAKE) clean -C $(LIBFTDIR)
	$(RM) $(OBJS) $(OBJS_BONUS)
	@printf "\e[31m\tClean \t\t[ ✓ ]\n\e[39m"

fclean: clean
	@$(MAKE) fclean -C $(LIBFTDIR)
	$(RM) $(NAME) $(NAME_BONUS)
	@printf "\e[35;5;161m\tBinary Clean \t[ ✓ ]\n\e[39m"

re:	fclean all

.PHONY:	all clean fclean re

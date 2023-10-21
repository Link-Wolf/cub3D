/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xxxxxxx <xxxxxxx@student.42mulhouse.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 10:59:54 by xxxxxxx           #+#    #+#             */
/*   Updated: 2022/05/06 10:48:27 by xxxxxxx          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes_bonus/check3D.h"

static void	tini2(t_cub *cub);

const char	*g_err_msg[] = {[EMPTY_FILE] = "File is empty. Hint : give a real fi\
le, fucker", [ALLOCATION_FAILED] = "Unexpected error during memory allocation. F\
or this one.. unfortunately I have to admit I can't blame you, just try again o\
r clear ur cache lmao", [INVALID_WALL_TEXTURE_ID] = "I only need a texture for t\
hese 4 cardinal points : NO, SO, EA and WE. We're not in a 4D+ world bro",
[INVALID_WALL_TEXTURE] = "When I ask you a path to a texture file, I except an \
existant file, did you really think that I'm gonna create it myself duh??",
[WALL_TEXTURE_DUP_MISS] = "In case you didn't know, I need a texture for these \
4 cardinal points : NO, SO, EA and WE. No more, no less, right ?",
[CF_INVALID_FORMAT] = "Let me explain you how work the floor and ceiling thing \
: [C/F] [0-255],[0-255],[0-255]  Isn't it simple ? An ID and a RGB code",
[TOO_MANY_WALLS] = "Here we are.. Do you know others cardinal points than north\
, south, east and west ? Me neither, so don't try to add some or I'll be less n\
ice", [INVALID_FLOOR_FORMAT] = "Let me explain you how work the floor thing : [F\
] [0-255],[0-255],[0-255]  Isn't it simple ? F and a RGB code",
[INVALID_CEILING_FORMAT] = "Let me explain you how work the ceiling thing : [C]\
 [0-255],[0-255],[0-255]  Isn't it simple ? C and a RGB code", [F_DUPLICATE] = "\
You have multiple floors in your house ? Amazing, good for you, but I don't fu\
cking care you damn bourgeois, we don't", [C_DUPLICATE] = "You have multiple ce\
ilings in your house ? Amazing, good for you, but I don't fucking care you dam\
n bourgeois, we don't", [INVALID_FILE] = "Invalid file : find the error yoursel\
f because U r not a 🤡 , u r the entire 🎪", [MISSPLACED_MAP] = "I case you were \
wondering, YES the map must be the last thing on your file, and NO I wont negot\
iate with e-terrorists", [MAP_MUST_BE_CLOSED] = "You know, deep void space is NO\
T breathable, you might want to close that hole.. don't forget I'm watching you\
. Oh, and yes, the spawn can't be a wall u know", [INVALID_SPAWN_ELEM] = "In ca\
se you can't read, I need a spawn, and only accept the letters N,S,E and W dumb\
ss. The rest of the map is only filled by 0, 1 and space characters",
[DUP_SPAWN_INVALID_ELEM] = "I might have forget to precise, but OBVIOUSLY it ca\
n only have exactly 1 iteration of N,S,E or W, not less nor more",
[WRONG_TEXTURE_EXTENSION] = "Textures can only be .png or .xpm files (but i sti\
ll prefer xpm you know)\n\t((No, really i don't want to influence you, but xpm \
are waaaayyyy better))\n\t(((please)))", [DOOR_WITHOUT_WALL] = "Doors must b\
e placed between two walls right ? Otherwise, on what do they hang ? The air ??\
????"};

void	error_manager(t_cub *cub)
{
	ft_printf("Error\nCode : %d\n\t%s\n", cub->check->err_code,
		g_err_msg[cub->check->err_code]);
	close(cub->check->fd);
	if (cub->mlx_ptr)
		tini_image(cub);
	tini(cub);
}

void	tini(t_cub *cub)
{
	int	i;

	system("killall afplay");
	system("osascript -e \"set Volume 0\"");
	i = -1;
	while (++i < cub->nb_line)
		free(cub->map[i]);
	if (!cub || !cub->check || !cub->check->err_code)
	{
		if (cub->sophie_itr > 0)
		{
			ft_printf("\n\n*closing the game with strange and horrific noise*\n\n\
u̵̞̲̦̽̆̚ṃ̷̱̱̈́ ̴̖͔̹̽d̷̛̰͛o̶̡͓͊l̶̡̫̠̓͌͠o̶̮̍̈̆r̴̡̫͑ ̴̛̯̀̇s̶̡͓͐͛ỉ̶̡̨̖t̴̹͆͐̚ ̶̳̥͔̏̀͝a̵̺͛ḿ̷͕̽̿ḛ̸̼̟̎t̸̨̙̫͛,̴͕̒ ̸̲͂̂c̷̡̜̔̃ö̶̩̼́n̶̡̖̮͑̽̓ś̶̹̂͘e̸̦̖͠c̵̡̤̔̊͝t̷̛̪͌̕ḙ̴̞̪̿̀̉t̸̢̹͓̏̌͆u̷̞͛͒r̸̹̽ ̴͈̠̩̚a̵̡͔̦͛̇̚d̷͓̝̓̎i̸̫̮͆̒̕p̷͔͌̋i̸̢͙̍̌͠s̵̻̖͂c̷͉͕͜͝i̷̗̱͒̎̿ṋ̵̀͛g̶̢̛̭̏ ̴̦̹̠̓ë̷̮̞́l̸̟̊̓͂i̷̳̅̈́̑ṱ̶̈́̽.̴̘͐̔ ̵̰̥̫̚Ş̴͖̺́͌͂ű̴͇̪̭̓s̴̲͕̫̉p̶̲͔͓̚ě̷̞̗͚̍̃n̵̲̋d̶̡̓̉i̵̻͉̿ŝ̴̱s̴̨̥͎̉ë̶̦́̆ ̴̢̘̃u̴̧̨͐ț̸͖̭̊ ̶̨̟̝̎͛f̶̝̺͔̀̆͝ȇ̴̦͔̉̇ř̵̘̓m̸̝͈̯̽̈́͝e̷̪̒͝n̷̡̛̙͍͝t̴͕̜̺̔̇͐ŭ̴̪͔͇͆m̸̫̈́̆ ̸̨̜̱̐̈̀e̵̛̙͋̓r̵͈͉̀͜â̷̻͙̯̂̚t̸̙̻̀̓,̴͇͚̂ ̶̗͆̃͝\n																																					\n\
[Game over, good luck next time... on 42stein3D]\n");
		}
		else
		{
			ft_printf("\n\n*closing the game with sad noise*\n\
[Okay bye, see you soon on 42stein3D]\n");
		}
	}
	tini2(cub);
}

static void	tini2(t_cub *cub)
{
	free(cub->map);
	free(cub->check);
	free(cub->no_path);
	free(cub->ea_path);
	free(cub->we_path);
	free(cub->so_path);
	free(cub->ceiling);
	free(cub->floor);
	free(cub->no_text);
	free(cub->ea_text);
	free(cub->we_text);
	free(cub->so_text);
	free(cub->cam);
	free(cub->mmap->mask);
	free(cub->mmap->map);
	free(cub->mmap);
	free(cub);
	exit(1);
}

void	tini_image(t_cub *cub)
{
	mlx_destroy_image(cub->mlx_ptr, cub->begin);
	mlx_destroy_image(cub->mlx_ptr, cub->img[0].ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->img[1].ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->o_door->ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->door->ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->no_text->ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->so_text->ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->ea_text->ptr);
	mlx_destroy_image(cub->mlx_ptr, cub->we_text->ptr);
	mlx_destroy_window(cub->mlx_ptr, cub->win_ptr);
}

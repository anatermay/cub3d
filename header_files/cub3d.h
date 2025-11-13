/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:24:08 by aternero          #+#    #+#             */
/*   Updated: 2025/11/13 18:22:35 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//	**	LIBRARIES	**
# include "../resources/libft/libft.h"
# include "../resources/ft_printf/ft_printf.h"
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "macros.h"
# include "msg.h"
# include "../MLX42/include/MLX42/MLX42.h"

//	**	STRUCTURES	**

typedef struct s_boolean
{
	bool	tall;
	bool	wide;
}	t_boolean;

typedef struct s_texture
{
	char			*tex;
}	t_texture;

typedef struct s_vert
{
	char	id;
	int		red;
	int		green;
	int		blue;
	int		events;
}	t_vert;

typedef struct s_coord
{
	char		id;
	char		*id_name;
	t_texture	*tex;
	int			events;
}	t_coord;

typedef struct s_dim
{
	int	x;
	int	y;
}	t_dim;

typedef struct s_file
{
	char			*path;
	char			*line;
	bool			space;
	struct s_file	*next;
	struct s_file	*prev;
}	t_file;

typedef struct s_map
{
	char	**map;
	t_dim	dim;
	t_dim	player;
	t_coord	*direction;
}	t_map;

typedef struct s_game
{
	char	*path;
	t_file	*file;
	t_map	*map;
	t_coord	*north;
	t_coord	*south;
	t_coord	*west;
	t_coord	*east;
	t_vert	*floor;
	t_vert	*ceil;
	mlx_t	*mlx;
}	t_game;

//	**	FUNCTIONS	**

//	0_parser.c
t_game	*parser_main(char *argv);
int		cub_extension(char *str);

//	1_init_game.c
t_game	*init_game(char *argv);

//	2_init_file.c
t_file	*init_file(char **content, char *path);

//	3_gnl_to_file.c
char	**map_file_content(char *str);

//	4_init_coordinates.c
int		init_coords(t_game *game);

//	5_count_coords.c
void	coord_count(t_game *game, t_coord *coord, char *id);

//	6_init_vertical.c
t_vert	*init_vertical(t_game *game, char id, char *argv);

//	7_sorting.c
int		sorting(t_game *game);

//	8_process_data.c
int		process_data(t_game *game, char *line);

//	9_process_coordinates.c
int		process_coordinates(t_game *game, char **line);

//	10_process_vertical.c
int		process_vertical(t_game *game, char **line);

// 11_process_map.c
int		process_map(t_game *game, t_file *start);

// 12_extract_map.c
char	**extract_map(t_file *start);

// 13_map_check.c
int		map_check(t_game *game);

// 14_valid_characters.c
int		valid_characters(char **map);

//	15_single_player.c
int		single_player(char **map);

//	16_validation_walls.c
int		validation_walls(char **map);

//	17_flood_fill.c
int		re_recheck(char **map, t_dim dim);

//	18_textures_loading.c
void	load_image(t_game *game);
void	texture_to_image(t_game *game);

//	[ PARSER ] Utils
	/***	IDENTIFIERS	***/
int		is_position(char c);
int		is_vert(char *str);
int		is_coord(char *str);
	/***	LENGTH	***/
int		array_length(char **array);
	/***	LINES	***/
int		valid_special_row(char *map);
int		first_row(char **map, int index);
int		first_column(char *map, int index);
int		last_row(char **map, int yndex);
int		last_column(char *map, int yndex);
	/***	MEMORY AND FREE	***/
void	*array_free(char **array);
void	*free_game(t_game *game);
void	*free_file(t_file **file);
void	*free_map(t_map *map);
	/***	PLAYER POSITION	***/
t_dim	player_position(t_game *game, char **map);
	/***	PRINT	***/
int		print_error(char *msg);
	/***	SPACE	***/
int		is_space(char c);
int		is_space_array(char *str);
char	*space_strtrim(char *str);
	/***	SPLIT ***/
char	**u_split(char const *str);

void	start_game(t_game *game);

#endif

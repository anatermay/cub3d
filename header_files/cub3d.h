/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 11:24:08 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:21:11 by aternero         ###   ########.fr       */
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

//	**	STRUCTURES	**

typedef struct s_texture
{
	char	*tex;
	// mlx texture
}	t_texture;

typedef struct s_vert
{
	char	id;
	char	**lines;
	int		red;
	int		green;
	int		blue;
	int		events;
}	t_vert;

typedef struct s_coord
{
	char		id;
	char		*id_name;
	char		**lines;
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
}	t_file;

typedef struct s_map
{
	char	**map;
	t_dim	dim;
	t_dim	player;
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
}	t_game;

//	**	FUNCTIONS	**
	//	PARSER
int		cub_extension(char *str);
int		real_parse(t_game *game);
int		parser_main(t_game **game, char **argv, int argc);

	//	INIT GAME
t_game	*init_game(char *argv);

	//	INIT FILE
char	**map_file_content(char *str);
t_file	*init_file(char **content, char *path);

	//	GNL FILE
int		file_dimensions(int fd);
char	**file_content(char **file, int fd);

	//	COORD COUNT
void	coord_count(t_game *game, char *id);

	//	UTILS
void	array_free(char **array);
void	free_file(t_file **file);
void	free_game(t_game *game);
int		print_error(char *msg);
int		is_space(char c);
int		is_space_array(char *str);
int		open_fd(char *str);

#endif
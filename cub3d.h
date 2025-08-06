
#ifndef CUB3D_H
# define CUB3D_H

//  **  LIBRARIES   **

//  **  MACROS  **
# define TRUE 1
# define FALSE 0
	//	ERRORS
# define EARGC "Invalid number of arguments."
# define ECUB "Invalid file extension."
	//	COORDINATES
# define north "NO"
# define n_acronym 'N'
# define south "SO"
# define s_acronym 'S'
# define east "EA"
# define e_acronym 'E'
# define weast "WE"
# define w_acronym 'W'
# define floor 'F'
# define ceiling 'C'

//  **  STRUCTURES  **
typedef struct s_rgb_colours
{
	int red;
	int green;
	int blue;
}				t_rgb_colours;

typedef struct s_vertical
{
	char			id;
	t_rgb_colours	rgb;
}				t_vertical;

typedef struct s_textures
{
	char			*texture;
	//mlx img
}				t_textures;

typedef struct s_compass
{
	char			**id;
	char			acronym;
	char			*texture;
}				t_compass;

typedef struct s_position
{
	int				x;
	int				y;
}				t_position;

typedef struct s_player
{
	t_position		pos;	// position
	t_compass		dir;	// direction
}				t_player;

typedef struct s_map
{
	char			*path;
	char			**map;
	t_position		dim;	// map dimensions
	t_compass		north;
	t_compass		south;
	t_compass		east;
	t_compass		west;
	t_vertical		floor;
	t_vertical		ceiling;
}				t_map;

typedef struct s_game
{
	t_map			*map;
	t_player		*player;
}	t_game;

//  **  FUNCTIONS   **
	//	MAIN
	//	PARSER
int	prestructure_parsing(int argc, char **argv);
int	cub_extension(char *file);
	//	UTILS
int p_print(char *msg);

#endif
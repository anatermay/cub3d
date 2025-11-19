/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:05:26 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/19 10:58:27 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_UTILS_H
# define EX_UTILS_H

# define WIDTH 1920
# define HEIGHT 1080

# define OPACITY 255
# define FOV 66.0

# define MOV_SPEED 0.03
# define ROT_SPEED 0.02

# include "cub3d.h"
# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_player
{
	t_vector		pos;
	t_vector		dir;
	char			ori;
}					t_player;

typedef struct s_img_data
{
	mlx_texture_t	*tex;
	mlx_image_t		*img;
}					t_img_data;

typedef struct s_imgs
{
	t_img_data		no;
	t_img_data		ea;
	t_img_data		so;
	t_img_data		we;
}					t_imgs;

typedef struct s_dr_utils
{
	mlx_texture_t	*tex;
	int				y;
	int				x;
	int				tex_y;
	int				tex_x;
}					t_dr_utils;

typedef struct s_ex_utils
{
	mlx_t			*mlx;
	char			**map;
	mlx_image_t		*bg;
	uint32_t		c_color;
	uint32_t		f_color;
	t_imgs			imgs;
	t_player		player;
	t_vector		plane;
}					t_ex_utils;

typedef struct s_rayc
{
	double			pos_x;
	t_vector		map;
	t_vector		dir;
	t_vector		delt;
	t_vector		step;
	t_vector		dist;
	t_vector		side;
	double			perp;
	int				wall_h;
	double			wall_x;
	int				draw_start;
	int				draw_end;
}					t_rayc;

int		load_imgs(t_game *game, t_ex_utils *ex_utils);
void	build_bg(t_game *game, t_ex_utils *ex_utils);
void	paint_bg(t_ex_utils *ex_utils);
void	draw_wall(t_ex_utils *ex_utils, t_rayc *rayc, int x);

void	init_player(t_game *game, t_ex_utils *ex_utils);
void	init_camera(t_ex_utils *ex_utils);

void	move(t_ex_utils *ex_utils, double move_x, double move_y);
void	rotate(t_ex_utils *ex_utils, double rot);
// Main Loops
void	rayc_loop(t_ex_utils *ex_utils);
void	mov_loop(void *param);

void	run_game(t_game *game, t_ex_utils *ex_utils);
void	free_images(t_ex_utils *ex_utils, int err_lvl);

#endif

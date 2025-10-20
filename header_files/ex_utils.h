/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:05:26 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/20 11:57:44 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_UTILS_H
# define EX_UTILS_H

# define WIDTH 1920
# define HEIGHT 1080

# define OPACITY 255
# define FOV 66.0

# define MOV_SPEED 0.05
# define ROT_SPEED 0.03

# include "cub3d.h"
# include <math.h>

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif


typedef struct  s_mini_tex
{
    t_texture   wall;
    t_texture   pj;
}   t_mini_tex;

typedef struct s_vector
{
    double  x;
    double  y;
}   t_vector;


typedef struct  s_player
{
    t_vector    pos;
    t_vector    dir;
    char        ori;
}   t_player;

typedef struct  s_ex_utils
{
    mlx_t       *mlx;
	t_mini_tex  mini_tex;
    mlx_image_t *bg;
    uint32_t    c_color;
    uint32_t    f_color;
    t_player    player;
    t_vector    plane;
}	t_ex_utils;

typedef struct  s_rayc
{
    double      pos_x;
    t_vector    map;
	t_vector    dir;
    t_vector    delt;
}   t_rayc;


void	paint_bg(t_game* game, t_ex_utils *ex_utils);
void	get_images(t_game *game, t_ex_utils *ex_utils);
void	display_minimap(t_game *game, t_ex_utils *ex_utils);

#endif

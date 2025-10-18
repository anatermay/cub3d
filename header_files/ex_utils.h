/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 13:05:26 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/18 19:12:57 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EX_UTILS_H
# define EX_UTILS_H

#include "cub3d.h"

typedef struct s_mini_tex
{
    t_texture   wall;
    t_texture   pj;
}   t_mini_tex;

typedef struct s_ex_utils
{
	t_mini_tex  mini_tex;
    mlx_image_t *bg;
    uint32_t    c_color;
    uint32_t    f_color;
}	t_ex_utils;

void	paint_bg(t_game* game, t_ex_utils *ex_utils);
void	get_images(t_game *game, t_ex_utils *ex_utils);
void	display_minimap(t_game *game, t_ex_utils *ex_utils);

#endif

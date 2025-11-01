/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_controller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 20:33:36 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/01 18:21:07 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

// static void	update_frame(t_ex_utils *ex_utils)
// {
// 	paint_bg(ex_utils);
// 	rayc_loop(ex_utils);
// }

static void	move(t_ex_utils *ex_utils, double move_x, double move_y)
{
	t_player *p;

    p = &ex_utils->player;
	if (ex_utils->map[(int)(p->pos.y)][(int)(p->pos.x + move_x)] != '1')
		p->pos.x += move_x;
	if (ex_utils->map[(int)(p->pos.y + move_y)][(int)(p->pos.x)] != '1')
		p->pos.y += move_y;
	//update_frame(ex_utils);
}

static void	rotate(t_ex_utils *ex_utils, double rot)
{
	t_player *p;
    t_vector *plane;
	double old_dir_x;
	double old_plane_x;

    p = &ex_utils->player;
    plane = &ex_utils->plane;
    old_dir_x = p->dir.x;
    old_plane_x = ex_utils->plane.x;
	p->dir.x = p->dir.x * cos(rot) - p->dir.y * sin(rot);
	p->dir.y = old_dir_x * sin(rot) + p->dir.y * cos(rot);
	plane->x = plane->x * cos(rot) - plane->y * sin(rot);
	plane->y = old_plane_x * sin(rot) + plane->y * cos(rot);
	//update_frame(ex_utils);
}

void	key_controller(mlx_key_data_t keydata, void *param)
{
	t_ex_utils	*ex_utils;
    t_player    *p;
    
    ex_utils = param;
    p = &ex_utils->player;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
        if (keydata.key == MLX_KEY_ESCAPE)
            mlx_close_window(ex_utils->mlx);
		if (keydata.key == MLX_KEY_LEFT)
			rotate(ex_utils, -ROT_SPEED);
		if (keydata.key == MLX_KEY_RIGHT)
			rotate(ex_utils, ROT_SPEED);
        if (keydata.key == MLX_KEY_W)
			move(ex_utils, p->dir.x * MOV_SPEED, p->dir.y * MOV_SPEED);
		if (keydata.key == MLX_KEY_A)
			move(ex_utils, -p->dir.y * MOV_SPEED, p->dir.x * MOV_SPEED);
        if (keydata.key == MLX_KEY_D)
			move(ex_utils, p->dir.y * MOV_SPEED, -p->dir.x * MOV_SPEED);
		if (keydata.key == MLX_KEY_S)
			move(ex_utils, -p->dir.x * MOV_SPEED, -p->dir.y * MOV_SPEED);
	}
}

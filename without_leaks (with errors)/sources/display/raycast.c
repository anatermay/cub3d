/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:40:02 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/20 14:31:14 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

static void	init_rayc(t_ex_utils *ex_utils, t_rayc *rayc, int x)
{
	rayc->map.x = (int)ex_utils->player.pos.x;
	rayc->map.y = (int)ex_utils->player.pos.y;
	rayc->pos_x = 2 * x / (double)WIDTH - 1;
	rayc->dir.x = ex_utils->player.dir.x + ex_utils->plane.x * rayc->pos_x;
	rayc->dir.y = ex_utils->player.dir.y + ex_utils->plane.y * rayc->pos_x;
	rayc->delt.x = fabs(1 / rayc->dir.x);
	rayc->delt.y = fabs(1 / rayc->dir.y);
}

static void	init_dda(t_ex_utils *ex_utils, t_rayc *rayc)
{
	rayc->step.x = 1;
	rayc->step.y = 1;
	rayc->dist.x = (rayc->map.x + 1 - ex_utils->player.pos.x) * rayc->delt.x;
	rayc->dist.y = (rayc->map.y + 1 - ex_utils->player.pos.y) * rayc->delt.y;
	if (rayc->dir.x < 0)
	{
		rayc->step.x = -1;
		rayc->dist.x = (ex_utils->player.pos.x - rayc->map.x) * rayc->delt.x;
	}
	if (rayc->dir.y < 0)
	{
		rayc->step.y = -1;
		rayc->dist.y = (ex_utils->player.pos.y - rayc->map.y) * rayc->delt.y;
	}
}

static void	ex_dda(t_ex_utils *ex_utils, t_rayc *rayc)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (rayc->dist.x < rayc->dist.y)
		{
			rayc->dist.x += rayc->delt.x;
			rayc->map.x += rayc->step.x;
			rayc->side.x = 1;
			rayc->side.y = 0;
		}
		else
		{
			rayc->dist.y += rayc->delt.y;
			rayc->map.y += rayc->step.y;
			rayc->side.x = 0;
			rayc->side.y = 1;
		}
		if (ex_utils->map[(int)rayc->map.y][(int)rayc->map.x] == '1')
			hit = 1;
	}
}

static void	calc_wall_height(t_player player, t_rayc *rayc)
{
	if (rayc->side.x)
	{
		rayc->perp = (rayc->map.x - player.pos.x
				+ (1 - rayc->step.x) / 2) / rayc->dir.x;
		rayc->wall_x = player.pos.y + rayc->perp * rayc->dir.y;
	}
	else
	{
		rayc->perp = (rayc->map.y - player.pos.y
				+ (1 - rayc->step.y) / 2) / rayc->dir.y;
		rayc->wall_x = player.pos.x + rayc->perp * rayc->dir.x;
	}
	rayc->wall_x -= floor(rayc->wall_x);
	rayc->wall_h = (int)(HEIGHT / rayc->perp);
}

void	rayc_loop(t_ex_utils *ex_utils)
{
	int		x;
	t_rayc	rayc;

	x = -1;
	while (++x < WIDTH)
	{
		init_rayc(ex_utils, &rayc, x);
		init_dda(ex_utils, &rayc);
		ex_dda(ex_utils, &rayc);
		calc_wall_height(ex_utils->player, &rayc);
		draw_wall(ex_utils, &rayc, x);
	}
}

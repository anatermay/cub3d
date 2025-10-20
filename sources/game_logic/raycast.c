/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:40:02 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/20 13:32:28 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

static void init_dda(t_ex_utils *ex_utils, t_rayc *rayc)
{
    rayc->step.x = 1;
    rayc->step.y = 1;
    rayc->dist.x = (rayc->map.x + 1 - ex_utils->player.pos.x) * rayc->delt.x;
    rayc->dist.y = (rayc->map.y + 1 - ex_utils->player.pos.y) * rayc->delt.y;
    if (rayc->dir.x < 0)
    {
        rayc->step.x = -1;
        rayc->dist.x = rayc->delt.x - rayc->dist.x;
    }
    if (rayc->dir.y < 0)
    {
        rayc->step.y = -1;
        rayc->dist.y = rayc->delt.y - rayc->dist.y;
    }
}

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

void    rayc_loop(t_ex_utils *ex_utils)
{
    int     x;
    t_rayc  rayc;

    x = -1;
    while (++x < WIDTH)
    {
        init_rayc(ex_utils, &rayc, x);
        init_dda(ex_utils, &rayc);
    }
}

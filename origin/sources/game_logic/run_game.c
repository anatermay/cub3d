/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:50:58 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/11/15 13:16:17 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ex_utils.h"

void	run_game(t_game *game, t_ex_utils *ex_utils)
{
	build_bg(game, ex_utils);
	paint_bg(ex_utils);
	init_player(game, ex_utils);
	init_camera(ex_utils);
	rayc_loop(ex_utils);
	mlx_loop_hook(ex_utils->mlx, mov_loop, ex_utils);
	mlx_loop(ex_utils->mlx);
	free_images(ex_utils, 0);
	mlx_terminate(ex_utils->mlx);
}

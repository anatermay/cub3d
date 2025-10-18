/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/10/18 19:12:10 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include "ex_utils.h"

void	start_game(t_game *game)
{
	t_ex_utils	*ex_utils;

	ex_utils = malloc(sizeof(t_ex_utils));
	game->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", true);
	get_images(game, ex_utils);
	paint_bg(game, ex_utils);
	display_minimap(game, ex_utils);
	// mlx_key_hook(game->mlx, key_controller, data_game);
	mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 12:29:12 by jsanz-bo          #+#    #+#             */
/*   Updated: 2025/09/26 13:27:29 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	display_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map->dim.y)
	{
		j = 0;
		while (j < game->map->dim.x)
		{
			mlx_image_to_window(game->mlx,
                game->south->tex->img, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

void	start_game(t_game *game)
{
	game->mlx = mlx_init(game->map->dim.x * 64, game->map->dim.y * 64,
                "cub3D", true);
	display_map(game);
	// mlx_key_hook(game->mlx, key_controller, data_game);
	// mlx_loop(game->mlx);
	// if (game->collected == game->collects_total && game->exit)
	// 	ft_printf("You won!\n");
	// free_images(game);
	// mlx_terminate(game->mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:16:03 by aternero          #+#    #+#             */
/*   Updated: 2025/10/08 20:09:51 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	can_apply_direction(t_game *game, char dir)
{
	if (dir == 'N')
		game->map->direction = game->north;
	else if (dir == 'S')
		game->map->direction = game->south;
	else if (dir == 'W')
		game->map->direction = game->west;
	else if (dir == 'E')
		game->map->direction = game->east;
}

static void	apply_direction(t_game *game)
{
	int	yndex;
	int	index;

	if (!game || !game->map)
		return ;
	yndex = -1;
	while (game->map->map[++yndex])
	{
		index = -1;
		while (game->map->map[yndex][++index])
		{
			if (is_position(game->map->map[yndex][index]) == TRUE)
			{
				can_apply_direction(game, game->map->map[yndex][index]);
				return ;
			}
		}
	}
}

static int	real_parse(t_game *game)
{
	t_file	*temp;

	if (!game || !game->file)
		return (print_error("Invalid game or file pointer"));
	temp = game->file;
	while (temp && (!temp->line || !temp->line[0] || temp->space == TRUE))
		temp = temp->next;
	if (!temp)
		return (print_error(EEMPTYFILE));
	if (sorting(game) == FALSE)
		return (FALSE);
	return (TRUE);
}

int	cub_extension(char *str)
{
	if (ft_strlen(str) < 5
		|| ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4) != 0)
		return (print_error(ECUB));
	return (TRUE);
}

t_game	*parser_main(char *argv)
{
	t_game	*game;

	game = init_game(argv);
	if (!game)
		return (NULL);
	if (real_parse(game) == FALSE)
	{
		free_game(game);
		return (NULL);
	}
	load_image(game);
	apply_direction(game);
	return (game);
}

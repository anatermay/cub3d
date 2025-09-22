/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:16:03 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 18:27:36 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

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

static int	cub_extension(char *str)
{
	if (ft_strlen(str) < 5
		|| ft_strncmp(str + ft_strlen(str) - 4, ".cub", 4) != 0)
		return (print_error(ECUB));
	return (TRUE);
}

t_game	*parser_main(char *argv, int argc)
{
	t_game	*game;

	if (argc != 2)
	{
		print_error(EARGC);
		return (NULL);
	}
	if (cub_extension(argv) == FALSE)
		return (NULL);
	game = init_game(argv);
	if (!game)
		return (NULL);
	if (real_parse(game) == FALSE)
	{
		free_game(game);
		return (NULL);
	}
	return (game);
}

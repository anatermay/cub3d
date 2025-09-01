/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:05:52 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:45:12 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	parser_main(t_game **game, char **argv, int argc)
{
	if (argc != 2)
	{
		print_error(EARGC);
		return (FALSE);
	}
	if (cub_extension(argv[1]) == FALSE)
		return (FALSE);
	*game = init_game(ft_strdup(argv[1]));
	if (!(*game))
		return (FALSE);
	if (real_parse(*game) == FALSE)
	{
		free_game(*game);
		return (FALSE);
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	*game;

	game = NULL;
	if (parser_main(&game, argv, argc) == FALSE)
		return (1);
	ft_printf("YOU CAN PLAY!\n");
	free_game(game);
	return (0);
}

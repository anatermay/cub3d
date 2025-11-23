/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsanz-bo <jsanz-bo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:05:52 by aternero          #+#    #+#             */
/*   Updated: 2025/11/19 11:10:52 by jsanz-bo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static char	*pre_parser(int argc, char **argv)
{
	char	*path;

	if (argc != 2)
	{
		print_error(EARGC);
		return (NULL);
	}
	if (cub_extension(argv[1]) == FALSE)
		return (NULL);
	path = ft_strdup(argv[1]);
	if (!path)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	return (path);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	char	*path;

	path = pre_parser(argc, argv);
	if (!path)
		return (1);
	game = parser_main(path);
	if (!game)
	{
		free(path);
		return (1);
	}
	ft_printf("YOU CAN PLAY!\n");
	start_game(game);
	free_game(game);
	free(path);
	return (0);
}

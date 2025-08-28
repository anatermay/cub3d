/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 13:05:52 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 11:17:28 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	main(int argc, char **argv)
{
	t_game	*game;

	if (argc != 2)
	{
		print_error(EARGC);
		return (1);
	}
	if (cub_extension(argv[1]) == FALSE)
	{
		print_error(ECUB);
		return (1);
	}
	game = init_game(ft_strdup(argv[1]));
	free_game(game);
	return (0);
}

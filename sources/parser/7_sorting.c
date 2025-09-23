/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_sorting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 19:27:13 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 19:20:24 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	sorting(t_game *game)
{
	t_file	*temp;
	int		lines;

	lines = 6;
	temp = game->file;
	while (temp && lines > 0)
	{
		if (temp->space == FALSE)
		{
			if (process_data(game, temp->line) == FALSE)
				return (FALSE);
			lines--;
		}
		temp = temp->next;
	}
	if (lines > 0 || !game->north->tex || !game->south->tex
		|| !game->east->tex || !game->west->tex || game->floor->red == -1
		|| game->ceil->red == -1)
		return (print_error(EMISSINGELEM));
	if (process_map(game, temp) == FALSE)
		return (FALSE);
	return (TRUE);
}

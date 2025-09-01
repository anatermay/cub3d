/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:16:03 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 18:40:12 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	real_parse(t_game *game)
{
	/* int		index;
	t_file	*temp; */

	if (!game)
		return (FALSE);
	if (!game->file->line[0]
		|| (is_space_array(game->file->line) == TRUE
			&& game->file->next == NULL))
		return (print_error(EEMPTYFILE));
	/* index = 0;
	while (game->file)
	{
		temp = game->file;
		ft_printf("%d\n", index++);
		ft_printf("\t%s\n", temp->path);
		ft_printf("\t%s\n", temp->line);
		ft_printf("\t%d\n\n", temp->space);
		game->file = game->file->next;
		free(temp->line);
		free(temp->path);
		free(temp);
	} */
	return (TRUE);
}

int	cub_extension(char *str)
{
	int	index;

	index = 0;
	while (str[index])
		index++;
	if (index <= 4)
		return (print_error(ECUB));
	index--;
	if (str[index] == 'b' && str[index - 1] == 'u'
		&& str[index - 2] == 'c' && str[index - 3] == '.')
		return (TRUE);
	return (print_error(ECUB));
}

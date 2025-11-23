/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:49:45 by aternero          #+#    #+#             */
/*   Updated: 2025/09/23 18:57:39 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static char	**this_file_print(char *msg)
{
	print_error(msg);
	return (NULL);
}

static char	**fill_map(char **map, t_file *start)
{
	int	index;

	index = 0;
	while (start)
	{
		if (start->line)
		{
			map[index] = ft_strdup(start->line);
			if (!map[index])
				return (NULL);
			index++;
		}
		start = start->next;
	}
	map[index] = NULL;
	return (map);
}

static int	measure_file(t_file *start)
{
	t_file	*temp;
	t_file	*save;
	int		length;

	length = 0;
	temp = start;
	while (temp)
	{
		length++;
		if (temp->next == NULL)
			save = temp;
		temp = temp->next;
	}
	while (save)
	{
		if (save->space == FALSE)
			break ;
		length--;
		save = save->prev;
	}
	return (length);
}

char	**extract_map(t_file *start)
{
	char	**map;
	int		length;

	if (!start)
		return (NULL);
	while (start && (start->space == TRUE || !start->line || !start->line[0]))
		start = start->next;
	if (!start)
		return (this_file_print(ENOMAP));
	length = measure_file(start);
	if (length == 0)
		return (this_file_print(ENOMAP));
	map = malloc(sizeof(char *) * (length + 1));
	if (!map)
		return (this_file_print(EMALLOC));
	map[length] = NULL;
	fill_map(map, start);
	return (map);
}

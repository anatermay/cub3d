/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   12_extract_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:49:45 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 18:28:54 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static char	**fill_map(char **map, t_file *start)
{
	int	index;

	index = 0;
	while (start)
	{
		map[index] = ft_strdup(start->line);
		index++;
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
		temp = temp->next;
		if (temp->next == NULL)
			save = temp;
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

char	**extract_map(t_file *file, t_file *start)
{
	char	**map;
	int		length;

	if (!start)
		return (NULL);
	while (start && (start->space == TRUE || !start->line || !start->line[0]))
		start = start->next;
	length = measure_file(file);
	if (length == 0)
	{
		print_error(ENOMAP);
		return (NULL);
	}
	map = malloc(sizeof(char *) * (length + 1));
	if (!map)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	map[length] = NULL;
	fill_map(map, start);
	return (map);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:31:22 by aternero          #+#    #+#             */
/*   Updated: 2025/09/04 21:04:25 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static void	*this_file_free(t_file **file, char **array)
{
	if (file && *file)
		free_file(file);
	array_free(array);
	return (NULL);
}

static void	join_to_structure(t_file **file, t_file *new)
{
	t_file	*temp;

	if (!new)
		return ;
	if (!(*file))
	{
		*file = new;
		new->next = NULL;
	}
	else
	{
		temp = *file;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
		new->next = NULL;
	}
}

static t_file	*new_file_node(char *line, char *path)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	file->line = ft_strdup(line);
	file->space = is_space_array(line);
	file->path = ft_strdup(path);
	file->next = NULL;
	return (file);
}

t_file	*init_file(char **content, char *path)
{
	t_file	*file;
	t_file	*temp;
	int		index;

	if (!content)
		return (NULL);
	index = 0;
	file = NULL;
	while (content[index])
	{
		temp = new_file_node(content[index], path);
		if (!temp)
			return (this_file_free(&file, content));
		join_to_structure(&file, temp);
		index++;
	}
	return (file);
}

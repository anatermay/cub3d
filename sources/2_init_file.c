/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_init_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 16:31:22 by aternero          #+#    #+#             */
/*   Updated: 2025/08/28 11:14:47 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

void	increase_snake(t_file **file, t_file *new)
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

t_file	*new_file_node(char *line, char *path)
{
	t_file	*file;

	file = (t_file *)malloc(sizeof(t_file));
	if (!file)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	file->line = ft_strdup(line);
	file->space = is_space(file->line[0]);
	file->path = ft_strdup(path);
	file->next = NULL;
	return (file);
}

char	**map_file_content(char *str)
{
	char	**file;
	int		fd;

	fd = open_fd(str);
	if (fd == FALSE)
		return (NULL);
	file = (char **)malloc((file_dimensions(fd) + 1) * sizeof(char *));
	if (!file)
	{
		print_error(EMALLOC);
		return (NULL);
	}
	fd = open_fd(str);
	if (fd == FALSE)
		return (NULL);
	file_content(file, fd);
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
		{
			if (file)
				free_file(&file);
			if (content[index])
				array_free(content);
			return (NULL);
		}
		increase_snake(&file, temp);
		index++;
	}
	return (file);
}

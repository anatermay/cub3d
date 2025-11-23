/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:10:16 by aternero          #+#    #+#             */
/*   Updated: 2025/09/10 20:54:53 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	measure_temp(t_file *start)
{
	t_file	*temp;
	int		index;

	temp = start;
	index = 0;
	while (temp)
	{
		index++;
		temp = temp->next;
	}
	return (index);
}

int	array_length(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

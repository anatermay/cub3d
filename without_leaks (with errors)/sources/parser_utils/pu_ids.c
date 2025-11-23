/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_ids.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 13:18:32 by aternero          #+#    #+#             */
/*   Updated: 2025/09/17 19:07:21 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	is_position(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (TRUE);
	return (FALSE);
}

int	is_vert(char *str)
{
	int	index;

	index = 0;
	while (is_space(str[index]) == TRUE)
		index++;
	if (str[index] == 'F')
		return (F_NBR);
	else if (str[index] == 'C')
		return (C_NBR);
	return (FALSE);
}

int	is_coord(char *str)
{
	int	index;

	index = 0;
	while (is_space(str[index]) == TRUE)
		index++;
	if (str[index] == 'N' && str[index + 1] == 'O')
		return (N_NBR);
	else if (str[index] == 'S' && str[index + 1] == 'O')
		return (S_NBR);
	else if (str[index] == 'E' && str[index + 1] == 'A')
		return (E_NBR);
	else if (str[index] == 'W' && str[index + 1] == 'E')
		return (W_NBR);
	return (FALSE);
}

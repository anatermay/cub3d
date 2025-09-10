/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_arraylen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/01 20:10:16 by aternero          #+#    #+#             */
/*   Updated: 2025/09/01 20:12:08 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

int	array_length(char **array)
{
	int	len;

	len = 0;
	while (array[len])
		len++;
	return (len);
}

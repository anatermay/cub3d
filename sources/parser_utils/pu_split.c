/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pu_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aternero <aternero@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 18:40:53 by aternero          #+#    #+#             */
/*   Updated: 2025/09/04 20:18:37 by aternero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/cub3d.h"

static int	count_words(char const *str)
{
	int	index;
	int	words;
	int	inside_word;

	index = 0;
	words = 0;
	inside_word = 0;
	while (str[index])
	{
		if (is_space(str[index]) == FALSE)
		{
			if (!inside_word)
				words++;
			inside_word = 1;
		}
		else
			inside_word = 0;
		index++;
	}
	return (words);
}

static size_t	count_word_size(char const *s, size_t start)
{
	size_t	letters;

	letters = 0;
	while (s[start + letters] && is_space(s[start + letters]) == FALSE)
		letters++;
	return (letters);
}

static char	**splited_split(const char *str, char **array)
{
	int	index;
	int	yndex;
	int	inside_word;

	index = 0;
	yndex = 0;
	inside_word = 0;
	while (str[index])
	{
		if (is_space(str[index]) == FALSE && !inside_word)
		{
			inside_word = 1;
			array[yndex] = ft_substr(str, index, count_word_size(str, index));
			if (!array[yndex])
			{
				array_free(array);
				return (NULL);
			}
			yndex++;
		}
		else if (is_space(str[index]) == TRUE)
			inside_word = 0;
		index++;
	}
	return (array);
}

char	**u_split(char const *str)
{
	char	**array;
	int		word_count;

	if (!str)
		return (NULL);
	word_count = count_words(str);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!array)
		return (NULL);
	if (!splited_split(str, array))
		return (NULL);
	array[word_count] = NULL;
	return (array);
}

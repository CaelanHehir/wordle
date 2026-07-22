/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_verif_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:11:18 by chehir            #+#    #+#             */
/*   Updated: 2026/07/22 17:28:16 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wordle.h"

int	check_valid_word(char *guess)
{
	char	*line;
	int		i;
	int		fd;

	fd = open(VALID_GUESSES_PATH, O_RDONLY);
	i = 0;
	while (i < NB_WORDS)
	{
		line = get_next_line(fd);
		if (!custom_strncmp(guess, line, WORD_SIZE))
		{
			free(line);
			close(fd);
			return (1);
		}
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

int	check_guess(char *str)
{
	int	size;
	int	i;

	if (!str)
		return (-1);
	i = 0;
	size = custom_strlen(str);
	while (i < size)
	{
		if (!custom_isalpha(str[i++]))
			return (custom_printf("Your guess must not contain non-alphabetic characters\n"));
	}
	if (size != WORD_SIZE)
		return (custom_printf("Your guess must be a %d letter word\n", WORD_SIZE));
	if (!check_valid_word(str) && g_difficulty > 1)
		return (custom_printf("'%s' isn't a word.\n", str));
	return (0);
}

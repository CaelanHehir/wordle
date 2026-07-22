/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_setup_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:09:22 by chehir            #+#    #+#             */
/*   Updated: 2026/07/22 17:28:06 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wordle.h"

void	get_difficulty(void)
{
	char	*user_input;
	int		difficulty;

	difficulty = 0;
	system("clear");
	display_title();
	while (!difficulty)
	{
		custom_printf("\nSelect a difficulty:\n1. Easy  		2. Medium		3. Hard\n");
		user_input = get_next_line(0);
		difficulty = custom_atoi(user_input);
		free(user_input);
		if (!difficulty || difficulty < 1 || difficulty > 3)
		{
			system("clear");
			display_title();
			custom_printf("\nInvalid input. Select a difficulty (between 1 and 3).\n");
			difficulty = 0;
		}
	}
	g_difficulty = difficulty;
	g_max_guesses = 6;
	if (g_difficulty == 3)
		g_max_guesses = 4;
}

char	*pick_word(void)
{
	char	*word;
	int		word_number;
	int		fd;
	int		i;

	srand(time(NULL));
	word_number = ((rand() % (NB_WORDS + 1)) + 1);
	i = 0;
	fd = open(WORDS_PATH, O_RDONLY);
	word = NULL;
	while (++i <= word_number)
	{
		if (word)
			free(word);
		word = get_next_line(fd);
	}
	close(fd);
	word[custom_strlen(word) - 1] = '\0';
	return (word);
}

char	**init_guess_tab(void)
{
	char	**guesses;
	int		i;
	int		j;

	guesses = custom_calloc(g_max_guesses, sizeof(char *));
	i = 0;
	while (i < g_max_guesses)
	{
		guesses[i] = custom_calloc(WORD_SIZE + 1, sizeof(char));
		j = 0;
		while (j < WORD_SIZE)
		{
			guesses[i][j] = '_';
			j++;
		}
		i++;
	}
	return (guesses);
}

void	free_guess_tab(char **guesses)
{
	int	i;

	i = 0;
	while (i < g_max_guesses)
		free(guesses[i++]);
	free(guesses);
}

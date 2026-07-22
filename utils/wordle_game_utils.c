/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_game_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:12:42 by chehir            #+#    #+#             */
/*   Updated: 2025/11/23 19:32:38 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wordle.h"

int	check_replay(char *word, char **guess_list)
{
	char	*input;
	int		retry;

	retry = 0;
	while (!retry)
	{
		ft_printf("\nWould you like to play again? (yes/no)\n");
		input = get_next_line(0);
		if (!ft_strncmp(input, "yes", 3))
			retry = 1;
		else if (!ft_strncmp(input, "no", 2))
			retry = -1;
		else
		{
			system("clear");
			display_screen(word, guess_list);
			ft_printf("\nInvalid input. Say yes or no.\n");
		}
		free(input);
	}
	return (retry);
}

char	*get_user_input(char *word, char **guess_list)
{
	char	*input;
	int		valid_input;
	int		len;
	int		i;

	valid_input = 0;
	while (!valid_input)
	{
		input = get_next_line(0);
		input[ft_strlen(input) - 1] = '\0';
		display_screen(word, guess_list);
		if (check_guess(input))
			free(input);
		else
			valid_input = 1;
	}
	i = 0;
	len = ft_strlen(input);
	while (i < len)
	{
		input[i] = ft_tolower(input[i]);
		i++;
	}
	return (input);
}

int	game_loop(char *word, char **guess_list)
{
	char	*current_guess;
	int		line;
	int		column;

	line = 0;
	current_guess = NULL;
	while (line < g_max_guesses)
	{
		current_guess = get_user_input(word, guess_list);
		column = 0;
		while (column < WORD_SIZE)
		{
			guess_list[line][column] = current_guess[column];
			column++;
		}
		free(current_guess);
		display_screen(word, guess_list);
		if (!ft_strncmp(guess_list[line], word, 5))
			return (line + 1);
		line++;
	}
	return (0);
}

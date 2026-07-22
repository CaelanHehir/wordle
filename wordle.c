/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 18:25:34 by chehir            #+#    #+#             */
/*   Updated: 2025/11/23 19:29:38 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/wordle.h"
/* TO DO:
DONT SHOW DUPLICATE LETTERS IN YELLOW */

int	g_difficulty;
int	g_max_guesses;

int	main(void)
{
	char	**guess_list;
	char	*word;
	int		result;

	result = 0;
	while (result != -1)
	{
		word = pick_word();
		get_difficulty();
		guess_list = init_guess_tab();
		display_screen(word, guess_list);
		result = game_loop(word, guess_list);
		if (result == 1)
			ft_printf("\n\033[37;01mCongratulations! You found the word in %d guess!!!\033[00m\n", result);
		else if (result)
			ft_printf("\n\033[37;01mCongratulations! You found the word in %d guesses!!!\033[00m\n", result);
		else
			ft_printf("\n\033[37;01mYou lost! The word was: %s\033[00m\n", word);
		result = check_replay(word, guess_list);
		free(word);
		free_guess_tab(guess_list);
	}
	return (result);
}

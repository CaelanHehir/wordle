/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wordle_display_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 17:08:05 by chehir            #+#    #+#             */
/*   Updated: 2025/11/23 18:09:22 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wordle.h"

int	print_letter(char *word, char *guess, int guess_index)
{
	if (word[guess_index] == guess[guess_index])
		ft_printf("\033[32;01m");
	else if (ft_strchr(word, guess[guess_index]))
		ft_printf("\033[33;01m");
	else
		ft_printf("\033[38;01m");
	ft_printf("%c\033[00m", guess[guess_index]);
	return (1);
}

void	display_title(void)
{
	ft_printf("\033[37;01m__________               __  .__                   __      __                .___.__          \n");
	ft_printf("\\______   \\ ____   _____/  |_|  |   ____   ____   /  \\    /  \\___________  __| _/|  |   ____  \n");
	ft_printf(" |   |   _//  _ \\ /  _ \\   __\\  | _/ __ \\ / ___\\  \\   \\/\\/   /  _ \\_  __ \\/ __ | |  | _/ __ \\ \n");
	ft_printf(" |   |    (  <_> |  <_> )  | |  |_\\  ___// /_/  >  \\        (  <_> )  | \\/ /_/ | |  |_\\  ___/ \n");
	ft_printf(" |_______/ \\____/ \\____/|__| |____/\\____> ___  /    \\__/\\  / \\____/|__|  \\_____| |____/\\____>\n");
	ft_printf("                                        /_____/          \\/\n");
	ft_printf("( ͡° ͜ʖ ͡°) Welcome to Bootleg Wordle!\033[00m\n");
}

void	display_screen(char *word, char **guesses)
{
	int	i;
	int	j;

	system("clear");
	display_title();
	ft_printf("\nGuesses: \n");
	i = 0;
	while (i < g_max_guesses)
	{
		j = 0;
		while (j < 5)
		{
			print_letter(word, guesses[i], j++);
			ft_putchar_fd(' ', 1);
		}
		ft_putchar_fd('\n', 1);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

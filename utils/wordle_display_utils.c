#include "../includes/wordle.h"

int	print_letter(char *word, char *guess, int guess_index)
{
	if (word[guess_index] == guess[guess_index])
		custom_printf("\033[32;01m");
	else if (custom_strchr(word, guess[guess_index]))
		custom_printf("\033[33;01m");
	else
		custom_printf("\033[38;01m");
	custom_printf("%c\033[00m", guess[guess_index]);
	return (1);
}

void	display_title(void)
{
	custom_printf("\033[37;01m__________               __  .__                   __      __                .___.__          \n");
	custom_printf("\\______   \\ ____   _____/  |_|  |   ____   ____   /  \\    /  \\___________  __| _/|  |   ____  \n");
	custom_printf(" |   |   _//  _ \\ /  _ \\   __\\  | _/ __ \\ / ___\\  \\   \\/\\/   /  _ \\_  __ \\/ __ | |  | _/ __ \\ \n");
	custom_printf(" |   |    (  <_> |  <_> )  | |  |_\\  ___// /_/  >  \\        (  <_> )  | \\/ /_/ | |  |_\\  ___/ \n");
	custom_printf(" |_______/ \\____/ \\____/|__| |____/\\____> ___  /    \\__/\\  / \\____/|__|  \\_____| |____/\\____>\n");
	custom_printf("                                        /_____/          \\/\n");
	custom_printf("( ͡° ͜ʖ ͡°) Welcome to Bootleg Wordle!\033[00m\n");
}

void	display_screen(char *word, char **guesses)
{
	int	i;
	int	j;

	system("clear");
	display_title();
	custom_printf("\nGuesses: \n");
	i = 0;
	while (i < g_max_guesses)
	{
		j = 0;
		while (j < 5)
		{
			print_letter(word, guesses[i], j++);
			custom_putchar_fd(' ', 1);
		}
		custom_putchar_fd('\n', 1);
		i++;
	}
	custom_putchar_fd('\n', 1);
}

#ifndef WORDLE_H
# define WORDLE_H

# include "../customlib/customlib.h"
# include <time.h>

# ifndef NB_WORDS
#  define NB_WORDS 2316
# endif

# ifndef WORD_SIZE
#  define WORD_SIZE 5
# endif

# ifndef WORDS_PATH
#  define WORDS_PATH "dictionaries/words.txt"
# endif

# ifndef VALID_GUESSES_PATH
#  define VALID_GUESSES_PATH "dictionaries/words.txt"
# endif

extern int	g_difficulty;
extern int	g_max_guesses;

void	get_difficulty(void);
char	*pick_word(void);
char	**init_guess_tab(void);
void	free_guess_tab(char **guesses);

int		print_letter(char *word, char *guess, int guess_index);
void	display_title(void);
void	display_screen(char *word, char **guesses);

int		check_valid_word(char *guess);
int		check_guess(char *str);

int		check_replay(char *word, char **guess_list);
char	*get_user_input(char *word, char **guess_list);
int		game_loop(char *word, char **guess_list);

#endif

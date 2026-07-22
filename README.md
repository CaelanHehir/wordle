# Bootleg Wordle



## Description
Bootleg Wordle is a simple wordle clone, but more importantly, it is the first personal project I ever worked on! I wrote it in C using as few external functions as possible, which meant using custom implementations of classics such as **printf**, **atoi**, and a few more. Reading user input is also done using a custom function, aptly named '**custom_read_next_line**'.

Working on this was a lot of fun and helped me practice writing slightly more complex programs with multiple moving parts. It laid the groundwork for future, larger-scale projects.


## Instructions

### Build
Simply run the command:
```bash
> make
```

This first builds `customlib.a` (the custom standard-library replacement) inside `customlib/`, then compiles and links the game into a `wordle` executable in the project root.

Other targets:

```bash
> make clean   # remove object files
> make fclean  # remove object files and the executable
> make re      # fclean + all
```

### Run
The executable can be run using
```bash
> ./wordle
```

Run it from the project root, since the game reads its word lists from `dictionaries/words.txt` and `dictionaries/valid_guesses.txt` using paths relative to the working directory.

### How to play
1. Pick a difficulty:
   - **1. Easy / 2. Medium**: 6 guesses.
   - **3. Hard**: only 4 guesses.
   - On Medium and Hard, your guess must also be a real word found in `dictionaries/valid_guesses.txt`.
2. Type a 5-letter guess and hit enter.
3. Each letter is color-coded after every guess:
   - **Green**: right letter, right spot.
   - **Yellow**: letter is in the word, wrong spot.
   - **White**: letter isn't in the word.
4. Guess the word before you run out of tries, then choose whether to play again.


## Details

### Custom functions
Before starting this, I had worked on a school project where I had to create my own C library, so I decided to adapt it slightly to put it to use for this project.

Custom implementations include:
- `custom_printf` - a hand-rolled `printf`
- `custom_atoi` - string-to-int parsing
- `custom_read_next_line` - reads a line of input from a file descriptor (used for reading keyboard input from stdin)
- `custom_strlen`, `custom_strncmp`, `custom_strchr` - string utilities

### Project structure
```
|
├── wordle.c                     # main game loop
├── includes/
│   └── wordle.h                 # shared structs, constants, prototypes
├── utils/
│   ├── wordle_setup_utils.c     # difficulty selection, word picking, guess table setup
│   ├── wordle_verif_utils.c     # guess/word validation
│   ├── wordle_game_utils.c      # game loop, input handling, replay prompt
│   └── wordle_display_utils.c   # title screen and colored guess grid rendering
├── customlib/                   # custom libc-style implementations, built as customlib.a
├── dictionaries/
│   ├── words.txt                # possible answer words
│   └── valid_guesses.txt        # words accepted as valid guesses
├── Makefile
└── README.md
```

### Word lists
- `words.txt` holds the pool of possible secret words (2316 words).
- `valid_guesses.txt` holds every word accepted as a valid guess on Medium/Hard difficulty (14,854 words).

#ifndef CUSTOMLIB_H
# define CUSTOMLIB_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

// Base functions
int		custom_isalpha(int c);
size_t	custom_strlen(const char *s);
char	*custom_strchr(const char *s, int c);
int		custom_strncmp(const char *s1, const char *s2, size_t n);
int		custom_toupper(int c);
int		custom_tolower(int c);
int		custom_atoi(const char *str);
void	custom_bzero(void *s, size_t n);
void	*custom_calloc(size_t nmemb, size_t size);
int		custom_putchar_fd(char c, int fd);
int		custom_putstr_fd(char *s, int fd);
void	custom_putnbr_fd(int n, int fd);

// custom_printf functions
int		custom_display_int(va_list arg);
int		custom_display_unsigned(va_list arg);
int		custom_display_char(va_list arg);
int		custom_display_string(va_list arg);

int		custom_puthex_fd(long unsigned int nb, int caps, int fd);
int		custom_display_hex(va_list arg, int caps);
int		custom_display_address(va_list arg);

int		custom_printf(const char *str, ...);

// get_next_line functions
char	*custom_grow_stache(int fd, char *stache);
char	*custom_get_hair(char *stache);
char	*custom_trim_stache(char *stache);
char	*custom_add_buff(char *s1, char *s2);

char	*custom_read_next_line(int fd);

#endif

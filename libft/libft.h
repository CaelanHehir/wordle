/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:20:23 by chehir            #+#    #+#             */
/*   Updated: 2025/11/23 15:22:35 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
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
int		ft_isalpha(int c);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_putchar_fd(char c, int fd);
int		ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);

// ft_printf functions
int		ft_display_int(va_list arg);
int		ft_display_unsigned(va_list arg);
int		ft_display_char(va_list arg);
int		ft_display_string(va_list arg);

int		ft_puthex_fd(long unsigned int nb, int caps, int fd);
int		ft_display_hex(va_list arg, int caps);
int		ft_display_address(va_list arg);

int		ft_printf(const char *str, ...);

// get_next_line functions
char	*ft_grow_stache(int fd, char *stache);
char	*ft_get_hair(char *stache);
char	*ft_trim_stache(char *stache);
char	*ft_add_buff(char *s1, char *s2);

char	*get_next_line(int fd);

#endif

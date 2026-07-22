#include "customlib.h"

int	custom_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
		custom_putchar_fd(s[i++], fd);
	return (i);
}

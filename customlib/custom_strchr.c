#include "customlib.h"

char	*custom_strchr(const char *s, int c)
{
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && c == '\0')
		return ((char *)&s[i]);
	return (NULL);
}

/*#include <stdio.h>

int	main()
{
	char *str = "Hello";
	char *ptr = custom_strchr(str, 'l');
	if (ptr != NULL)
	{
		printf("%c\n", *ptr);
		printf("%c\n", *(++ptr));
		printf("%c\n", *(++ptr));
	}
}*/

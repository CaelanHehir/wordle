#include "customlib.h"

size_t	custom_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

/*#include <stdio.h>
#include <bsd/string.h>

int     main()
{
        char    *str;

	str = "Hello world";
	printf("%zu\n", custom_strlen(str));
	printf("%zu", strlen(str));
}*/

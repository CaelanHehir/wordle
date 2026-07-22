#include "customlib.h"

int	custom_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (s1[i] && (s1[i] == s2[i]) && (i < n))
		i++;
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}

/*#include <stdio.h>
#include <string.h>
int     main(int argc, char *argv[])
{       
        if (argc > 1)
        {
                printf("%d\n",strncmp(argv[1],argv[2],10));
                printf("%d\n",custom_strncmp(argv[1],argv[2],10));
        }
}*/

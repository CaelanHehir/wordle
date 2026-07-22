/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 11:34:40 by chehir            #+#    #+#             */
/*   Updated: 2025/11/21 19:09:16 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
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
	char *ptr = ft_strchr(str, 'l');
	if (ptr != NULL)
	{
		printf("%c\n", *ptr);
		printf("%c\n", *(++ptr));
		printf("%c\n", *(++ptr));
	}
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 17:05:22 by chehir            #+#    #+#             */
/*   Updated: 2025/11/22 18:43:55 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
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
	printf("%zu\n", ft_strlen(str));
	printf("%zu", strlen(str));
}*/

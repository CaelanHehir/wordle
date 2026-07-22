/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:57:52 by chehir            #+#    #+#             */
/*   Updated: 2025/11/13 12:51:02 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
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
                printf("%d\n",ft_strncmp(argv[1],argv[2],10));
        }
}*/

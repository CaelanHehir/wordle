/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:07:43 by chehir            #+#    #+#             */
/*   Updated: 2025/11/25 15:44:28 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_grow_stache(int fd, char *stache)
{
	char	*buff;
	int		n_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff[BUFFER_SIZE] = '\0';
	if (!buff)
		return (NULL);
	n_bytes = 1;
	while (!ft_strchr(stache, '\n') && n_bytes)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
			return (free(buff), NULL);
		buff[n_bytes] = '\0';
		stache = ft_add_buff(stache, buff);
	}
	free(buff);
	if (!n_bytes && !stache[0])
	{
		free(stache);
		return (NULL);
	}
	return (stache);
}

char	*ft_get_hair(char *stache)
{
	int		i;
	char	*line;

	i = 0;
	while (stache[i] && stache[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (stache[i] && stache[i] != '\n')
	{
		line[i] = stache[i];
		i++;
	}
	if (stache[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*ft_trim_stache(char *stache)
{
	int		i;
	int		j;
	char	*trimmed_stache;

	if (!stache)
		return (NULL);
	if (!ft_strchr(stache, '\n'))
	{
		free(stache);
		return (NULL);
	}
	i = 0;
	while (stache[i] != '\n')
		i++;
	trimmed_stache = ft_calloc(ft_strlen(&stache[i]) + 1, sizeof(char));
	if (!trimmed_stache)
		return (NULL);
	j = 0;
	if (stache[i] == '\n')
		i++;
	while (stache[i])
		trimmed_stache[j++] = stache[i++];
	free(stache);
	return (trimmed_stache);
}

char	*ft_add_buff(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = ft_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	result = ft_calloc((len1 + len2) + 1, sizeof(char));
	if (!result)
		return (NULL);
	i = -1;
	while (++i < len1)
		result[i] = s1[i];
	j = -1;
	while (++j < len2)
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(s1);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*stache[4096];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stache[fd] = ft_grow_stache(fd, stache[fd]);
	if (!stache[fd])
		return (NULL);
	line = ft_get_hair(stache[fd]);
	stache[fd] = ft_trim_stache(stache[fd]);
	return (line);
}

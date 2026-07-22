/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chehir <chehir@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/17 16:07:43 by chehir            #+#    #+#             */
/*   Updated: 2026/07/22 20:29:02 by chehir           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "customlib.h"

char	*custom_grow_stache(int fd, char *stache)
{
	char	*buff;
	int		n_bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	buff[BUFFER_SIZE] = '\0';
	if (!buff)
		return (NULL);
	n_bytes = 1;
	while (!custom_strchr(stache, '\n') && n_bytes)
	{
		n_bytes = read(fd, buff, BUFFER_SIZE);
		if (n_bytes == -1)
			return (free(buff), NULL);
		buff[n_bytes] = '\0';
		stache = custom_add_buff(stache, buff);
	}
	free(buff);
	if (!n_bytes && !stache[0])
	{
		free(stache);
		return (NULL);
	}
	return (stache);
}

char	*custom_get_hair(char *stache)
{
	int		i;
	char	*line;

	i = 0;
	while (stache[i] && stache[i] != '\n')
		i++;
	line = custom_calloc(i + 2, sizeof(char));
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

char	*custom_trim_stache(char *stache)
{
	int		i;
	int		j;
	char	*trimmed_stache;

	if (!stache)
		return (NULL);
	if (!custom_strchr(stache, '\n'))
	{
		free(stache);
		return (NULL);
	}
	i = 0;
	while (stache[i] != '\n')
		i++;
	trimmed_stache = custom_calloc(custom_strlen(&stache[i]) + 1, sizeof(char));
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

char	*custom_add_buff(char *s1, char *s2)
{
	char	*result;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	if (!s1)
		s1 = custom_calloc(1, sizeof(char));
	if (!s1 || !s2)
		return (NULL);
	len1 = custom_strlen(s1);
	len2 = custom_strlen(s2);
	result = custom_calloc((len1 + len2) + 1, sizeof(char));
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
	stache[fd] = custom_grow_stache(fd, stache[fd]);
	if (!stache[fd])
		return (NULL);
	line = custom_get_hair(stache[fd]);
	stache[fd] = custom_trim_stache(stache[fd]);
	return (line);
}
